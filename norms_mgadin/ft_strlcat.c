/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:44:04 by waissi            #+#    #+#             */
/*   Updated: 2024/11/06 19:05:31 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, size_t s)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	i = 0;
	j = ft_strlen(dst);
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if ((dst == NULL && s == 0) || (dst == NULL || dlen >= s))
	{
		return (s + slen);
	}
	while (src[i] && i < s - dlen - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dlen + slen);
}

/*int main()
{
	char d[17] = "baysal ";
	char s[9] = "zbo kbir";
	printf("%d\n", ft_strlcat(d,s,18));
	printf("%s\n",d);
}*/
