/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahab <adahab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:16:40 by adahab            #+#    #+#             */
/*   Updated: 2025/08/25 11:11:03 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	write_error(char *s, t_shell *shell)
{
	ft_putstr_fd("Minishell: export: `", 2);
	ft_putstr_fd(s, 2);
	ft_putendl_fd("': not a valid identifier", 2);
	shell->d_change = 1;
	g_exit_status = 1;
}

int	valid_plus(char current, char next)
{
	if (current == '+' && next != '=')
		return (1);
	return (0);
}

int	validate(char *s, t_shell *shell)
{
	char	*tmp;

	tmp = s;
	if (ft_isdigit(s[0]) || s[0] == '=')
	{
		write_error(tmp, shell);
		return (1);
	}
	while (*s && *s != '=')
	{
		if (*s == '-' || *s == '!' || *s == '@' || *s == '#' || *s == '%'
			|| *s == '^' || *s == '&' || *s == '*' || *s == '(' || *s == ')'
			|| *s == '[' || *s == ']' || *s == '{' || *s == '}' || *s == ';'
			|| *s == ':' || *s == '"' || *s == '\'' || *s == '\\' || *s == '|'
			|| *s == '<' || *s == '>' || *s == '?' || *s == ',' || *s == '.'
			|| *s == '/' || *s == ' ' || *s == '$' || valid_plus(*s, *(s + 1)))
		{
			write_error(tmp, shell);
			return (1);
		}
		s++;
	}
	return (0);
}
