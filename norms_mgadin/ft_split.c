/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:32:23 by waissi            #+#    #+#             */
/*   Updated: 2024/11/09 16:32:30 by waissi           ###   ########.fr       */
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

static void	free_array(char **arr, size_t i)
{
	if (arr)
	{
		while (i > 0)
		{
			free(arr[i - 1]);
			i--;
		}
		free(arr);
	}
}

char	*split_words(char const *s, char c, char **lst)
{
	size_t	word_len;
	size_t	i;

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
			{
				free_array(lst, i);
				return (NULL);
			}
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
		free(lst);
		return (NULL);
	}
	return (lst);
}
// int main()
// {
// 	char *ch = "baysal,zbo,kbir,bzaaaaf";
// 	int i = 0;
// 	char **chh = ft_split(ch, ',');
// 	if (chh)  // check if splitting was successful
// 	{
// 		while (chh[i])  // print all words
// 		{
// 			printf("%s\n", chh[i]);
// 			i++;
// 		}

// 		// Free memory after using the split array
// 		i = 0;
// 		while (chh[i])  // free all allocated words
// 		{
// 			free(chh[i]);
// 			i++;
// 		}
// 		free(chh);  // free the array itself
// 	}
// 	return (0);
// }
