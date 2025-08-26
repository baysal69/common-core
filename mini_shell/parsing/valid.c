/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:08:58 by ysemlali          #+#    #+#             */
/*   Updated: 2024/11/12 20:52:42 by waissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	heredoc_error(t_shell *shell, int type, t_oken *next)
{
	if (shell->err == ERR_SYNTAX)
		return ;
	if (type == HEREDOC && next == NULL)
	{
		shell->err = ERR_SYNTAX;
		g_exit_status = 2;
		ft_putendl_fd("minishell: syntax error near unexpected token `newline'",
			2);
	}
	else if (type == HEREDOC && next->type != END && next->type != ARGS)
	{
		shell->err = ERR_SYNTAX;
		g_exit_status = 2;
		ft_putstr_fd("minishell: syntax error near unexpected token  `", 2);
		ft_putstr_fd(next->value, 2);
		ft_putstr_fd("'\n", 2);
	}
}

void	redirect_error(t_shell *shell, int type, t_oken *next)
{
	if (shell->err == ERR_SYNTAX)
		return ;
	if ((type == OUTPUT || type == INPUT || type == APPEND) && (next == NULL
			|| next->type != ARGS))
	{
		shell->err = ERR_SYNTAX;
		g_exit_status = 2;
		if (next == NULL)
		{
			ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
			ft_putendl_fd("`newline'", 2);
		}
		else
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
			ft_putstr_fd(next->value, 2);
			ft_putstr_fd("'\n", 2);
		}
	}
}

void	pipe_error(t_shell *shell, t_oken *token, t_oken *next)
{
	if (shell->err == ERR_SYNTAX)
		return ;
	if (next == NULL || next->type == PIPE || token->index == 0)
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|'", 2);
		shell->err = ERR_SYNTAX;
		g_exit_status = 2;
	}
}

void	valid(t_shell *shell)
{
	t_oken	*token;

	token = shell->token;
	while (token)
	{
		if (token->type == PIPE)
			pipe_error(shell, token, token->next);
		if (token->type == HEREDOC)
			heredoc_error(shell, token->type, token->next);
		if ((token->type == OUTPUT || token->type == INPUT
				|| token->type == APPEND) && (token->next == NULL
				|| token->next->type != ARGS))
			redirect_error(shell, token->type, token->next);
		if (shell->err == ERR_SYNTAX)
			break ;
		token = token->next;
	}
}
