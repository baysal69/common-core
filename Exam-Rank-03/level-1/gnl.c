#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#define BUFFER_SIZE 42

char *ft_join(char *line,char c)
{
	int i = 0;
	while (line && line[i])
		i++;
	char *s = malloc(i + 2);//protecc
	i = 0;
	while (line && line[i])
	{
		s[i] = line[i];
		i++;
	}
	s[i] = c;
	s[i+1] = '\0';
	free(line);
	return s;
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int pos,i;
	char *line = NULL;
	char c;
	while(1)
	{
		if (pos >= i)
		{
			pos = 0;
			i = read(fd,buffer,BUFFER_SIZE);
			if (i <= 0 )
				break;
		}
		c = buffer[pos];
		pos++;
		line = ft_join(line,c);
		if (c == '\n')
			break;
	}
	return line;
}
int main ()
{
	int fd = open("test.txt", O_CREAT | O_RDONLY);
		printf("%s",get_next_line(fd));
		printf("%s",get_next_line(fd));
		printf("%s",get_next_line(fd));
		printf("%s",get_next_line(fd));
}

	
