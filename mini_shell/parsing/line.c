/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:08:04 by ysemlali          #+#    #+#             */
/*   Updated: 2024/10/14 23:08:06 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	getlen(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (metachar(*s))
			i += 3;
		else
			i++;
		s++;
	}
	return (i);
}

int	inquotes(char *s, int i, int x)
{
	int		one;
	int		two;
	char	*p;

	p = s;
	one = 0;
	two = 0;
	while (*p && p - s < i)
	{
		if (*p == '\'' && two % 2 == 0)
			one++;
		if (*p == '\"' && one % 2 == 0)
			two++;
		p++;
	}
	if (x == 1)
		return (one % 2 == 0 && two % 2 != 0);
	if (x == 2)
		return (one % 2 != 0 && two % 2 == 0);
	return (one % 2 != 0 || two % 2 != 0);
}

int	space(char *new, char *s, int *i)
{
	char	buf[5];

	bzero(buf, 5);
	buf[0] = ' ';
	buf[1] = s[*i];
	*i += 1;
	if (ft_strchr("<>", s[*i]) && s[*i] == s[*i - 1] && !inquotes(s, *i, 0))
	{
		buf[2] = s[*i];
		buf[3] = ' ';
		*i += 1;
	}
	else
		buf[2] = ' ';
	ft_strlcat(new, buf, 5);
	return (ft_strlen(buf));
}

int	expand_case(char *new, char *s, int *index)
{
	int	i;

	i = *index;
	while (i > 0 && (ft_isspace(s[i - 1]) || inquotes(s, i, 1)))
		i--;
	if (i > 0 && (s[i - 1] == '<' && s[i - 2] == '<'))
		*new = -99;
	else if (i > 0 && (s[i - 1] == '>' || s[i - 1] == '<'))
		*new = -100;
	else
		*new = '$';
	*index += 1;
	return (1);
}

void	spacing(t_shell *shell)
{
	char	*new;
	char	*tmp;
	char	*s;
	int		i;

	s = shell->s;
	new = ft_calloc(getlen(shell->s) * 2, 1);
	if (new)
	{
		tmp = new;
		i = 0;
		while (s[i])
		{
			if ((s[i] == '$' && inquotes(s, i, 2)))
				*new ++ = -s[i++];
			else if (s[i] == '$' && !inquotes(s, i, 2))
				new += expand_case(new, s, &i);
			else if (metachar(s[i]) && !inquotes(s, i, 0))
				new += space(new, s, &i);
			else
				*new ++ = s[i++];
		}
		free(shell->s);
		shell->s = tmp;
	}
}
