#include "libft.h"

char *ft_strchr(char *str, char c)
{
	int i,l = 0;
	while (str[l])
	{
	l++;
	}
	while (str[i] != c)
	{
		i++;
	}
	if (i == (l))
		return NULL;
	return str + i;
}
/*int main()
{
	printf("%s",ft_strchr("baysal",' '));
}*/
