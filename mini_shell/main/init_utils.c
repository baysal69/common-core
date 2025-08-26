/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahab <adahab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 23:05:17 by adahab            #+#    #+#             */
/*   Updated: 2025/08/25 23:05:19 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*value(char *s, int type)
{
	if (type == 0)
		return (ft_strndup(s, ft_strchr(s, '=') - s));
	else if (type == 1)
		return (ft_strdup(ft_strchr(s, '=') + 1));
	else if (type == 2)
		return (ft_itoa(ft_atoi(ft_strchr(s, '=') + 1) + 1));
	return (NULL);
}

void	init_env(t_shell **shell, char **nv)
{
	int		i;
	t_env	*tmp;

	i = 0;
	(*shell)->nv = ft_calloc(1, sizeof(t_env));
	if ((*shell)->nv)
	{
		tmp = (*shell)->nv;
		while (nv[i])
		{
			(*shell)->nv->key = value(nv[i], 0);
			if (ft_strcmp((*shell)->nv->key, "SHLVL") == 0)
				(*shell)->nv->value = value(nv[i], 2);
			else
				(*shell)->nv->value = value(nv[i], 1);
			if (nv[i + 1])
			{
				(*shell)->nv->next = ft_calloc(1, sizeof(t_env));
				(*shell)->nv = (*shell)->nv->next;
			}
			i++;
		}
		(*shell)->nv->next = NULL;
		(*shell)->nv = tmp;
	}
}
