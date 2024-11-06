/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:22:50 by waissi            #+#    #+#             */
/*   Updated: 2024/11/06 15:23:59 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		*str = 0;
		str++;
	}
}
/*
int	main(void)
{
	int i = 0;
	int c[1] = {999999};
	ft_bzero(c,2);
	//while (i < 1)
	//{
	printf("%d\n",c[i]);
	//i++;
	//}
}*/
