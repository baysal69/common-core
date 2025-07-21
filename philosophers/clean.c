/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:07:11 by sel-khao          #+#    #+#             */
/*   Updated: 2025/07/17 09:51:15 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_up(t_pstats *p, t_lock *forks)
{
	int	i;
	int	all;

	if (!p || !forks)
		return ;
	all = p[0].in->nphilos;
	pthread_mutex_destroy(&p[0].in->print);
	pthread_mutex_destroy(&p[0].in->death_lock);
	i = 0;
	while (i < all)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	if (p[0].meal_lock)
	{
		i = 0;
		while (i < all)
		{
			pthread_mutex_destroy(&p[0].meal_lock[i]);
			i++;
		}
		free(p[0].meal_lock);
	}
}

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
		if (curr->nmeals > 0 && check_full(p, curr))
			break ;
		if (end_death(p, curr))
			break ;
		ft_usleep(1);
	}
	return (NULL);
}
