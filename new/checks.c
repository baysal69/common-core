/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:02:45 by sel-khao          #+#    #+#             */
/*   Updated: 2025/07/14 09:02:45 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_full(t_pstats *p, t_content *curr)
{
    int i;
    int count;
	int nphilos;

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
        pthread_mutex_unlock(&curr->death_lock);
        return (1);
    }
    pthread_mutex_unlock(&curr->death_lock);
    return (0);
}

int	check_args(int ac, char **av)
{
	int		i;
	long	nb;

	i = 1;
	nb = 0;
	if (ac < 5 || ac > 6)
		error(1);
	while (i < ac)
	{
		if (!checkarg(av[i]))
			error(2);
		i++;
	}
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (!nb || nb < INT_MIN || nb > INT_MAX)
			error(2);
		i++;
	}
	return (1);
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

void	error(int code)
{
	if (code == 1)
	{
		printf(RED "invalid arguments\n" RESET);
		exit(1);
	}
	else if (code == 2)
	{
		printf (RED "invalid arguments content\n"RESET);
		exit(1);
	}
	else if (code == 3)
	{
		printf(RED "invalid number of meals\n" RESET);
		exit(1);
	}
	else if (code == 4)
	{
		printf(RED "mutex initialization failed\n" RESET);
		exit(1);
	}
	else if (code == 5)
	{
		printf(RED "threads creation failed\n" RESET);
		exit(1);
	}
}

