#include "libft.h"

static int int_len(long n)
{
	int len = 0;
	if ( n == 0)
		return 0;
	else if ( n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return len;
}

char *ft_itoa(int n)
{
	int i = int_len(n);
	char *res = (char*)ft_calloc((i + 1), sizeof(char));
	long nb = n;
	if (n < 0 )
		nb *= -1;
	res[i] = '\0';
	i--;
	while( i >= 0)
	{
		res[i] = (nb % 10) + 48;
		nb /= 10;
		i--;
	}
	if (n < 0)
		res[0] = '-';
	return res;
}
/*
int main()
{
	printf("%s", ft_itoa(421337));
}
*/

