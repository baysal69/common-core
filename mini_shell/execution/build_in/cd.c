/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:20:15 by aclakhda          #+#    #+#             */
/*   Updated: 2024/11/05 21:49:02 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_str_cpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_str_join(char const *s1, char const *s2)
{
	size_t	i;
	size_t	l1;
	size_t	l2;
	char	*p;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!p)
		return (NULL);
	ft_str_cpy(p, s1);
	i = 0;
	while (s2[i])
	{
		p[l1++] = s2[i++];
	}
	p[l1] = '\0';
	return (p);
}

void	cd(t_shell *shell)
{
	char	**av;
	char	past_path[1024];

	if (shell->tree->right && shell->tree->right->right)
	{
		ft_putstr_fd("cd: too many argument :c\n", 2);
		g_exit_status = 1;
		return ;
	}
	getcwd(past_path, sizeof(past_path));
	if (getcwd(past_path, sizeof(past_path)) == NULL)
	{
		perror("getcwd :");
		g_exit_status = 1;
		return ;
	}
	if (!shell->tree->right || !ft_strcmp(shell->tree->right->op, "~"))
		handle_home_directory(shell);
	else
	{
		av = cmd_maker(shell);
		change_directory(shell, av[1], av);
	}
	if (g_exit_status == 0)
		update_paths(shell, past_path);
}
