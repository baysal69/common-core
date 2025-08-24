/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:05:28 by ysemlali          #+#    #+#             */
/*   Updated: 2024/10/14 23:05:31 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	metachar(char c)
{
	return (ft_strchr("|<>", c) != NULL);
}

char	*get_env(t_env *nv, char *key)
{
	t_env	*tmp;

	tmp = nv;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

int	getcount(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (ft_isspace(*s))
		{
			count++;
			while (*s && ft_isspace(*s))
				s++;
		}
		if (*s)
		{
			count++;
			while (*s && !ft_isspace(*s))
				s++;
		}
	}
	return (count);
}
