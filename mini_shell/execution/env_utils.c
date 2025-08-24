/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:27:46 by aclakhda          #+#    #+#             */
/*   Updated: 2024/09/30 17:09:42 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	env_sizze(t_env *nv)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = nv;
	while (tmp)
	{
		if (tmp->value)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

char	*join_key_value(char *key, char *value)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(key, "=");
	if (!temp)
		return (NULL);
	if (value)
	{
		result = ft_strjoin(temp, value);
		free(temp);
		return (result);
	}
	return (temp);
}

char	**creat_env(t_env *nv)
{
	t_env	*tmp;
	char	**env;
	int		i;

	tmp = nv;
	env = malloc(sizeof(char *) * (env_sizze(nv) + 1));
	if (!env)
		return (NULL);
	i = 0;
	while (tmp)
	{
		if (tmp->value)
		{
			env[i] = join_key_value(tmp->key, tmp->value);
			if (!env[i])
				return (lazy_free(env, i), NULL);
			i++;
		}
		tmp = tmp->next;
	}
	env[i] = NULL;
	return (env);
}

int	env_size(t_env *nv)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = nv;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	lazy_free(char **env, int i)
{
	while (i > 0)
	{
		if (env[i - 1])
			free(env[--i]);
	}
	free(env);
}
