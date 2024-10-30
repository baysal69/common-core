#include "libft.h"

int ft_isascii(int c)
{
	if (c >= 0 && <= 127)
		return 1;
	else
		return 0;
}
