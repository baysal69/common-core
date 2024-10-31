#include "libft.h"

char *ft_strdup (const char *s)
{
	char *d;
	int i = 0;
	int l = ft_strlen(s);
	d = malloc((sizeof(char) * l) + 1);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return d;
}
/*
int main()
{
	char *str = "baysal";
	printf("%s\n",ft_strdup(str));
}*/
