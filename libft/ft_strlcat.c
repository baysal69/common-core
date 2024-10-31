#include "libft.h"

int ft_strlcat(char *dst, const char *src, size_t s)
{
	int i,j,dlen,slen;
	
	i = 0;
	j = ft_strlen(dst);
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	
	if ((dst == NULL && s == 0) || (dst == NULL || dlen >= (int)s))
	{
		return s + slen;
	}
	while ( src[i] && i < (int)s - dlen - 1) //amjnn a7sn blan katchof wach i 9l mn size d dkchi li 5ask t3mro
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return dlen + slen;
}

/*int main()
{
	char d[17] = "baysal ";
	char s[9] = "zbo kbir";
	printf("%d\n", ft_strlcat(d,s,18));
	printf("%s\n",d);
}*/
