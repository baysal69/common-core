/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_the_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:57:20 by waissi            #+#    #+#             */
/*   Updated: 2025/04/18 01:36:17 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	on_top_b(t_list **a, t_list **b, t_list *node)
{
	int	len;

	len = ft_lstsize(*b);
	if (!b || !node)
		ft_error("Error\n", a, b, NULL);
	positioning(b);
	while (*b != node)
	{
		if (node->position <= len / 2)
			rb(b);
		else
			rrb(b);
	}
}

void	on_top_a(t_list **a, t_list **b, t_list *node)
{
	int	len;

	len = ft_lstsize(*a);
	if (!a || !node)
		ft_error("Error\n", a, b, NULL);
	positioning(a);
	while (*a != node)
	{
		if (node->position <= len / 2)
			ra(a);
		else
			rra(a);
	}
}
