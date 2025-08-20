#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define BUFFER_SIZE 42 

char *ft_join(char *line,char c)
{
        int i = 0;
        while (line && line[i])
                i++;
        char *s = malloc(i + 2);
	if (!s)
		return NULL;
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
                                return NULL;
                }
                c = buffer[pos];
                pos++;
                line = ft_join(line,c);
		if (!line)
			return NULL;
                if (c == '\0' || !i)
                        break;
        }
	return line;
}

ft_strncmp(char *s1, char *s2,int len)
{
	int i = 0;
	while (s1[i] && s2[i] && i <= len)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return 1;
	}
	return 0;
}
int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0, len = strlen(av[1]), j = 0;
		char *input = get_next_line(0);
		if (!input)
		{
			perror("Error");
			return 1;
		}
		while (input[i])
		{
			if (ft_strncmp(&input[i],av[1],len))
				printf("%c",input[i++]);
			else
			{
				j = 0;
				while (j < len)
				{
					printf("*");
					j++;
				}
				i+= len;
			}
		}
	}
	else
		return 1;
}
