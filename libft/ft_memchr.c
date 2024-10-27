#include "libft.h"

/*void *ft_memchr(const void *s, int c, size_t n)
{
	int i = 0;
	int str = (char *)s;
	while ( str[i] != c && i < n)
	{
		i++;
	}
	if ((unsigned char)str[i] == (char )c)
		return (void *)s + i;
	return 0;
}*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char ch;
	size_t	i;

	i = 0;
	str = (unsigned char *)s;
	ch = (unsigned char) c;
	while (str[i] != ch &&i < n)
	{
		i++;
	}
	if (str[i] == ch)
                        return (void *)(s + i);
	return (NULL);
}
/*
int main()
{
	char s[] = "baysal";
	int c = 'a';
	printf("%s\n", (char *)ft_memchr(s,c,6));

}*/
