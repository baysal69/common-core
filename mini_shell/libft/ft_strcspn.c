/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:34:26 by waissi            #+#    #+#             */
/*   Updated: 2025/08/25 23:03:59 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *d)
{
	const char	*d2 = d;
	const char	*s2 = s;

	while (*s)
	{
		while (*d)
		{
			if (*s == *d)
				return (s - s2);
			d++;
		}
		d = d2;
		s++;
	}
	return (s - s2);
}
// return len of the initial segment of s which consists of characters not in d.
// if s is not in d, return the length of s.
