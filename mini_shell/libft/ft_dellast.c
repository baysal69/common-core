/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:24:28 by ysemlali          #+#    #+#             */
/*   Updated: 2024/09/18 10:24:28 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dellast(t_oken **lst)
{
	t_oken	*current;
	t_oken	*prev;

	if (lst && *lst)
	{
		if (!(*lst)->next)
		{
			ft_lstdelone(*lst);
			*lst = NULL;
			return ;
		}
		current = *lst;
		prev = NULL;
		while (current->next)
		{
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		ft_lstdelone(current);
	}
}
