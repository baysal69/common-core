#include "libft.h"

char *ft_strrchr(const char *str, char c)
{
	char *s = (char *)str;
	int i = ft_strlen(s);
	while (i > 0)
	{
		if (str[i] == c)
			return s + i;
		i--;
	}
	if (str[i] == c )
		return s + i;
	return 0;
}
