/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:07:11 by sel-khao          #+#    #+#             */
/*   Updated: 2025/07/16 21:27:45 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void clean_up(t_pstats *p, t_lock *forks)
{
	int i;
	int all;

	if (!p || !forks)
		return;
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

