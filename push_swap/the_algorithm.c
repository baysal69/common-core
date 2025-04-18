/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:01:01 by waissi            #+#    #+#             */
/*   Updated: 2025/04/18 01:37:12 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_list **stack_a, t_list **stack_b, int max_bits)
{
	int	size;
	int	i;
	int	j;
	int	value;

	i = 0;
	while (i < max_bits)
	{
		size = ft_lstsize(*stack_a);
		j = 0;
		while (j++ < size && !is_increase(stack_a))
		{
			value = (*stack_a)->rank;
			if ((value >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b))
			pa(stack_a, stack_b);
		i++;
	}
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	max;
	int	max_bits;

	ranking(stack_a);
	max = get_max(stack_a);
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	radix(stack_a, stack_b, max_bits);
}
