/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:31:56 by waissi            #+#    #+#             */
/*   Updated: 2024/11/06 15:32:26 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	ch;
	size_t	i;

	i = 0;
	str = (unsigned char *)s;
	ch = (unsigned char)c;
	while (str[i] && i < n)
	{
		if (str[i] == ch)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char s[] = "baysal";
	int c = 'a';
	printf("%s\n", (char *)ft_memchr(s,c,6));

}*/
