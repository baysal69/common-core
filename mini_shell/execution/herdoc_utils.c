/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:43:00 by waissi            #+#    #+#             */
/*   Updated: 2025/08/25 14:45:14 by waissi           ###   ########.fr       */
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
