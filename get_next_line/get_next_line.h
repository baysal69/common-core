/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:03:17 by waissi            #+#    #+#             */
/*   Updated: 2024/12/31 17:19:32 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

int ft_strlen(const char *str);
char *ft_strcpy(char *dest, const char *src, char c);
char *get_next_line(int fd);
char *ft_strncpy(char *dst, const char *src, size_t size);

#endif
