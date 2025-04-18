/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:51:02 by waissi            #+#    #+#             */
/*   Updated: 2025/04/18 01:37:05 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_increase(t_list **ab)
{
	t_list	*tmp;

	tmp = *ab;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_tree(t_list **ab)
{
	t_list	*last;
	t_list	*s;

	s = *ab;
	last = ft_lstlast(*ab);
	if (s->next->value > s->value && s->next->value > last->value)
	{
		rra(ab);
		if (!is_increase(ab))
			sa(ab);
	}
	else if (s->value > s->next->value && s->value > last->value)
	{
		ra(ab);
		if (!is_increase(ab))
			sa(ab);
	}
	else
	{
		if (!is_increase(ab))
			sa(ab);
	}
}

t_list	*get_the_one(t_list *a, int i)
{
	t_list	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->rank == i)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int	get_max(t_list **stack)
{
	t_list	*head;
	int		max;

	head = *stack;
	max = 0;
	while (head != NULL)
	{
		if (head->rank > max)
			max = head->rank;
		head = head->next;
	}
	return (max);
}

void	sort_20orless(t_list **a, t_list **b)
{
	int		i;
	t_list	*small;

	i = 1;
	ranking(a);
	while (ft_lstsize(*a) > 3)
	{
		small = get_the_one(*a, i);
		if (!small)
			ft_error("Error\n", a, b, NULL);
		else
		{
			on_top_a(a, b, small);
			pb(a, b);
			i++;
		}
	}
	sort_tree(a);
	while (*b)
		pa(a, b);
}
