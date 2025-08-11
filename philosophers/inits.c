/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:04:20 by waissi            #+#    #+#             */
/*   Updated: 2025/08/10 19:17:08 by waissi           ###   ########.fr       */
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

int	init_pstats(t_pstats *p, t_content *curr, t_lock *forks)
{
	int		i;
	t_lock	*meal_locks;

	i = -1;
	meal_locks = malloc(sizeof(t_lock) * curr->nphilos);
	while (++i < curr->nphilos)
	{
		if (pthread_mutex_init(&meal_locks[i], NULL) != 0)
			return (4);
	}
	i = -1;
	while (++i < curr->nphilos)
	{
		p[i].id = i + 1;
		p[i].lastmeal = curr->start;
		p[i].full = 0;
		p[i].eating = 0;
		p[i].in = curr;
		p[i].lfork = &forks[i];
		p[i].rfork = &forks[(i + 1) % curr->nphilos];
		p[i].meal_lock = &meal_locks[i];
	}
	return (init_thrds(curr, p));
}

int	init_thrds(t_content *curr, t_pstats *p)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&curr->print, NULL) != 0)
		return (4);
	if (pthread_mutex_init(&curr->death_lock, NULL) != 0)
		return (4);
	curr->start = get_time();
	while (++i < curr->nphilos)
		p[i].lastmeal = curr->start;
	i = -1;
	if (pthread_create(&curr->monitor, NULL, monitoring, p) != 0)
		return (5);
	i = -1;
	while (++i < curr->nphilos)
	{
		if (pthread_create(&p[i].philo, NULL, routine, &p[i]) != 0)
			return (5);
	}
	i = -1;
	while (++i < curr->nphilos)
		pthread_join(p[i].philo, NULL);
	pthread_join(curr->monitor, NULL);
	return (0);
}

void	philo_born(t_pstats *p, int *nphilos, size_t *tdie, size_t *teat)
{
	t_content	*curr;

	curr = p->in;
	pthread_mutex_lock(&curr->death_lock);
	*nphilos = curr->nphilos;
	*tdie = curr->tdie;
	*teat = curr->teat;
	pthread_mutex_unlock(&curr->death_lock);
}

long long	get_time(void)
{
	t_timeval	tv;
	long long	timelaps;

	gettimeofday(&tv, NULL);
	timelaps = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (timelaps);
}
