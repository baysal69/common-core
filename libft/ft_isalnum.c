#include "LIBFT_H"

int ft_isalphanum(int c)
{
	if ( (c >= 48 && c <= 57) || (c >= 65 && c <= 90) || ( c >= 97 && c <= 122 ) )
		return 1;
	else
		return 0;
}
