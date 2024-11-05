#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
	int i = 0;
	if (!s)
		return NULL;
	while (s[i])
	{
		write(fd,&s[i],1);
		i++;
	}
}
