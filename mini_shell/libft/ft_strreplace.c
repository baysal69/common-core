/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:33:42 by ysemlali          #+#    #+#             */
/*   Updated: 2024/09/18 10:33:42 by ysemlali         ###   ########.fr       */
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
