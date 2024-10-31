#include "libft.h"

void *ft_memmove (void *dest, const void *src, size_t n)
{
	int i = 0;
	char *s = (unsigned char *)src;
	char *d = (unsigned char *)dest;
	if (!d && !s)
		return NULL;
	if(d > s)
	{
		while (n > 0)
		{
			d[n -1] = s[n - 1];
			n--;
		}
	}
	else
	{
		ft_memcpy(dest,src,n);
	}
	return (void *)dest;
}
/*
int main()
{
        char s[] = "baysal";
        char d[6];
        char f[6];
        printf("%s\n",(char *) ft_memmove(d,s,8));
        printf("%s\n",(char *)    memmove(f,s,8));
}
*/

