#include "LIBFT_H"

int ft_strlen(char *str)
{
	int l,i = 0;
	while(str[i])
	{
		l++;
		i++;
	}
	return l;
}
