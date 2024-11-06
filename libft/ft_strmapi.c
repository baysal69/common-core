#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	if (!s || !f)
		return NULL;
	int i = 0;
	char *res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return NULL;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return res;
}
/*
int main()
{
	printf("%s",ft_strmapi("baysal",to_upper));
}*/
