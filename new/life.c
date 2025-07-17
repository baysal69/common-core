/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:41:04 by sel-khao          #+#    #+#             */
/*   Updated: 2025/07/16 22:00:59 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	*routine(void *arg)
// {
// 	t_pstats	*p;
// 	t_content	*curr;

// 	p = (t_pstats *)arg;
// 	curr = p->in;
	
// 	if (curr->nphilos == 1)
// 	{
// 		pthread_mutex_lock(p->lfork);
// 		put_message("has taken a fork\n", p);
// 		ft_usleep(curr->tdie);
// 		pthread_mutex_unlock(p->lfork);
// 		return (NULL);
// 	}
// 	if (p->id % 2 == 0)
// 		ft_usleep(curr->teat * 0.9);
// 	while (is_alive(curr))
// 	{
// 		if (eating(p))
// 			break ;
// 		sleeping(p);
// 		if (!is_alive(curr))
// 			break ;
// 		thinking(p);
// 	}
// 	return (NULL);
// }
void	*routine(void *arg)
{
    t_pstats	*p;
    t_content	*curr;
    int nphilos;
    size_t tdie;

    p = (t_pstats *)arg;
    curr = p->in;
    
    // Read shared data under lock protection
    pthread_mutex_lock(&curr->death_lock);
    nphilos = curr->nphilos;
    tdie = curr->tdie;
    pthread_mutex_unlock(&curr->death_lock);
    
    if (nphilos == 1)
    {
        pthread_mutex_lock(p->lfork);
        put_message("has taken a fork\n", p);
        ft_usleep(tdie);
        pthread_mutex_unlock(p->lfork);
        return (NULL);
    }
    if (p->id % 2 == 0)
    {
        pthread_mutex_lock(&curr->death_lock);
        size_t teat = curr->teat;
        pthread_mutex_unlock(&curr->death_lock);
        ft_usleep(teat * 0.9);
    }
    while (is_alive(curr))
    {
        if (eating(p))
            break ;
        sleeping(p);
        if (!is_alive(curr))
            break ;
        thinking(p);
    }
    return (NULL);
}

// int	end_death(t_pstats *p, t_content *curr)
// {
// 	int		i;
// 	size_t	time;
// 	int nphilos;

// 	pthread_mutex_lock(&curr->death_lock);
// 	nphilos = curr->nphilos;
// 	i = 0;
// 	time = get_time();
// 	pthread_mutex_unlock(&curr->death_lock);
// 	while (i < nphilos)
// 	{
// 		pthread_mutex_lock(p[i].meal_lock);
// 		if (!p[i].eating && (time - p[i].lastmeal) >= curr->tdie)
// 		{
// 			pthread_mutex_unlock(p[i].meal_lock);
// 			pthread_mutex_lock(&curr->death_lock);
// 			if (curr->death == 0)
// 			{
// 				curr->death = 1;
// 				put_dead(curr, p[i].id);
// 			}
// 			pthread_mutex_unlock(&curr->death_lock);
// 			return (1);
// 		}
// 		pthread_mutex_unlock(p[i].meal_lock);
// 		i++;
// 	}
// 	return (0);
// }
int	end_death(t_pstats *p, t_content *curr)
{
    int		i;
    size_t	time;
    int		nphilos;
    size_t	tdie;

    // Read shared data under lock protection
    pthread_mutex_lock(&curr->death_lock);
    nphilos = curr->nphilos;
    tdie = curr->tdie;
    pthread_mutex_unlock(&curr->death_lock);
    
    i = 0;
    time = get_time();
    while (i < nphilos)
    {
        pthread_mutex_lock(p[i].meal_lock);
        if (!p[i].eating && (time - p[i].lastmeal) >= tdie)
        {
			// pthread_mutex_lock(&curr->death_lock);
            if (curr->death == 0)
            {
				curr->death = 1;
                put_dead(curr, p[i].id);
            }
            // pthread_mutex_unlock(&curr->death_lock);
			pthread_mutex_unlock(p[i].meal_lock);
            return (1);
        }
        pthread_mutex_unlock(p[i].meal_lock);
        i++;
    }
    return (0);
}


int	is_alive(t_content *curr)
{
	pthread_mutex_lock(&curr->death_lock);
	if (curr->death == 1)
	{
		pthread_mutex_unlock(&curr->death_lock);
		return (0);
	}
	pthread_mutex_unlock(&curr->death_lock);
	return (1);
}

