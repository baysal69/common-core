/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:18:41 by waissi          #+#    #+#             */
/*   Updated: 2024/11/21 16:53:58 by waissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	type_check(t_tree *tree)
{
	if (tree->type == OUTPUT || tree->type == INPUT || tree->type == APPEND
		|| tree->type == HEREDOC)
		return (1);
	return (0);
}

int	check_directory(t_var *var, t_shell *shell)
{
	struct stat	path_stat;

	if (stat(var->av[0], &path_stat) == -1)
	{
		if (var->cmd_path || check_is_dir_path(var->av[0]))
			return (0);
		print_err(var->av[0], 1);
		g_exit_status = 127;
		handle_exec_error(var, shell, 0);
	}
	if (S_ISDIR(path_stat.st_mode))
	{
		if (check_is_dir_path(var->av[0]))
			return (1);
		print_err(var->av[0], 0);
		for_norminet(var, shell);
	}
	if (access(var->av[0], X_OK) == -1)
	{
		if (ft_strncmp("./", var->av[0], 2) && ft_strncmp("/", var->av[0], 1))
			return (0);
		print_err(var->av[0], 3);
		for_norminet(var, shell);
	}
	return (0);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}
