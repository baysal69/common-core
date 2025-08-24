/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 23:32:06 by aclakhda          #+#    #+#             */
/*   Updated: 2024/11/12 16:45:02 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_open_error(void)
{
	ft_putstr_fd("failed to open\n", 2);
	g_exit_status = 1;
}

int	open_file_for_writing(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	return (fd);
}

void	redirect_output(t_shell *shell, int fd, int STD)
{
	if (shell->r_fd)
	{
		dup2(shell->r_fd, STD);
		close(fd);
	}
	else
	{
		shell->r_fd = fd;
		dup2(fd, STD);
	}
}

void	handle_left_subtree(t_shell *shell, t_tree *root, t_oken *tokens,
		t_oken *last_r_pip)
{
	t_oken	*new_token;

	if (last_r_pip->next->next)
	{
		new_token = creat_token(tokens, last_r_pip);
		root->left = create_tree(shell, new_token);
		ft_free_token(new_token);
	}
	else if (last_r_pip != tokens)
		root->left = create_tree(shell, tokens);
}

void	handle_right_subtree(t_shell *shell, t_tree *root, t_oken *last_r_pip)
{
	t_oken	*tmp;

	tmp = find_next_token(last_r_pip->next->next);
	if (last_r_pip->next->next && tmp && tmp->read == 0)
		root->right = create_tree(shell, tmp);
	else
		root->right = NULL;
}
