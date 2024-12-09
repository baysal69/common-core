/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:58:20 by sel-khao          #+#    #+#             */
/*   Updated: 2024/12/08 17:10:48 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nil_check(unsigned long n)
{
	if (!n)
	{
		write (1, "(nil)", 5);
		return (0);
	}
	else
		write(1, "0x", 2);
	return (1);
}

int	ft_putaddr(unsigned long num)
{
	int		len;
	char	addr[16];
	int		i;

	if (nil_check(num) != 1)
		return (5);
	len = 0;
	if (num == 0)
	{
		len += ft_putchar('0');
		return (len);
	}
	while (num > 0)
	{
		addr[len] = "0123456789abcdef"[num % 16];
		num /= 16;
		len++;
	}
	addr[len] = '\0';
	i = len - 1;
	while (i >= 0)
		write(1, &addr[i--], 1);
	return (len + 2);
}

/*#include <limits.h>
int main()
{
	char *num = "0";
   //	ft_putaddr(ULONG_MAX);
	ft_putaddr(0);
	printf("\n %p %p \n"0, 0);
	ft_putaddr(num);
	write(1, "\n", 1);
	return 0;
} */