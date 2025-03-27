/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:14:42 by waissi            #+#    #+#             */
/*   Updated: 2024/12/21 21:15:38 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_putstr(char *s, char c, int f)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s == NULL && f == 0)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	if (f == 1)
		count += write(1, &c, 1);
	else
	{
		while (s[i])
		{
			count += write(1, &s[i], 1);
			i++;
		}
	}
	return (count);
}

int	ft_putnbr(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count += ft_putstr(0, '-', 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
		count += ft_putstr(0, nb + '0', 1);
	return (count);
}

int	ft_puthex(unsigned long n, char c, char f)
{
	int			count;
	const char	*hex;

	count = 0;
	if (f == 1)
		count += write(1, "0x", 2);
	if (c == 'X')
		hex = "0123456789ABCDEF";
	else if (c == 'x')
		hex = "0123456789abcdef";
	else
		return (0);
	if (n >= 16)
	{
		count += ft_puthex(n / 16, c, 0);
		count += ft_puthex(n % 16, c, 0);
	}
	else
		count += ft_putstr(0, hex[n], 1);
	return (count);
}

int	process_format(char specifier, va_list args)
{
	unsigned long	x;

	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *), 0, 0));
	else if (specifier == 'c')
		return (ft_putstr(0, va_arg(args, int), 1));
	else if (specifier == '%')
		return (ft_putstr(0, '%', 1));
	else if (specifier == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_puthex(va_arg(args, unsigned int), specifier, 0));
	else if (specifier == 'p')
	{
		x = va_arg(args, unsigned long);
		if (!x)
			return (write(1, "(nil)", 5));
		return (ft_puthex(x, 'x', 1));
	}
	else
		return (ft_printf("%%%c", specifier));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!s)
		return (-1);
	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != '%')
			count += ft_putstr(0, s[i], 1);
		else
		{
			i++;
			count += process_format(s[i], args);
		}
		i++;
	}
	va_end(args);
	return (count);
}
/*
#include <limits.h>

int	main(void)
{
	int	a;
	int	*aa;
	int	*b;

	a = -1;
	aa = &a;
	b = NULL;
	ft_printf("%d\n",ft_printf(NULL));
	//printf("%d\n",printf("%p\n", -1));
}
int	ft_printf(const char *s, ...)
{
	va_list args;
	va_start(args,s);
	int i = 0;
	int count = 0;
	while(s[i])
	{
		if(s[i] != '%')
			count += ft_putstr(0,s[i],1);
		else if(s[i] == '%')
		{
			if(s[i+1] == 'd' || s[i+1] == 'i')
			{
				count += ft_putnbr(va_arg(args,int));
				i++;
			}
			else if(s[i+1] == 's')
			{
				count+=ft_putstr(va_arg(args,char*),0,0);
				i++;
			}
			else if(s[i+1] == 'c')
			{
				count += ft_putstr(0,va_arg(args,int),1);
				i++;
			}
			else  if(s[i+1] == '%')
			{
				count += ft_putstr(0,'%',1);
				i++;
			}
			else if(s[i+1] == 'u')
			{
				count +=ft_putnbr(va_arg(args, unsigned int));
				i++;
			}
			else if(s[i+1] == 'x' || s[i+1] == 'X')
			{
				if (s[i+1] == 'x')
					count += ft_puthex(va_arg(args,unsigned int),'x',0);
				else
					count += ft_puthex(va_arg(args,unsigned int),'X',0);
				i++;
			}
			else if(s[i+1] == 'p')
			{
				unsigned long x =va_arg(args,unsigned long);
				if (!x)
				{
					count += write(1,"(nil)",5);
				}
				else
					count += ft_puthex(x,'x',1);
				i++;
			}
		}
	i++;
	}
	return (count);
}*/