#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	char *str = (char *)s1;
	char *s = (char *)set;
	char *r;
	int start = 0;
	int end = ft_strlen(str) - 1;
	if (!s1 || !set)
		return NULL;
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup(s1 + end + 1));
	while (ft_strchr(set ,s1[end] && end >= 0));
		end --;
	r = malloc(end - start + 2);
	return str + start;

}
int main()
{
	char ch[] = "-- baysal";
	char chh[] = "--";
	printf("%s",ft_strtrim(ch,chh));
}
