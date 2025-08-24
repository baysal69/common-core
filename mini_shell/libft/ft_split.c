/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali & aclakhda <ysemlali & aclackd    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 06:58:31 by ysemlali          #+#    #+#             */
/*   Updated: 2024/08/29 12:05:48 by ysemlali &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	freeall(char **result, size_t count)
{
	size_t	i;

	if (result[count] == NULL)
	{
		i = 0;
		while (i < count)
			free(result[i++]);
		free(result);
		return (0);
	}
	return (1);
}

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

size_t	ft_count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			i += ft_wordlen(&s[i], c);
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			result[j] = ft_substr(s, i, ft_wordlen(&s[i], c));
			if (freeall(result, j) != 1)
				return (NULL);
			j++;
			i += ft_wordlen(&s[i], c);
		}
		else
			i++;
	}
	return (result[j] = NULL, result);
}
