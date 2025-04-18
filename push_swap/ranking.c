/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:13:25 by waissi            #+#    #+#             */
/*   Updated: 2025/04/18 01:36:52 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ranking(t_list **a)
{
	int		rank;
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *a;
	while (tmp)
	{
		tmp2 = *a;
		rank = 1;
		while (tmp2)
		{
			if (tmp->value > tmp2->value)
				rank++;
			tmp2 = tmp2->next;
		}
		tmp->rank = rank;
		tmp = tmp->next;
	}
}

void	positioning(t_list **a)
{
	int		position;
	t_list	*tmp;

	position = 1;
	tmp = *a;
	while (tmp)
	{
		tmp->position = position;
		position++;
		tmp = tmp->next;
	}
}
