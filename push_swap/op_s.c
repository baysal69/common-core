/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:44:13 by waissi            #+#    #+#             */
/*   Updated: 2025/04/18 01:38:55 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **ab)
{
	int		tmp;
	t_list	*s;

	if (!*ab)
	{
		free(ab);
		return ;
	}
	if (ft_lstsize(*ab) < 2)
		return ;
	s = *ab;
	tmp = s->value;
	s->value = s->next->value;
	s->next->value = tmp;
}

void	sa(t_list **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}
