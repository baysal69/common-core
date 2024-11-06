/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:36:25 by waissi            #+#    #+#             */
/*   Updated: 2024/11/06 15:42:07 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, char c)
{
	int		i;
	int		l;
	char	*s;

	i = 0;
	l = ft_strlen(str);
	s = (char *)str;
	while (s[i])
	{
		if (str[i] == c)
			return (s + i);
		i++;
	}
	if (str[i] == c)
		return (s + i);
	return (0);
}
/*int main()
{
	printf("%s",ft_strchr("baysal",' '));
}*/
