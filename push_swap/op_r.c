/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:04:17 by waissi            #+#    #+#             */
/*   Updated: 2025/04/18 01:38:42 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotation(t_list **ab)
{
	t_list	*s;
	t_list	*last;

	if (!ab || !*ab || ft_lstsize(*ab) < 2)
		return ;
	s = *ab;
	*ab = s->next;
	s->next = NULL;
	last = ft_lstlast(*ab);
	last->next = s;
}

void	ra(t_list **a)
{
	rotation(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rotation(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotation(a);
	rotation(b);
	write(1, "rr\n", 3);
}
