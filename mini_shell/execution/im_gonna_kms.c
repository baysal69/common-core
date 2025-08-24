/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   im_gonna_kms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 01:06:45 by waissi          #+#    #+#             */
/*   Updated: 2024/11/10 20:28:16 by waissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	pipe_count(t_oken *token)
{
	t_oken	*tmp;
	int		i;

	tmp = token;
	i = 0;
	while (tmp)
	{
		if (tmp->type == PIPE)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

t_tree	*create_simple_tree(t_shell *shell, t_oken *tokens)
{
	t_tree	*root;

	if (tokens)
	{
		root = creat_node(tokens, NULL, 0);
		root->index = tokens->index;
		if (tokens->next && (tokens->next->type == ARGS
				|| tokens->next->type == CMD))
			root->right = create_tree(shell, tokens->next);
		return (root);
	}
	return (NULL);
}

t_herdoc	*s(int i)
{
	t_herdoc	*herdoc;

	herdoc = malloc(sizeof(t_herdoc));
	herdoc->line = malloc(sizeof(char *) * (i + 1));
	herdoc->line[i] = NULL;
	return (herdoc);
}

void	count_tree_nodes(t_tree *tree, int *count)
{
	t_tree	*tmp;

	tmp = tree;
	*count = 0;
	while (tmp)
	{
		(*count)++;
		tmp = tmp->right;
	}
}

void	free_av1(char **av)
{
	int	i;

	if (!av)
		return ;
	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
