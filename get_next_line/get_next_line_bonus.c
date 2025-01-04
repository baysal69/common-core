/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 01:59:16 by waissi            #+#    #+#             */
/*   Updated: 2025/01/04 16:56:04 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	read_buffer(int fd, char *buffer, int *pos, int *i)
{
	*i = read(fd, buffer, BUFFER_SIZE);
	*pos = 0;
	return (*i > 0);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE];
	static int	i[1024];
	static int	pos[1024];
	char		*line;
	char		c;

	line = NULL;
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	while (1)
	{
		if (pos[fd] >= i[fd]
			&& !read_buffer(fd, buffer[fd], &pos[fd], &i[fd]))
			return (line);
		c = buffer[fd][pos[fd]++];
		line = ft_join(line, c);
		if (!line || c == '\n')
			break ;
	}
	return (line);
}
