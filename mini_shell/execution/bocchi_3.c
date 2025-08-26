/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bocchi_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 01:20:55 by waissi            #+#    #+#             */
/*   Updated: 2025/08/25 22:17:38 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**av_m(t_shell *shell)
{
	char	**av;

	av = malloc(4 * sizeof(char *));
	if (!av)
	{
		perror("malloc");
		g_exit_status = EXIT_FAILURE;
		free_all_shell(shell, 0);
	}
	av[0] = "/bin/sh";
	av[1] = "-c";
	av[2] = "exit 42";
	av[3] = NULL;
	return (av);
}

char	*find_cmd_path(char **av, t_env *nv)
{
	t_var	var;
	char	**path_split;

	var.i = 0;
	if (!access(av[0], X_OK))
		return (av[0]);
	path_split = ft_split(get_env(nv, "PATH"), ':');
	if (!path_split)
		return (NULL);
	while (path_split && path_split[var.i])
	{
		var.len = ft_strlen(path_split[var.i]) + ft_strlen(av[0]) + 2;
		var.cmd_path = creating_cmd_path(var.len, path_split, var.i, av[0]);
		if (!var.cmd_path)
			return (NULL);
		if (access(var.cmd_path, X_OK) == 0)
		{
			s_free(path_split);
			return (var.cmd_path);
		}
		var.i++;
		free(var.cmd_path);
	}
	s_free(path_split);
	return (NULL);
}

char	**allocate_av(int count)
{
	char	**av;

	av = (char **)malloc(sizeof(char *) * (count + 1));
	if (!av)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (av);
}

void	fill_av(t_tree *tree, char **av)
{
	int		i;
	t_tree	*tmp;

	i = 0;
	tmp = tree;
	while (tmp)
	{
		av[i] = ft_strdup(tmp->op);
		tmp = tmp->right;
		i++;
	}
	av[i] = NULL;
}

char	**cmd_maker(t_shell *shell)
{
	int		count;
	char	**av;

	count_tree_nodes(shell->tree, &count);
	av = allocate_av(count);
	fill_av(shell->tree, av);
	return (av);
}
