#include "libft.h"
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i = 0;
	while (s1[i] && s2[i] && i < (int)n)
	{
		if ( s1[i] == s2[i] )
			i++;
		else 
			return s1[i] - s2[i];
	}
	return 0;
}
