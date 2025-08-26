/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:34:26 by waissi            #+#    #+#             */
/*   Updated: 2025/08/25 23:03:59 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join(char *line, char c)
{
	int		i;
	char	*s;

	i = 0;
	while (line && line[i])
		i++;
	s = malloc(i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		s[i] = line[i];
		i++;
	}
	s[i] = c;
	s[i + 1] = '\0';
	free(line);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	pos;
	static int	i;
	char		*line;
	char		c;

	line = NULL;
	while (1)
	{
		if (pos >= i)
		{
			pos = 0;
			i = read(fd, buffer, BUFFER_SIZE);
			if (i <= 0)
				break ;
		}
		c = buffer[pos];
		pos++;
		line = ft_join(line, c);
		if (c == '\n')
			break ;
	}
	return (line);
}
