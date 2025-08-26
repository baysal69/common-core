/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:34:26 by waissi            #+#    #+#             */
/*   Updated: 2025/08/25 23:03:59 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	toggle(unsigned int i, char c)
{
	(void)i;
	if (c == -99 || c == -100 || c == -36)
		return ('$');
	return (c);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	char	*d;
	int		i;

	i = 0;
	d = (char *)s;
	if (!s || !f)
		return (0);
	result = ft_calloc(ft_strlen(s) + 1, 1);
	while (*s)
	{
		result[i++] = f(s - d, *s);
		s++;
	}
	return (result);
}
