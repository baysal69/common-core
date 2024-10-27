#include "libft.h"
#include <string.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	int i = 0;
	char *s = (unsigned char *)src;
	char *d = (unsigned char *)dest;

	while( s[i] && i < n - 1)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (void *)d;
}
int main()
{
	char s[] = "baysal";
	char d[6];
	printf("%s\n",(char *)ft_memcpy(d,s,6));
	printf("%s\n", (char *)memcpy(d,s,6));
}
