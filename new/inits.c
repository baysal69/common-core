/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:04:20 by sel-khao          #+#    #+#             */
/*   Updated: 2025/07/14 09:04:20 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_content(t_content *it, int ac, char **av)
{
	int	i;

	i = 0;
	it->nphilos = ft_atoi(av[1]);
	it->tdie = ft_atoi(av[2]);
	it->teat = ft_atoi(av[3]);
	it->tsleep = ft_atoi(av[4]);
	if (it->nphilos % 2 == 1)
		it->tthink = (it->teat * 2) - it->tsleep;
	else
		it->tthink = it->teat - it->tsleep;
	if (it->tthink <= 0)
		it->tthink = 1;
	it->full = 0;
	it->death = 0;
	it->start = get_time();
	if (ac == 5)
		it->nmeals = -1;
	else if (ac == 6)
		it->nmeals = ft_atoi(av[5]);
	while (i < it->nphilos)
		it->counter[i++] = 0;
}

void	init_pstats(t_pstats *p, t_content *curr, t_lock *forks)
{
	int		i;
	t_lock	*meal_locks;

	i = -1;
	meal_locks = malloc(sizeof(t_lock) * curr->nphilos);
	while (++i < curr->nphilos)
	{
		if (pthread_mutex_init(&meal_locks[i], NULL) != 0)
			error(4);
	}
	i = -1;
	while (++i < curr->nphilos)
	{
		p[i].id = i + 1;
		p[i].lastmeal = curr->start;
		p[i].full = 0;
		p[i].eating = 0;
		p[i].turn = 0;
		p[i].in = curr;
		p[i].lfork = &forks[i];
		p[i].rfork = &forks[(i + 1) % curr->nphilos];
		p[i].meal_lock = &meal_locks[i];
	}
	init_thrds(curr, p);
}

void	init_thrds(t_content *curr, t_pstats *p)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&curr->print, NULL) != 0)
		error (4);
	if (pthread_mutex_init(&curr->death_lock, NULL) != 0)
		error (4);
	curr->start = get_time();
	while (++i < curr->nphilos)
		p[i].lastmeal = curr->start;
	i = -1;
	if (pthread_create(&curr->monitor, NULL, monitoring, p) != 0)
		error(5);
	i = -1;
	while (++i < curr->nphilos)
	{
		if (pthread_create(&p[i].philo, NULL, routine, &p[i]) != 0)
			error (5);
	}
	i = -1;
	while (++i < curr->nphilos)
		pthread_join(p[i].philo, NULL);
	pthread_join(curr->monitor, NULL);
}

long long	get_time(void)
{
	t_timeval	tv;
	long long	timelaps;

	gettimeofday(&tv, NULL);
	timelaps = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (timelaps);
}
