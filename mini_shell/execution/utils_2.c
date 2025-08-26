/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:56:19 by waissi            #+#    #+#             */
/*   Updated: 2025/08/25 21:22:00 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	z;

	z = 0;
	while (src[z])
	{
		dest[z] = src[z];
		z++;
	}
	dest[z] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	isnt_red(int type, int i)
{
	if (i && type == HEREDOC)
		return (0);
	if (type == OUTPUT || type == INPUT || type == APPEND)
		return (0);
	return (1);
}

void	ft_free_token(t_oken *token)
{
	t_oken	*tmp;

	while (token)
	{
		tmp = token->next;
		free(token->value);
		free(token);
		token = tmp;
	}
}

void	found_key(t_shell *shell, char *key)
{
	t_env	*tmp;
	t_env	*prev;

	prev = NULL;
	tmp = shell->nv;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			if (prev)
				prev->next = tmp->next;
			else
				shell->nv = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
