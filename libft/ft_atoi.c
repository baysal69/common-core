#include "libft.h"
int ft_atoi(char *str)
{
	int i = 0,res = 0;
	int sign = 1;
	if (str[i] >= 0 && str[i] <= 20)
		i++;
	else if (str[i] == '-')
	{
		sign *= (-1);
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - 48;
		i++;
	}
	return res * sign;
}
