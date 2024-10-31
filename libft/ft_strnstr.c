#include "libft.h"

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t    i;
    size_t    j;
	i = 0;
    if (!little[i])
	    return (char*) big;
    while (big[i] && i < len)
    {
        j = 0;
        while (big[i + j] == little[j] && (i + j) < len)
        {
            if (little[j + 1] == '\0')
                return ((char *)big + i);
	    j++;
	}
        i++;
    }
    return (NULL);
}

/*int main()
{
        char *s1 = "baysal raso bzaaaaaaaaf";
        char *s2 = "al";
        printf("%s\n",ft_strnstr(s1,s2,15));
}*/
