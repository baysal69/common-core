/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:36:16 by waissi            #+#    #+#             */
/*   Updated: 2024/11/06 15:36:18 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

static int	count_substrings(const char *s, char c)
{
	int	count;
	int	in_substring;

	count = 0;
	in_substring = 0;
	while (*s)
	{
		if (*s != c && !in_substring)
		{
			in_substring = 1;
			count++;
		}
		else if (*s == c)
		{
			in_substring = 0;
		}
		s++;
	}
	return (count);
}

static char	*copy_substring(const char *start, size_t length)
{
	char	*substr;

	substr = (char *)malloc(length + 1);
	if (!substr)
	{
		return (NULL);
	}
	ft_strlcpy(substr, start, length + 1);
	substr[length] = '\0';
	return (substr);
}

char	**ft_split(const char *s, char c)
{
	int			substr_count;
	char		**result;
	int			index;
	const char	*start = NULL;

	if (!s)
		return (NULL);
	substr_count = count_substrings(s, c);
	result = (char **)malloc((substr_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	index = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (start == NULL)
			{
				start = s;
			}
		}
		else
		{
			if (start != NULL)
			{
				result[index] = copy_substring(start, s - start);
				index++;
				start = NULL;
			}
		}
		s++;
	}
	if (start != NULL)
	{
		result[index] = copy_substring(start, s - start);
		index++;
	}
	result[index] = NULL;
	return (result);
}
/*
int	main(void)
{
	char *ch= "baysal,head,is,so,big";
	int i = 0;
	char **chh = ft_split(ch,',');
	while (chh[i]){
	printf("%s\n",chh[i]);
	i++;
	}
}*/
