/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali & waissi <ysemlali & aclackd    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:38:12 by ysemlali          #+#    #+#             */
/*   Updated: 2024/09/02 23:44:22 by ysemlali &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_oken **token, t_oken *new)
{
	t_oken	*last;

	if (!token || !new)
		return ;
	if (*token == NULL)
	{
		*token = new;
		return ;
	}
	last = *token;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}
