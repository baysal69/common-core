#include "libft.h"

char *ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char *ft_strjoin (char const *s1, char const *s2)
{
	char *str1 = (unsigned char *)s1;
	char *str2 = (unsigned char *)s2;
	int ttl = ft_strlen(str1) + ft_strlen(str2);
	char *r = malloc(sizeof(char) * (ttl + 1));
	if (!r)
		return NULL;
	r = ft_strcat(str1,str2);
	return r;
}
/*
int main()
{
	char ch[] = "baysal ";
	char chh[] = "zbo kbir";
	printf("%s",ft_strjoin(ch,chh));
}*/
			
