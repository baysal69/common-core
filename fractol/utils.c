/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:29:51 by waissi            #+#    #+#             */
/*   Updated: 2025/04/13 23:55:52 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if ((nptr[i] < '0' || nptr[i] > '9') && nptr[i] != '-')
		exit(0);
	if (nptr[i] == '-')
		sign = sign * -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + nptr[i] - '0';
		i++;
		if (num * sign > 2147483647 || num * sign < -2147483648)
			exit(0);
	}
	return (num * sign);
}

static int	check_negative(char *c)
{
	if (*c == '-' || *c == '+')
	{
		if (*c == '-')
			return (-1);
		return (1);
	}
	return (1);
}

double	ft_atof(const char *str)
{
	double	res;
	double	res2;
	char	*c;
	int		len;
	int		sign;

	c = (char *)str;
	res = (double)ft_atoi(c);
	sign = check_negative(c);
	while (*c > 32 && *c != '.')
		c++;
	if (*c == '.')
	{
		c++;
		res2 = (double)ft_atoi(c);
		len = ft_strlen(c);
		while (len--)
			res2 /= 10;
		if (res >= 0)
			return ((res + res2) * sign);
		else
			return ((res - res2) * sign);
	}
	else
		return (res * sign);
}
