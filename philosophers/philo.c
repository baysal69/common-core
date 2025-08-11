/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:04:34 by waissi            #+#    #+#             */
/*   Updated: 2025/07/17 09:00:06 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	pthread_mutex_t	*forks;
	t_pstats		*p;
	t_content		curr;

	forks = NULL;
	p = NULL;
	if (error(check_args(ac, av)) < 0)
		return (-1);
	init_content(&curr, ac, av);
	if (error(ft_parse(&p, &forks, curr)) < 0)
		return (-1);
	if (error(init_pstats(p, &curr, forks)) < 0)
		return (-1);
	clean_up(p, forks);
	free(p);
	free(forks);
	return (0);
}
