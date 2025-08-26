/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:34:26 by waissi            #+#    #+#             */
/*   Updated: 2025/08/25 23:03:59 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_charneg(char *arr, size_t index)
{
	if (!arr)
		return ;
	arr[index] = -arr[index];
}

char	*ft_strreplace(char *s, int replace, int c)
{
	char	*tmp;

	if (s == NULL)
		return (NULL);
	tmp = s;
	while (*tmp)
	{
		if (*tmp == replace)
			*tmp = c;
		tmp++;
	}
	return (s);
}
