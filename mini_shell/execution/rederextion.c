/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rederextion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:35:04 by aclakhda          #+#    #+#             */
/*   Updated: 2024/11/18 22:28:03 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	redirect_in(t_shell *shell, int fd, int STD)
{
	if (shell->i_fd)
	{
		dup2(shell->i_fd, STD);
		close(fd);
	}
	else
	{
		shell->i_fd = fd;
		dup2(fd, STD);
	}
}

void	ft_exec_rederect_in(t_shell *shell)
{
	int		fd;
	int		stdin_copy;
	t_tree	*tmp;

	stdin_copy = dup(STDIN);
	fd = open(shell->tree->file_name, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
	{
		open_error(shell->tree->file_name);
		g_exit_status = 1;
		return ;
	}
	redirect_in(shell, fd, 0);
	tmp = shell->tree;
	shell->tree = shell->tree->left;
	executing(shell);
	shell->tree = tmp;
	dup2(stdin_copy, STDIN);
	close(stdin_copy);
	close(fd);
}

void	ft_exec_rederect_out(t_shell *shell)
{
	int		fd;
	int		stdout_copy;
	t_tree	*tmp;

	stdout_copy = dup(STDOUT);
	fd = open_file_for_writing(shell->tree->file_name);
	if (fd < 0)
	{
		open_error(shell->tree->file_name);
		g_exit_status = 1;
		return ;
	}
	redirect_output(shell, fd, 1);
	tmp = shell->tree;
	shell->tree = shell->tree->left;
	executing(shell);
	shell->tree = tmp;
	dup2(stdout_copy, STDOUT);
	close(stdout_copy);
	close(fd);
}

void	ft_exec_rederect_out_append(t_shell *shell)
{
	int		fd;
	int		stdout_copy;
	t_tree	*tmp;

	stdout_copy = dup(STDOUT);
	fd = open(shell->tree->file_name, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		open_error(shell->tree->file_name);
		g_exit_status = 1;
		return ;
	}
	redirect_output(shell, fd, 1);
	tmp = shell->tree;
	shell->tree = shell->tree->left;
	executing(shell);
	shell->tree = tmp;
	dup2(stdout_copy, STDOUT);
	close(stdout_copy);
	close(fd);
}

void	ft_exec_rederect(t_shell *shell)
{
	if (checks_err(shell))
		return ;
	if (ft_strcmp(shell->tree->op, ">") == 0)
		ft_exec_rederect_out(shell);
	else if (ft_strcmp(shell->tree->op, ">>") == 0)
		ft_exec_rederect_out_append(shell);
	else if (ft_strcmp(shell->tree->op, "<") == 0)
		ft_exec_rederect_in(shell);
	else if (ft_strcmp(shell->tree->op, "<<") == 0)
		ft_exec_rederect_herd(shell, 0);
}
