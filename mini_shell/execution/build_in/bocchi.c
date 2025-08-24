/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bocchi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:53:13 by aclakhda          #+#    #+#             */
/*   Updated: 2024/11/12 20:28:12 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*file_name(t_shell *shell)
{
	if (!ft_strcmp("1", shell->tree->right->op))
		return ("the_bocchies/bocchi.txt");
	else if (!ft_strcmp("2", shell->tree->right->op))
		return ("the_bocchies/k-on.txt");
	else if (!ft_strcmp("3", shell->tree->right->op))
		return ("the_bocchies/frieren.txt");
	return (NULL);
}

void	bocchi(t_shell *shell)
{
	char	*line;
	int		fd;

	if (!shell->tree->right)
	{
		printf("1 : print bocchi\n2 : print k-on\n3 : print frieren\n");
		return ;
	}
	fd = open(file_name(shell), O_RDONLY, 0644);
	line = get_next_line(fd);
	if (!line)
	{
		ft_putstr_fd("bocchi.txt: No such file or directory\n", STDERR);
		return ;
	}
	while (line)
	{
		ft_putstr_fd(line, STDOUT);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
