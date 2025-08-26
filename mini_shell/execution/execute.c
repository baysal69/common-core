/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:12:59 by waissi            #+#    #+#             */
/*   Updated: 2025/08/25 12:54:40 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_tree	*create_tree(t_shell *shell, t_oken *tokens)
{
	t_oken	*last_redirection_pipe;

	last_redirection_pipe = NULL;
	last_redirection_pipe = last_p_r(shell, tokens);
	if (last_redirection_pipe && last_redirection_pipe->read == 0
		&& last_redirection_pipe->type == PIPE)
		return (creat_tree_pipe(shell, tokens, last_redirection_pipe));
	else if (last_redirection_pipe && last_redirection_pipe->read == 0
		&& !isnt_red(last_redirection_pipe->type, 1))
		return (creat_tree_red(shell, tokens, last_redirection_pipe));
	return (create_simple_tree(shell, tokens));
}

t_herdoc	*set_up(t_oken *token)
{
	t_herdoc	*herdoc;
	t_oken		*current;
	int			j;

	herdoc = NULL;
	current = token;
	j = 0;
	while (current)
	{
		if (current->type == HEREDOC)
		{
			current = current->next;
			if (!herdoc)
				herdoc = s(set(token));
			herdoc->line[j++] = ft_strdup(current->value);
		}
		current = current->next;
	}
	if (herdoc)
		herdoc->herdoc = j;
	return (herdoc);
}

int	set_up_file_name(t_shell *shell, int range)
{
	char	*name;
	int		fd;
	char	*file_n;

	file_n = random_name_gen();
	name = ft_strjoin("/tmp/.heredoc_", file_n);
	free(file_n);
	shell->name_list[range] = name;
	shell->name_list[range + 1] = NULL;
	fd = open(name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}

int	execute(t_shell *shell)
{
	t_oken	*tmp;

	set_file(shell);
	shell->pipe_count = pipe_count(shell->token);
	shell->tree = create_tree(shell, shell->token);
	shell->tree_copy = shell->tree;
	tmp = shell->token;
	shell->herdoc = set_up(tmp);
	if (shell->herdoc != NULL)
		ft_exec_rederect_herd(shell, 1);
	executing(shell);
	free_herdoc(shell, shell->herdoc);
	if (shell->fd != 0)
		close(shell->fd);
	ft_free_tree(shell->tree);
	if (shell->fd)
		close(shell->fd);
	if (shell->r_fd)
		close(shell->r_fd);
	return (0);
}
