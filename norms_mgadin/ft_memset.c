/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:34:39 by waissi            #+#    #+#             */
/*   Updated: 2024/11/06 15:34:40 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	char	ch;
	int		i;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (n--)
	{
		str[i] = c;
		i++;
	}
	return ((void *)str);
}