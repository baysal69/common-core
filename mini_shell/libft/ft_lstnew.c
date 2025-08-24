/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:00:56 by ysemlali          #+#    #+#             */
/*   Updated: 2024/09/10 23:21:22 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_oken	*ft_lnew(char *value, int type, int index, t_oken *prev)
{
	t_oken	*result;

	result = ft_calloc(1, sizeof(t_oken));
	if (!result)
		return (NULL);
	result->value = value;
	result->type = type;
	result->read = 0;
	result->fd = 0;
	result->index = index;
	result->quote = 0;
	result->next = NULL;
	result->prev = prev;
	return (result);
}
