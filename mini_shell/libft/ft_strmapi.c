/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:25:57 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/06 21:14:56 by ysemlali         ###   ########.fr       */
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
