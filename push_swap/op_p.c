/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:29:59 by waissi            #+#    #+#             */
/*   Updated: 2025/04/18 01:38:33 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(b, tmp);
}

void	pb(t_list **a, t_list **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}
