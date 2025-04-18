/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:21:31 by waissi            #+#    #+#             */
/*   Updated: 2025/04/18 01:37:37 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_the_sign(const char *str, t_list **a, t_list **b, char **a1)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			if (str[i + 1] == '-' || str[i + 1] == '+')
				ft_error("Error\n", a, b, a1);
		}
		else if (str[i] == '-' || str[i] == '+')
		{
			if (!ft_isdigit(str[i + 1]))
				ft_error("Error\n", a, b, a1);
		}
		i++;
	}
}
