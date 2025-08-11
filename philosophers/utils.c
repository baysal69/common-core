/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:35:36 by waissi            #+#    #+#             */
/*   Updated: 2025/07/14 09:35:36 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long long ms)
{
	long long	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(50);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign *= (-1);
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - 48;
		i++;
	}
	return (res * sign);
}

void	put_dead(t_content *curr, int i)
{
	size_t	time;

	pthread_mutex_lock(&curr->death_lock);
	curr->death = 1;
	pthread_mutex_unlock(&curr->death_lock);
	pthread_mutex_lock(&curr->print);
	time = get_time() - curr->start;
	printf("%lu %i died\n", time, i);
	pthread_mutex_unlock(&curr->print);
}

void	put_message(char *s, t_pstats *p)
{
	size_t	time;

	pthread_mutex_lock(&p->in->print);
	pthread_mutex_lock(&p->in->death_lock);
	if (p->in->death == 1)
	{
		pthread_mutex_unlock(&p->in->death_lock);
		pthread_mutex_unlock(&p->in->print);
		return ;
	}
	time = (get_time() - p->in->start);
	printf("%lu %d %s", time, p->id, s);
	pthread_mutex_unlock(&p->in->death_lock);
	pthread_mutex_unlock(&p->in->print);
}

int	ft_parse(t_pstats **p, pthread_mutex_t **forks, t_content curr)
{
	int	i;

	*p = malloc(sizeof(t_pstats) * curr.nphilos);
	*forks = malloc(sizeof(t_lock) * curr.nphilos);
	i = 0;
	while (i < curr.nphilos)
	{
		if (pthread_mutex_init(&(*forks)[i], NULL) != 0)
			error(4);
		i++;
	}
	return (0);
}
