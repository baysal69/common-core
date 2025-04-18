/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:56:01 by waissi            #+#    #+#             */
/*   Updated: 2025/04/18 01:38:02 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_atoi(const char *nptr, t_list **a, t_list **b, char **a1)
{
	long	num;

	int (i), (sign);
	i = 0;
	sign = 1;
	num = 0;
	check_the_sign(nptr, a, b, a1);
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + nptr[i] - '0';
		if (num * sign > 2147483647)
			ft_error("Error\n", a, b, a1);
		if (num * sign < -2147483648)
			ft_error("Error\n", a, b, a1);
		i++;
	}
	return (num * sign);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	int	*r;

	if (!lst || !del)
		return ;
	r = &lst->value;
	(*del)((void *)r);
}
