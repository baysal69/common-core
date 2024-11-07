#include "libft.h"

static size_t   ft_countword(char const *s, char c)
{
    size_t  count;

    if (!*s)
        return (0);
    count = 0;
    while (*s)
    {
        while (*s == c)
            s++;
        if (*s)
            count++;
        while (*s != c && *s)
            s++;
    }
    return (count);
}

static void    free_array(char **arr, int i)
{
    if (arr)
    {
    while (i >= 0)
    {
        free(arr[i]);
        i--;   
    }
    free(arr);
    }
}

char    **ft_split(char const *s, char c)
{
    char    **lst;
    size_t  word_len;
    int     i;

    lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
    if (!s || !lst)
        return (0);
    i = 0;
    while (*s)
    {
        while (*s == c && *s)
            s++;
        if (*s)
        {
            if (!ft_strchr(s, c))
                word_len = ft_strlen(s);
            else
                word_len = ft_strchr(s, c) - s;
            lst[i] = ft_substr(s, 0, word_len);
            if (!lst[i])
            {
                free_array(lst, i);
                return NULL;
            }
            i++;
            s += word_len;
        }
    }
    lst[i] = NULL;
    return (lst);
}

// int main()
// {
// 	char *ch= "baysal,zbo,kbir,bzaaaaf";
// 	int i = 0;
// 	char **chh = ft_split(ch,',');
// 	while (chh[i]){
// 	printf("%s\n",chh[i]);
// 	i++;
// 	}
//     while ( i < 0)
//     {
//         free(chh[i]);
//         i--;
//     }
//     free(chh);

// }
