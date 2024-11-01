#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			++j;
		}
		++i;
	}
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char *str = (char *)s1;
	char *s = (char *)set;
	return ft_strstr(str,s);
}
int main()
{
	char ch[] = "-- baysal";
	char chh[] = "baysal";
	printf("%s",ft_strtrim(ch,chh));
}
