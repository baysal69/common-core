#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char ch;
	size_t	i;

	i = 0;
	str = (unsigned char *)s;
	ch = (unsigned char) c;
	while (str[i] && i < n)
	{
		if (str[i] == ch)
			return (void*)(str + i);
		i++;
	}
	return (NULL);
}
/*
int main()
{
	char s[] = "baysal";
	int c = 'a';
	printf("%s\n", (char *)ft_memchr(s,c,6));

}*/
