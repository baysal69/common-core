/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali & waissi <ysemlali & aclackd    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:40:15 by ysemlali          #+#    #+#             */
/*   Updated: 2024/09/02 23:39:32 by ysemlali &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_oken **lst)
{
	t_oken	*current;
	t_oken	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		if (current->value)
			free(current->value);
		free(current);
		current = next;
	}
	*lst = NULL;
}
