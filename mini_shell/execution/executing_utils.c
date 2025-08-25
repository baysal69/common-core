/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:54:13 by waissi          #+#    #+#             */
/*   Updated: 2025/08/25 19:02:44 by waissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*creating_cmd_path(int len, char **path_split, int i, char *av)
{
	char	*cmd_path;

	cmd_path = malloc(len * sizeof(char));
	if (!cmd_path)
	{
		s_free(path_split);
		return (NULL);
	}
	ft_strcpy(cmd_path, path_split[i]);
	ft_strcat(cmd_path, "/");
	ft_strcat(cmd_path, av);
	return (cmd_path);
}

void	s_free(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

int	check_cmd(t_shell *shell)
{
	if (!ft_strcmp("echo", shell->tree->op) || !ft_strcmp("cd", shell->tree->op)
		|| !ft_strcmp("pwd", shell->tree->op) || !ft_strcmp("export",
			shell->tree->op) || !ft_strcmp("unset", shell->tree->op)
		|| !ft_strcmp("env", shell->tree->op) || !ft_strcmp("exit",
			shell->tree->op))
		return (1);
	return (0);
}

int	is_rederaction(char *c)
{
	if (!ft_strcmp(c, ">") || !ft_strcmp(c, "<") || !ft_strcmp(c, ">>")
		|| !ft_strcmp(c, "<<"))
		return (1);
	return (0);
}

int	is_herd(char *c)
{
	if (!ft_strcmp(c, "<<"))
		return (1);
	return (0);
}
