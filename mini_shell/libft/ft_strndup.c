/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:34:26 by waissi            #+#    #+#             */
/*   Updated: 2025/08/25 23:03:59 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*new;

	i = 0;
	while (s[i] && i < n)
		i++;
	new = ft_calloc(i + 1, sizeof(char));
	if (new)
	{
		i = 0;
		while (*s && n--)
			new[i++] = *s++;
	}
	return (new);
}
