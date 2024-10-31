#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	int i = 0;
	char *s = (unsigned char *)src;
	char *d = (unsigned char *)dest;
	if(!dest && !src)
		return NULL;
	if(dest == src)
		return (void *)dest;
	while( i < n)
	{
		d[i] = s[i];
		i++;
	}
	//d[i] = '\0';
	return (void *)d;
} 
/*
int main()
{
	char s[] = "baysal";
	char d[6];
	char f[6];
	printf("%s\n",(char *) ft_memcpy(d,s,8));
	printf("%s\n",(char *)    memcpy(f,s,8));
}*/
