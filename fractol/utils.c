/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:29:51 by waissi            #+#    #+#             */
/*   Updated: 2025/04/13 04:29:21 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strlen(const char *s)
{
	size_t			i;

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

/*double	ft_atof(const char *str)
{
	double	res;
	double	res2;
	char	*c;
	int		len;
	int sign;

	c = (char *)str;
	sign = 1;
	while (*c && *c != '.')
		c++;
	if (*c == '-')
    	{
       		 sign *= -1;
       		 c++;
    	}
   	else if (*c == '+')
    	{
     	  	 c++;
    	}
	res = (double)ft_atoi(c);
	if (*c == '.')
	{
		c++;
		res2 = (double)ft_atoi(c);
		len = ft_strlen(c);
		while (len--)
			res2 /= 10;
		while (*c)
		{
			if (!(*c >= '0' && *c <= '9'))
				exit(0);
			c++;
		}
	}
	else
		return (sign * res);
	return (sign * (res + res2));
}*/
double ft_atof(const char *str) {
    float result = 0.0, fraction = 0.0;
    int sign = 1, divisor = 1;

    // Skip leading whitespace
    while (*str <= 32)
	    str++;
    if (*str == '-' || *str == '+')
    {
	    if (*str == '-')
	    	sign = *-1
	    str++;
    }

    // Process integer part
    while (*str >= '0' && *str <= '9') result = result * 10 + (*str++ - '0');
    if (*str == '.') {
        str++;
        while (*str >= '0' && *str <= '9') {
            fraction = fraction * 10 + (*str++ - '0');
            divisor *= 10;
        }
    }
    return sign * (result + fraction / divisor);
}
