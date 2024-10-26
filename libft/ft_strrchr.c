#include "stdio.h"

char *ft_strrchr(char *str, char c)
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	while (str[i] != c)
	{
		i--;
	}
	return str + i;
}
