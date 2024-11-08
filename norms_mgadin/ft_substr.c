/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:46:50 by waissi            #+#    #+#             */
/*   Updated: 2024/11/06 15:46:51 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	char	*str;

	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	if (ft_strlen(str) <= start)
	{
		result = malloc(1);
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (len > ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	result = malloc(sizeof(char) * (len) + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, &str[start], len + 1);
	return (result);
}
