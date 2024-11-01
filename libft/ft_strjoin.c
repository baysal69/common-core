#include "libft.h"

char *ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

void    ft_strcpy(char *dest, const char *src)
{
        int     i;

        i = 0;
        while (src[i] != '\0')
        {
                dest[i] = src[i];
                i++;
        }
        dest[i] = '\0';
}

char *ft_strjoin (char const *s1, char const *s2)
{
	char *str1 = (unsigned char *)s1;
	char *str2 = (unsigned char *)s2;
	if (!s1 && !s2)
		return NULL;
	else if (!s1)
		return ft_strdup(s2);
	else if (!s2)
		return ft_strdup(s1);
	int ttl = ft_strlen(str1) + ft_strlen(str2);
	char *r = malloc(sizeof(char) * (ttl + 1));
	if (!r)
		return NULL;
	ft_strcpy(r,s1);
	ft_strcat(r,str2);
	return (char *)r;
}
/*
int main()
{
	char ch[] = "baysal ";
	char chh[] = "zbo kbir";
	printf("%s",ft_strjoin(ch,chh));
}
*/
