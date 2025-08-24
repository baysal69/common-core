/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:19:38 by ysemlali          #+#    #+#             */
/*   Updated: 2024/08/15 06:16:52 by ysemlali         ###   ########.fr       */
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
