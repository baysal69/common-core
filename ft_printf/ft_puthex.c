/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:08:18 by sel-khao          #+#    #+#             */
/*   Updated: 2024/12/08 17:17:06 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char c)
{
	const char			*hex;
	const char			*h = "0123456789abcdef";
	const char			*hh = "0123456789ABCDEF";
	int					len;

	if (c == 'x')
		hex = h;
	else if (c == 'X')
		hex = hh;
	else
		return (0);
	len = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n >= 16)
		len += ft_puthex(n / 16, c);
	len += ft_putchar(hex[n % 16]);
	return (len);
}
/* int main(void)
{
	ft_puthex(255, 'x');    // expected: "ff"
	ft_putchar('\n');
	return (0);
} */