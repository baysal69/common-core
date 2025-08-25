/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rederction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 23:15:09 by waissi          #+#    #+#             */
/*   Updated: 2025/12/07 15:31:14 by waissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_continue_rederect_herd(t_shell *shell)
{
	int		fd;
	int		stdin_copy;
	t_tree	*tmp;

	fd = open(shell->name_list[shell->tree->fd - 3], O_RDWR);
	if (fd < 0)
	{
		open_error("BAYSAL SHELL");
		g_exit_status = 1;
		return ;
	}
	stdin_copy = dup(STDIN);
	dup2(fd, STDIN);
	close(fd);
	tmp = shell->tree;
	shell->tree = shell->tree->left;
	executing(shell);
	shell->tree = tmp;
	dup2(stdin_copy, STDIN);
	close(stdin_copy);
}

t_oken	*next(t_oken *token, int i)
{
	t_oken	*tmp;

	if (i)
		_reset(token);
	tmp = token;
	while (tmp)
	{
		if (tmp->type == HEREDOC && tmp->read == 0)
		{
			tmp->read = 1;
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (tmp);
}

void	handle_heredoc_line(t_shell *shell, char *line, int *i)
{
	char	*tmp;

	if (ft_strcmp(line, shell->herdoc->line[*i]) == 0)
	{
		shell->tmp = next(shell->tmp, 0);
		free(line);
		(*i)++;
		shell->herdoc->herdoc--;
		return ;
	}
	tmp = line;
	line = var(line, shell->nv);
	if (!ft_strcmp(line, ""))
	{
		free(line);
		line = tmp;
	}
	else
		free(tmp);
	write(shell->tmp->fd, line, ft_strlen(line));
	write(shell->tmp->fd, "\n", 1);
	free(line);
}

void	process_heredoc(t_shell *shell)
{
	char	*line;
	int		i;

	i = 0;
	shell->tmp = shell->token;
	shell->tmp = next(shell->token, 1);
	while (shell->herdoc->herdoc && g_exit_status != CTRL_C)
	{
		line = readline("> ");
		if (line)
			handle_heredoc_line(shell, line, &i);
		else
		{
			if (g_exit_status != 130)
				heredoc_warning(shell, 0);
			if (shell->herdoc->line[i + 1])
				i++;
			else
				free_all_shell(shell, 0);
		}
	}
	free_all_shell(shell, 0);
}

void	ft_exec_rederect_herd(t_shell *shell, int j)
{
	shell->status = 0;
	if (shell->herdoc->herdoc > 17)
		heredoc_warning(shell, 1);
	if (j)
	{
		shell->pid = fork();
		if (shell->pid == 0)
		{
			signal(SIGINT, heredoc_signals);
			shell->allow = 0;
			g_exit_status = 0;
			process_heredoc(shell);
		}
		else
		{
			change_signals(1);
			waitpid(shell->pid, &shell->status, 0);
			if (WIFEXITED(shell->status))
				g_exit_status = WEXITSTATUS(shell->status);
		}
	}
	else if (ft_strcmp(shell->tree->op, "<<") == 0)
		ft_continue_rederect_herd(shell);
}
