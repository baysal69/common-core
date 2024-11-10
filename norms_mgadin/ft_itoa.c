/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:31:39 by waissi            #+#    #+#             */
/*   Updated: 2024/11/06 18:14:41 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*res;
	long	nb;

	i = int_len(n);
	res = (char *)malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	nb = n;
	if (n < 0)
		nb *= -1;
	res[i] = '\0';
	i--;
	if (n == 0)
		res[i] = '0';
	while (i >= 0)
	{
		res[i] = (nb % 10) + 48;
		nb /= 10;
		i--;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
/*
int	main(void)
{
	printf("%s", ft_itoa(2147483647));
}*/
