/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:10:15 by waissi            #+#    #+#             */
/*   Updated: 2025/04/18 01:37:56 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**free_arr(char **s, int i)
{
	while (i > 0)
	{
		i--;
		free(s[i]);
	}
	free(s);
	return (0);
}

static int	contw(char const *s, char c)
{
	int	i;
	int	co;
	int	f;

	i = 0;
	co = 0;
	f = 0;
	while (s[i])
	{
		if (s[i] != c && f == 0)
		{
			co++;
			f = 1;
		}
		else if (s[i] == c)
			f = 0;
		i++;
	}
	return (co);
}

static char	*cpy(char *arr, char const *s, int j, int len )
{
	int	i;

	i = 0;
	while (len > 0)
		arr[i++] = s[j - len--];
	arr[i] = '\0';
	return (arr);
}

static char	**spliter(char const *s, char c, char **arr, int num)
{
	int	arri;
	int	i;
	int	len;

	arri = 0;
	i = 0;
	len = 0;
	while (arri < num)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			len++;
		}
		arr[arri] = (char *)malloc(len + 1);
		if (!arr[arri])
			return (free_arr(arr, arri));
		cpy(arr[arri], s, i, len);
		len = 0;
		arri++;
	}
	arr[arri] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	num;

	if (!s)
		return (NULL);
	num = contw(s, c);
	arr = (char **)malloc((num + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = spliter(s, c, arr, num);
	return (arr);
}
