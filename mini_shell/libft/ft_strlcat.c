/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:24:35 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/06 21:14:56 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	p;
	size_t	d_len;

	i = 0;
	if (src == NULL)
		return (0);
	if (!dest && size == 0)
		return (ft_strlen(src));
	d_len = ft_strlen(dest);
	if (size <= d_len)
		return (size + ft_strlen(src));
	p = size - d_len - 1;
	while (src[i] != '\0' && i < p)
	{
		dest[i + d_len] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (d_len + ft_strlen(src));
}
