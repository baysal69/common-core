#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	char *str = (char *)s1;
	char *s = (char *)set;
	char *r;
	int start = 0;
	int end = ft_strlen(str);
	if (!s1 || !s2)
		return NULL;

}
int main()
{
	char ch[] = "-- baysal";
	char chh[] = "baysal";
	printf("%s",ft_strtrim(ch,chh));
}
