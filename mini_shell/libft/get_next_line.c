/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:08:09 by ysemlali          #+#    #+#             */
/*   Updated: 2023/12/07 18:32:53 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ln_exists(char *buf)
{
	size_t	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_remainder(char *line)
{
	char	*result;

	if (!ln_exists(line))
		return (free(line), NULL);
	result = cutstr(line, ln_index(line) + 1, ft_strlen(line));
	free(line);
	return (result);
}

char	*ft_read_buffer(int fd, char *line)
{
	char	*buffer;
	ssize_t	lines_read;

	buffer = malloc(B_S + 1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	lines_read = 1;
	while (lines_read > 0 && !ln_exists(buffer))
	{
		lines_read = read(fd, buffer, B_S);
		if (lines_read < 0)
			return (free(buffer), free(line), NULL);
		buffer[lines_read] = '\0';
		line = join_string(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*output;

	if (fd < 0)
		return (NULL);
	line = ft_read_buffer(fd, line);
	if (!line || !line[0])
		return (free(line), NULL);
	output = cutstr(line, 0, ln_index(line) + 1);
	line = ft_get_remainder(line);
	return (output);
}
