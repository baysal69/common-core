/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:24:29 by ysemlali          #+#    #+#             */
/*   Updated: 2024/09/30 15:59:47 by waissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	if (!s1)
		return (NULL);
	str = ft_calloc(ft_strlen(s1) + 1, 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1));
	return (str);
}
