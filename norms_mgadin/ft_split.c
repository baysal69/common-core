/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 03:44:36 by waissi            #+#    #+#             */
/*   Updated: 2024/11/09 00:25:06 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

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

static void	free_array(char **arr, int i)
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

char	*split_words(char const *s, char c, char **lst)
{
	size_t	word_len;
	int		i;
	
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			word_len = 0;
			while (s[word_len] && s[word_len] != c)
				word_len++;
			lst[i] = ft_substr(s, 0, word_len);
			if (!lst[i])
				return (NULL);
			i++;
			s += word_len;
		}
	}
	lst[i] = NULL;
	return ((char *)(lst));
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_countword(s, c);
	lst = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	if (split_words(s, c, lst) == NULL)
	{
		free_array(lst,ft_countword(s,c));
		free(lst);
		return (NULL);
	}
	return (lst);
}

 int main()
 {
 	char *ch= "baysal,zbo,kbir,bzaaaaf";
 	int i = 0;
 	char **chh = ft_split(ch,',');
 	while (chh[i]){
 	printf("%s\n",chh[i]);
 	i++;
 	}
     while ( i < 0)
     {
         free(chh[i]);
         i--;
     }
     free(chh);
}
