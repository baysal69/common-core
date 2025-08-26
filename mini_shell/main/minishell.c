/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahab <adahab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 01:32:24 by adahab            #+#    #+#             */
/*   Updated: 2025/08/25 01:32:24 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		g_exit_status = 0;

void	ctrl_c_remove(void)
{
	struct termios	t;

	tcgetattr(0, &t);
	t.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &t);
}

void	minishell(t_shell *shell)
{
	shell->status = execute(shell);
}

void	free_keys(char *key, char *value)
{
	free(key);
	free(value);
}

void	reset(t_shell *shell)
{
	change_signals(2);
	free(shell->s);
	ft_lstclear(&shell->token);
	shell->err = 0;
	shell->begin = 0;
	shell->status = 0;
	shell->r_fd = 0;
	shell->end = 0;
	shell->has_pipe = 0;
	shell->pipe_count = 0;
	shell->pid = 0;
	shell->pid2 = 0;
	shell->d_change = 0;
	shell->allow = 1;
	shell->i_fd = 0;
	shell->s = NULL;
}

int	main(const int ac, char **av, char **nv)
{
	t_shell	*shell;

	if (*nv == NULL)
		init(&shell, ac, av, NULL);
	else
		init(&shell, ac, av, nv);
	ctrl_c_remove();
	while (shell->status == 0)
	{
		reset(shell);
		parse(shell);
		if (shell->err == 0 && shell->token)
			minishell(shell);
	}
	return (0);
}
