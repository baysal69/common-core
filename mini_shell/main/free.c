/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahab <adahab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:37:17 by adahab            #+#    #+#             */
/*   Updated: 2025/08/25 10:37:17 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_av(char ***av)
{
	int	i;

	i = 0;
	if (*av != NULL)
	{
		while ((*av)[i])
		{
			free((*av)[i]);
			i++;
		}
	}
	free(*av);
	*av = NULL;
}

void	cleanup_env(t_env *env)
{
	t_env	*current;
	t_env	*next;

	current = env;
	while (current)
	{
		next = current->next;
		free(current->key);
		free(current->value);
		free(current);
		current = next;
	}
	env = NULL;
}

void	free_all(t_shell *shell)
{
	free(shell->s);
	ft_lstclear(&shell->token);
	cleanup_env(shell->nv);
	free(shell);
}
