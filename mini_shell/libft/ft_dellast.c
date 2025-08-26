/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:34:26 by waissi            #+#    #+#             */
/*   Updated: 2025/08/25 23:03:59 by waissi           ###   ########.fr       */
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
