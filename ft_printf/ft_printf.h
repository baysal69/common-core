/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:39:32 by sel-khao          #+#    #+#             */
/*   Updated: 2024/12/08 16:48:07 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h> 

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putnbr(long n);
int	ft_puthex(unsigned int n, char c);
int	ft_putstr(unsigned char *str);
int	ft_putaddr(unsigned long n);

#endif