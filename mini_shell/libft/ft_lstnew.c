/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:34:26 by waissi            #+#    #+#             */
/*   Updated: 2025/08/25 23:03:59 by waissi           ###   ########.fr       */
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
