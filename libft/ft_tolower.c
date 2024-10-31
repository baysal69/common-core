#include "libft.h"

char ft_tolower( int c) {
	if(c >= 'A' && c <= 'Z')
	{
		return c + 32; 
	}
		return c;
}
