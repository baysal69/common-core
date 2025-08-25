/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:12:39 by waissi          #+#    #+#             */
/*   Updated: 2025/08/25 16:12:42 by waissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_flag(char *av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (av[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	echo(t_shell *shell)
{
	t_tree	*tmp;
	int		flag;
	int		j;

	tmp = shell->tree->right;
	flag = 0;
	j = 0;
	while (tmp)
	{
		if (tmp->op[0] == '-' && is_flag(tmp->op) && j == 0)
		{
			if (tmp->op[1] != '\0')
				flag = 1;
		}
		else
		{
			ft_putstr_fd(tmp->op, 1);
			if (tmp->right)
				ft_putstr_fd(" ", 1);
			j = 1;
		}
		tmp = tmp->right;
	}
	if (flag == 0)
		ft_putstr_fd("\n", 1);
}
