/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:33:26 by ysemlali          #+#    #+#             */
/*   Updated: 2024/09/18 10:33:26 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpy(char *d, char *s)
{
	if (d == NULL || s == NULL)
		return (NULL);
	ft_memcpy(d, s, ft_strlen(s));
	return (d);
}
