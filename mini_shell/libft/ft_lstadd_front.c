/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali & waissi <ysemlali & aclackd    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:37:07 by ysemlali          #+#    #+#             */
/*   Updated: 2024/09/02 23:37:37 by ysemlali &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_oken **lst, t_oken *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
