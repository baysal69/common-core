/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:04:34 by sel-khao          #+#    #+#             */
/*   Updated: 2025/07/16 22:01:11 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	*monitoring(void *arg)
{
    t_pstats	*p;
    t_content	*curr;

    p = (t_pstats *)arg;
	pthread_mutex_lock(p->meal_lock);
    curr = p->in;
	pthread_mutex_unlock(p->meal_lock);
    ft_usleep(1);
    while (is_alive(curr))
    {
        // pthread_mutex_lock(p->meal_lock);
        if (curr->nmeals > 0 && check_full(p, curr))
            break ;
        if (end_death(p, curr))
            break ;
        // pthread_mutex_unlock(p->meal_lock);
        ft_usleep(1);
    }
    return	(NULL);
}


int	main(int ac, char **av)
{
	pthread_mutex_t *forks;
	t_pstats	*p;
	t_content curr;
	int i;

	check_args(ac, av);
	if (ac >= 2)
	{
		init_content(&curr, ac, av);
		p = malloc(sizeof(t_pstats) * curr.nphilos);
		forks = malloc(sizeof(t_lock) * curr.nphilos);
		i = 0;
		while (i < curr.nphilos)
		{
			if (pthread_mutex_init(&forks[i], NULL) != 0)
				error(4);
			i++;
		}
		init_pstats(p, &curr, forks);
		clean_up(p, forks);
		free(p);
		free(forks);
	}
	return (0);
}
