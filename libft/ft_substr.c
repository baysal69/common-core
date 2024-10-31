#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *result;
	result = malloc(1);
	if (!s)
		return NULL;
	if(ft_strlen(s) <= start)
	{
		result = malloc(1);
		if (!result)
			return NULL;
		result[0] = '\0';
		return result;
	}
	if ( len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	result = malloc(sizeof(char) * (len +1));
	if (!result)
		return NULL;
	ft_strlcpy(result, &result[start], len + 1);
	return result;
}

