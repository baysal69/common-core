/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 22:39:24 by waissi          #+#    #+#             */
/*   Updated: 2024/09/26 23:39:17 by waissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_pipe(t_shell *shell)
{
	if (shell->tree->right)
	{
		handle_exit_numeric(shell);
		if (shell->tree->right->right && g_exit_status != 2)
		{
			handle_exit_too_many_args();
			return ;
		}
	}
	else
		g_exit_status = 0;
	free_all_shell(shell, 1);
}

void	handle_exit_too_many_args(void)
{
	ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
	g_exit_status = 1;
}

void	handle_exit_numeric(t_shell *shell)
{
	if (is_numeric(shell->tree->right->op))
		g_exit_status = ft_atoi(shell->tree->right->op);
	else
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(shell->tree->right->op, STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		g_exit_status = 2;
	}
}

size_t	overfl(int g_exit_status)
{
	if (g_exit_status < 0)
		return (256 + (g_exit_status % 256));
	return (g_exit_status % 256);
}
