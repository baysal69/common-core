/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:04:34 by sel-khao          #+#    #+#             */
/*   Updated: 2025/07/17 09:00:06 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	pthread_mutex_t	*forks;
	t_pstats		*p;
	t_content		curr;
	int				i;

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
