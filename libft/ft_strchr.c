#include "libft.h"

char *ft_strchr(const char *str, char c)
{
	int i = 0,l = ft_strlen(str);
	char *s = (char *)str;
	while (s[i])
	{
		if (str[i] == c)
			return s + i;
		i++;
	
	}
	if (str[i] == c)
		return s + i;
	return 0;
}
/*int main()
{
	printf("%s",ft_strchr("baysal",' '));
}*/
