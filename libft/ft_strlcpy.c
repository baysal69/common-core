#include "libft.h"

int ft_strlcpy(char *dst, const char *src, size_t size)
{
	int i = 0,l = 0;
	if (!dst || !str)
		return 0;
	while (src[l])
	{
		l++;
	}
	if (l == 0)
		return l;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return l;
}
