/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:34:03 by waissi            #+#    #+#             */
/*   Updated: 2024/11/06 15:34:13 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return ((void *)dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *)d);
}

// int	main(void)
// {
// 	char s[] = "baysal";
// 	char d[6];
// 	char f[6];
// 	printf("%s",(char *) ft_memcpy(NULL,s,8));
// 	//printf("%s",(char *)    memcpy(NULL,s,8));
// }