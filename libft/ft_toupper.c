#include "LIBFT_H"

char ft_toupper (char c)
{
	if ( c >= 97 && c <= 126)
	{
		return (c - 32);
	}
	else
	return 0;
}	
