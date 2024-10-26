#include "stdio.h"
#include <string.h>

int ft_strlcat (char *dest, const char *src, size_t size)
{
	int i = 0, l = 0, l2 = 0;;
	while(src[l])
		l++;
	while(dst[l2])
		l2++;
	
	if (l <= size)
		return size + l;
	while (src[i] && i < size -1)
	{
		dest[l] = src[i];
		l++;
		i++;
	}
	dest[l] = '\0';
	return l+l2;
}
