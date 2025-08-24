/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:26:56 by waissi          #+#    #+#             */
/*   Updated: 2024/11/21 22:17:16 by waissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_child_process(t_shell *shell, t_var *var)
{
	char	buf[BUFFER_SML];

	ft_bzero(buf, BUFFER_SML);
	var->av = cmd_maker(shell);
	var->cmd_path = find_cmd_path(var->av, shell->nv);
	var->j = check_directory(var, shell);
	if (!var->cmd_path || !ft_strlen(shell->tree->op) || var->j)
	{
		ft_strlcat(buf, "minishell: ", BUFFER_SML);
		ft_strlcat(buf, var->av[0], BUFFER_SML);
		ft_strlcat(buf, ": command not found\n", BUFFER_SML);
		ft_putstr_fd(buf, STDERR);
		var->av = av_m(shell);
		execve("/bin/sh", var->av, NULL);
		perror("execve");
	}
	else
	{
		var->env = creat_env(shell->nv);
		if (execve(var->cmd_path, var->av, var->env) == -1)
			g_exit_status = 2;
	}
}

void	ft_exec_bin(t_shell *shell)
{
	t_var	var;

	shell->pid = fork();
	if (shell->pid == -1)
	{
		perror("fork");
		return ;
	}
	if (shell->pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		exec_child_process(shell, &var);
	}
	else
	{
		change_signals(1);
		waitpid(shell->pid, &g_exit_status, 0);
		handle_child_termination(g_exit_status);
	}
}

void	ft_exec_cmd(t_shell *shell)
{
	if (ft_strcmp(shell->tree->op, "echo") == 0)
	{
		echo(shell);
		g_exit_status = 0;
	}
	else if (ft_strcmp(shell->tree->op, "cd") == 0)
		cd(shell);
	else if (ft_strcmp(shell->tree->op, "env") == 0)
		env(shell);
	else if (ft_strcmp(shell->tree->op, "pwd") == 0)
		pwd(shell);
	else if (ft_strcmp(shell->tree->op, "export") == 0)
		export(shell);
	else if (ft_strcmp(shell->tree->op, "unset") == 0)
		unset(shell);
	else if (ft_strcmp(shell->tree->op, "exit") == 0)
		ft_exit(shell, 1, 1);
}

void	executing(t_shell *shell)
{
	if (!shell->tree)
		return ;
	else if (shell->tree->type == EMPTY)
	{
		shell->tree = shell->tree->right;
		executing(shell);
	}
	else if (is_rederaction(shell->tree->op) && type_check(shell->tree))
		ft_exec_rederect(shell);
	else if (shell->tree->type == PIPE)
		ft_pipe(shell);
	else if (check_cmd(shell))
		ft_exec_cmd(shell);
	else
		ft_exec_bin(shell);
}
