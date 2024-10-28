#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
	char *str = (unsigned char *)s;
	char ch = (unsigned char) c;
	int i = 0;
	while (n--)
	{
		str[i] = c;
		i++;
	}
}
