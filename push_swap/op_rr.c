/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:53:39 by waissi            #+#    #+#             */
/*   Updated: 2025/04/18 01:38:48 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotation(t_list **ab)
{
	t_list	*last;
	t_list	*s;

	if (!ab || !*ab || ft_lstsize(*ab) < 2)
		return ;
	s = *ab;
	while (s->next->next)
		s = s->next;
	last = s->next;
	s->next = NULL;
	last->next = *ab;
	*ab = last;
}

void	rra(t_list **a)
{
	reverse_rotation(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	reverse_rotation(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotation(a);
	reverse_rotation(b);
	write(1, "rrr\n", 4);
}
