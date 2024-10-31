#include "libft.h"
//#include <string.h>
int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int i = 0;
	unsigned char *str1 = (unsigned char *)s1;
	unsigned char *str2 = (unsigned char *)s2;
	while ( i < n)
	{
		if (str1[i] != str2[i])
			return str1[i] - str2[i];
		i++;
	}
	return 0;
}
/*
int main()
{
	char s1[] = "baysal";
	char s2[] = "baysql";
	printf("%d\n",ft_memcmp(s1,s2,2));
	printf("%d\n",memcmp(s1,s2,2));
}*/
