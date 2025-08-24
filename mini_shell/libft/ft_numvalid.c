/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numvalid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali & waissi <ysemlali & aclackd    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:33:45 by ysemlali &        #+#    #+#             */
/*   Updated: 2024/08/24 23:12:25 by ysemlali &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numvalid(const char *s)
{
	const char	*tmp;

	if (!s || !*s)
		return (0);
	tmp = s;
	if (*tmp == '-' || *tmp == '+')
		tmp++;
	while (*tmp && ft_isdigit(*tmp))
		tmp++;
	return (!*tmp);
}
