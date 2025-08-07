/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:14:32 by sel-khao          #+#    #+#             */
/*   Updated: 2025/08/07 16:48:07 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_pstats *p)
{
	put_message("is thinking...\n", p);
	if (p->in->nphilos % 2 != 0)
		ft_usleep(p->in->teat);
	ft_usleep(5);
}

void	sleeping(t_pstats *p)
{
	put_message("is sleeping\n", p);
	ft_usleep(p->in->tsleep);
}

int	eating(t_pstats *p)
{
	int	stop;

	stop = 0;
	f_lock(p);
	meal_update(p);
	put_message("started eating\n", p);
	ft_usleep(p->in->teat);
	pthread_mutex_lock(p->meal_lock);
	p->eating = 0;
	pthread_mutex_unlock(p->meal_lock);
	if (p->in->nmeals > 0 && p->in->counter[p->id - 1] >= p->in->nmeals)
	{
		pthread_mutex_lock(p->meal_lock);
		p->full = 1;
		pthread_mutex_unlock(p->meal_lock);
		stop = 1;
	}
	pthread_mutex_unlock(p->rfork);
	pthread_mutex_unlock(p->lfork);
	return (stop);
}

void	f_lock(t_pstats *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(p->lfork);
		put_message("has taken a fork\n", p);
		pthread_mutex_lock(p->rfork);
		put_message("has taken a fork\n", p);
	}
	else
	{
		pthread_mutex_lock(p->rfork);
		put_message("has taken a fork\n", p);
		pthread_mutex_lock(p->lfork);
		put_message("has taken a fork\n", p);
	}
}

void	meal_update(t_pstats *p)
{
	pthread_mutex_lock(p->meal_lock);
	p->lastmeal = get_time();
	p->eating = 1;
	p->in->counter[p->id -1]++;
	pthread_mutex_unlock(p->meal_lock);
}
