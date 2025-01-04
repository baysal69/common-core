/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 01:48:45 by waissi            #+#    #+#             */
/*   Updated: 2025/01/04 17:21:16 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_buffer(int fd, char *buffer, int *pos, ssize_t *i)
{
	*i = read(fd, buffer, BUFFER_SIZE);
	*pos = 0;
	if (*i > 0)
		return (*i);
	return (0);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	i;
	static int		pos;
	char			*line;
	char			c;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	while (1)
	{
		if (pos >= i && !read_buffer(fd, buffer, &pos, &i))
			return (line);
		c = buffer[pos++];
		line = ft_join(line, c);
		if (!line || c == '\n')
			break ;
	}
	return (line);
}
