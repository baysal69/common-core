/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:46:55 by aclakhda          #+#    #+#             */
/*   Updated: 2024/11/14 20:41:47 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_strcmp2(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	ft_size(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

void	ft_found(t_shell *shell, t_var *var, int start, int end)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	j = 0;
	var->i = start;
	while (var->i <= end)
	{
		if (ft_strcmp2(shell->av[var->i], "|") == 0 && i++ == 0)
			var->has_pipe = var->i;
		if (is_rederaction(shell->av[var->i]) && j++ == 0)
			var->has_rederect = var->i;
		if (is_herd(shell->av[var->i]) && k++ == 0)
			var->has_herd = var->i;
		var->i++;
	}
}

void	ft_free_tree(t_tree *root)
{
	if (root == NULL)
		return ;
	ft_free_tree(root->left);
	ft_free_tree(root->right);
	if (root->file_name)
		free(root->file_name);
	if (root->fd)
		close(root->fd);
	free(root->op);
	free(root);
	root = NULL;
}

char	*ft_strcat(char *dest, char *src)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (dest[x])
		x++;
	while (src[y])
	{
		dest[x + y] = src[y];
		y++;
	}
	dest[x + y] = '\0';
	return (dest);
}
