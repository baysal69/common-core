/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:15:59 by waissi            #+#    #+#             */
/*   Updated: 2025/01/02 04:25:28 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	
	ft_strcpy(str,line,c);
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	i = 0, pos = 0;
	char		*line;
	char		c;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return NULL;
	while (1)
	{
		if (pos >= i)
		{
			pos = 0;
			i = read(fd, buffer, BUFFER_SIZE);
			if (i <= 0)
			{
				if (line)
					return (line);
				free(line);
				return (NULL);
			}
		}
		c = buffer[pos++];
		line = ft_join(line, c);
		if (!line)
			return NULL;
		if (c == '\n')
			break ;
	}
	return (line);
}
/*
 int main() {
     int fd = open("a.txt", O_RDONLY);
     char *line = NULL;

     // Read each line from the file and print it
     line = get_next_line(fd);
         printf("%s", line);
         free(line);
             line = get_next_line(fd);
         printf("%s", line);
         free(line);

     // Close the file
     close(fd);
     return (0);
}*/
