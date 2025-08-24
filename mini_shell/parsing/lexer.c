/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:06:04 by ysemlali &        #+#    #+#             */
/*   Updated: 2024/11/16 16:27:14 by waissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	t_type(char *s, t_oken *prev, int quote)
{
	char	c[2];

	c[0] = -40;
	c[1] = '\0';
	if (ft_strcmp(s, c) == 0 && quote == 0)
		return (EMPTY);
	if (ft_strcmp(s, "|") == 0 && quote == 0)
		return (PIPE);
	else if (ft_strcmp(s, "<") == 0 && quote == 0)
		return (INPUT);
	else if (ft_strcmp(s, ">") == 0 && quote == 0)
		return (OUTPUT);
	else if (ft_strcmp(s, ">>") == 0 && quote == 0)
		return (APPEND);
	else if (ft_strcmp(s, "<<") == 0 && quote == 0)
		return (HEREDOC);
	else if (prev == NULL || (prev && prev->type == PIPE))
		return (CMD);
	return (ARGS);
}

void	token(t_shell *shell, char **str)
{
	char	token[BUFFER_SML];
	int		i;
	char	*s;

	i = 0;
	s = *str;
	ft_bzero(token, BUFFER_SML);
	while (s[i])
	{
		while ((s[i] == '\"' || s[i] == '\'') && !inquotes(s, i, 0))
			shell->t->quote = s[i++];
		if (s[i] == '\0' || (ft_isspace(s[i]) && !inquotes(s, i, 0)))
			break ;
		if (s[i] != '\0' && shell->t->quote != s[i])
			ft_strlcat(token, s + i, ft_strlen(token) + 2);
		i++;
	}
	*str += i;
	shell->t->value = ft_strdup(token);
	shell->t->type = t_type(token, shell->t->prev, shell->t->quote);
}

int	skip_whitespace(char **s)
{
	while (**s && ft_isspace(**s))
		(*s)++;
	if (**s == '\0')
		return (-1);
	return (0);
}

void	lexer(t_shell *shell)
{
	char	*s;
	int		i;

	i = 0;
	s = shell->s;
	skip_whitespace(&s);
	while (*s)
	{
		if (skip_whitespace(&s) != 0)
			break ;
		shell->t = ft_lnew(NULL, 0, i++, ft_lstlast(shell->token));
		token(shell, &s);
		ft_lstadd_back(&shell->token, shell->t);
	}
}
