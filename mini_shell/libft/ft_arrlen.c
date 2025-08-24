/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali & aclakhda <ysemlali & aclackd    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:34:26 by ysemlali &        #+#    #+#             */
/*   Updated: 2024/10/14 23:03:59 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_arrlen(char **s)
{
	char	**tmp;

	tmp = s;
	if (s && *s)
	{
		while (*tmp)
			tmp++;
		return (tmp - s);
	}
	return (0);
}
