/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:43:00 by aclakhda          #+#    #+#             */
/*   Updated: 2024/12/03 14:45:14 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_herdoc(t_shell *shell, t_herdoc *herdoc)
{
	int	i;

	i = 0;
	if (herdoc)
	{
		while (herdoc->line[i])
		{
			free(herdoc->line[i]);
			i++;
		}
		free(herdoc->line);
		free(herdoc);
		unlinker(shell);
		herdoc = NULL;
	}
}

void	handle_exec_error(t_var *var, t_shell *shell, int i)
{
	free_av1(var->av);
	if (i)
		lazy_free(var->env, env_size(shell->nv));
	free_all_shell(shell, 0);
	perror("execve");
	if (var->cmd_path)
		free(var->cmd_path);
	lazy_free(var->env, env_size(shell->nv));
	exit(g_exit_status);
}

int	set(t_oken *token)
{
	t_oken	*tmp;
	int		i;

	i = 0;
	tmp = token;
	while (tmp)
	{
		if (tmp->type == HEREDOC)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	already_exist(char *key, t_shell *shell)
{
	t_env	*tmp;

	tmp = shell->nv;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
