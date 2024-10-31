#include "libft.h"

int ft_strlcpy(char *dst, const char *src, size_t size)
{
	int i = 0,l = ft_strlen(src);
	if (!dst || !src)
		return 0;
	if (size == 0)
		return l;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return l;
}
