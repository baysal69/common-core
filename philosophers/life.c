/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:41:04 by waissi            #+#    #+#             */
/*   Updated: 2025/08/07 16:48:35 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*is_one(t_pstats *p, size_t tdie)
{
	pthread_mutex_lock(p->lfork);
	put_message("has taken a fork\n", p);
	ft_usleep(tdie);
	pthread_mutex_unlock(p->lfork);
	return (NULL);
}

void	life_cycle(t_pstats *p)
{
	t_content	*curr;

	curr = p->in;
	while (is_alive(curr))
	{
		if (eating(p))
			break ;
		sleeping(p);
		if (!is_alive(curr))
			break ;
		thinking(p);
	}
}

void	*routine(void *arg)
{
	t_pstats	*p;
	int			nphilos;
	size_t		tdie;
	size_t		teat;

	p = (t_pstats *)arg;
	philo_born(p, &nphilos, &tdie, &teat);
	if (nphilos == 1)
		return (is_one(p, tdie));
	if (p->id % 2 == 0)
		ft_usleep(teat);
	life_cycle(p);
	return (NULL);
}

int	end_death(t_pstats *p, t_content *curr)
{
	int		i;
	size_t	time;
	int		nphilos;
	size_t	tdie;

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
			if (curr->death == 0)
				put_dead(curr, p[i].id);
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
