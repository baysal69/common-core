/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:02:45 by waissi            #+#    #+#             */
/*   Updated: 2025/07/14 09:02:45 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_full(t_pstats *p, t_content *curr)
{
	int	i;
	int	count;
	int	nphilos;

	pthread_mutex_lock(&curr->death_lock);
	count = 0;
	i = 0;
	nphilos = curr->nphilos;
	pthread_mutex_unlock(&curr->death_lock);
	while (i < nphilos)
	{
		pthread_mutex_lock(p[i].meal_lock);
		if (p[i].full == 1)
			count++;
		pthread_mutex_unlock(p[i].meal_lock);
		i++;
	}
	pthread_mutex_lock(&curr->death_lock);
	curr->full = count;
	if (curr->full >= nphilos)
	{
		curr->death = 1;
		return (pthread_mutex_unlock(&curr->death_lock), 1);
	}
	return (pthread_mutex_unlock(&curr->death_lock), 0);
}

int	check_args(int ac, char **av)
{
	int		i;
	long	nb;

	i = 1;
	nb = 0;
	if (ac < 5 || ac > 6)
		return (1);
	while (i < ac)
	{
		if (!checkarg(av[i]))
			return (2);
		i++;
	}
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (!nb || nb < INT_MIN || nb > INT_MAX)
			return (2);
		i++;
	}
	return (0);
}

int	checkarg(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	error(int code)
{
	if (code == 1)
	{
		return (printf(RED "invalid arguments\n" RESET), -1);
		return (-1);
	}
	else if (code == 2)
	{
		printf(RED "invalid arguments content\n" RESET);
		return (-1);
	}
	else if (code == 3)
	{
		printf(RED "invalid number of meals\n" RESET);
		return (-1);
	}
	else if (code == 4)
	{
		printf(RED "mutex initialization failed\n" RESET);
		return (-1);
	}
	else if (code == 5)
		return (printf(RED "threads creation failed\n" RESET), -1);
	return (0);
}
