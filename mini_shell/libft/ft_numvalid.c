/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numvalid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:34:26 by waissi            #+#    #+#             */
/*   Updated: 2025/08/25 23:03:59 by waissi           ###   ########.fr       */
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
