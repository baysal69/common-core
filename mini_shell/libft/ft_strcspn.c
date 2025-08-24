/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 07:14:08 by ysemlali          #+#    #+#             */
/*   Updated: 2024/08/20 07:14:09 by ysemlali         ###   ########.fr       */
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
