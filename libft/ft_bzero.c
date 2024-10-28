#include "libft.h"
void ft_bzero (void *s, size_t n)
{
	char *str = (unsigned char *)s;
		while (n--)
		{
			*str = 0;
			str++;
		}
}
/*
int main()
{
	int i = 0;
	int c[1] = {999999};
	ft_bzero(c,2);
	//while (i < 1)
	//{
	printf("%d\n",c[i]);
	//i++;
	//}
}*/
