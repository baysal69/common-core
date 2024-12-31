/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:09:52 by waissi            #+#    #+#             */
/*   Updated: 2024/12/31 16:48:15 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int  ft_strlen(const char *dest)
{
        size_t  i;

        i = 0;
        while (dest[i])
        {
                i++;
        }
        return (i);
}

char *ft_strcpy(char *dest, const char *src, char c)
{
        int     i;

        i = 0;
        while (src && src[i])
                {
                        dest[i] = src[i];
                        i++;
                }
                dest[i] = c;
                dest[i + 1] = '\0';
	return dest;
}

char *ft_strncpy(char *dst, const char *src, size_t size)
{
        size_t  i;
        //int             l;

        i = 0;
        //l = ft_strlen(src);
        if (!dst || !src)
                return (0);
        if (size == 0)
                return (dst);
        while (src[i] && i < size - 1)
        {
                dst[i] = src[i];
                i++;
        }
        dst[i] = '\0';
        return (dst);
}
