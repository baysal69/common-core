/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 02:01:38 by waissi            #+#    #+#             */
/*   Updated: 2025/01/03 02:01:39 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *dest)
{
	size_t	i;

	i = 0;
	while (dest[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, const char *src, char c)
{
	int	i;

	i = 0;
	while (src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = c;
	dest[i + 1] = '\0';
	return (dest);
}

char	*ft_join(char *line, char c)
{
	int		i;
	char	*str;

	i = 0;
	if (line)
		i = ft_strlen(line);
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
	{
		free(line);
		return (NULL);
	}
	ft_strcpy(str, line, c);
	free(line);
	return (str);
}
