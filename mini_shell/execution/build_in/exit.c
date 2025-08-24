/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:55:33 by aclakhda          #+#    #+#             */
/*   Updated: 2024/12/05 17:58:22 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	unlinker(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->name_list[i])
	{
		if (shell->allow)
			unlink(shell->name_list[i]);
		free(shell->name_list[i]);
		i++;
	}
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_all_shell(t_shell *shell, int i)
{
	if (i)
	{
		g_exit_status = overfl(g_exit_status);
		return ;
	}
	free_herdoc(shell, shell->herdoc);
	ft_free_tree(shell->tree_copy);
	if (shell->fd)
		close(shell->fd);
	free_all(shell);
	exit(g_exit_status);
}

void	handle_exit_error(t_shell *shell, char *msg, int exit_code)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	if (exit_code == 2)
		ft_putstr_fd(": numeric argument required", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	g_exit_status = exit_code;
	if (exit_code == 1)
		return ;
	free_all_shell(shell, 0);
}

void	ft_exit(t_shell *shell, int i, int j)
{
	if (shell->has_pipe)
		return (exit_pipe(shell));
	if (i)
		ft_putstr_fd("exit\n", STDERR_FILENO);
	if (shell->tree->right && !ft_strcmp(shell->tree->right->op, "--"))
	{
		g_exit_status = 0;
		free_all_shell(shell, 0);
	}
	if (shell->tree->right && j)
	{
		if (is_numeric(shell->tree->right->op) && !shell->tree->right->right)
		{
			g_exit_status = ft_atoi(shell->tree->right->op);
			if (ft_atoi(shell->tree->right->op) == LONG_MAX)
				return (handle_exit_error(shell, shell->tree->right->op, 2));
		}
		else if (!is_numeric(shell->tree->right->op))
			return (handle_exit_error(shell, shell->tree->right->op, 2));
		if (shell->tree->right->right && is_numeric(shell->tree->right->op))
			return (handle_exit_error(shell, "too many arguments", 1));
	}
	free_all_shell(shell, 0);
}
