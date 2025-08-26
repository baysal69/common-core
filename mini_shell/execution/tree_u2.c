/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_u2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahab <adahab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:51:56 by adahab            #+#    #+#             */
/*   Updated: 2025/08/25 12:58:41 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_oken	*find_last_pipe(t_shell *shell, t_oken *tokens)
{
	t_oken	*current;
	t_oken	*last_pipe;

	last_pipe = NULL;
	current = tokens;
	while (current)
	{
		if (current->type == PIPE && current->read == 0)
			last_pipe = current;
		else if (!shell->pipe_count)
			return (NULL);
		current = current->next;
	}
	return (last_pipe);
}

t_oken	*find_last_redirection(t_oken *tokens)
{
	t_oken	*current;
	t_oken	*last_redirection;

	last_redirection = NULL;
	current = tokens;
	while (current)
	{
		if (!isnt_red(current->type, 1) && current->read == 0)
			last_redirection = current;
		current = current->next;
	}
	return (last_redirection);
}

t_oken	*last_p_r(t_shell *shell, t_oken *tokens)
{
	t_oken	*last_redirection_pipe;

	last_redirection_pipe = find_last_pipe(shell, tokens);
	if (!last_redirection_pipe)
		last_redirection_pipe = find_last_redirection(tokens);
	return (last_redirection_pipe);
}

t_oken	*creat_token(t_oken *tokens, t_oken *last_redirection)
{
	t_oken	*current;
	t_oken	*tmp;
	t_oken	*new;

	current = tokens;
	tmp = NULL;
	new = NULL;
	while (current != last_redirection)
	{
		new = ft_lnew(ft_strdup(current->value), current->type, 0, NULL);
		new->read = current->read;
		new->fd = current->fd;
		ft_lstadd_back(&tmp, new);
		current = current->next;
	}
	current = last_redirection->next->next;
	while (current && current->type != PIPE && isnt_red(current->type, 1))
	{
		new = ft_lnew(ft_strdup(current->value), current->type, 0, NULL);
		new->read = current->read;
		new->fd = current->fd;
		ft_lstadd_back(&tmp, new);
		current = current->next;
	}
	return (tmp);
}

t_tree	*creat_node(t_oken *token, char *file_name, int fd)
{
	t_tree	*node;

	node = malloc(sizeof(t_tree));
	node->op = ft_strdup(token->value);
	if (file_name)
		node->file_name = ft_strdup(file_name);
	else
		node->file_name = NULL;
	node->left = NULL;
	node->right = NULL;
	node->type = token->type;
	node->fd = fd;
	return (node);
}
