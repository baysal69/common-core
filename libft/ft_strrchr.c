/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:36:32 by waissi            #+#    #+#             */
/*   Updated: 2024/11/06 15:38:37 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, char c)
{
	char	*s;
	int		i;

	s = (char *)str;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (str[i] == c)
			return (s + i);
		i--;
	}
	if (str[i] == c)
		return ((char *)(s + i));
	return (0);
}
