/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:41:47 by ysemlali          #+#    #+#             */
/*   Updated: 2024/06/26 20:09:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	output;

	i = 0;
	sign = 1;
	output = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (output > (LONG_MAX - (str[i] - '0')) / 10)
			return (LONG_MAX);
		output *= 10;
		output += str[i] - '0';
		i++;
	}
	return (output * sign);
}
// converts the initial portion of the string
// pointed to by str to int representation.
