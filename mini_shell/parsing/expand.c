/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahab <adahab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:34:26 by adahab            #+#    #+#             */
/*   Updated: 2025/08/25 11:10:52 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_variable_size(char *s, t_env *nv)
{
	int		len;
	char	env[1024];

	len = 0;
	while (*s)
	{
		if (ft_strncmp(s, "$?", 2) == 0)
			len += get_num_len(g_exit_status);
		if (ft_strncmp(s, "$$", 2) == 0)
			len += 2;
		if (ft_strncmp(s, "$#", 2) == 0 || ft_strncmp(s, "\"$\"", 3) == 0)
			len++;
		if (ft_strncmp(s, "$0", 2) == 0)
			len += ft_strlen("minishell");
		if (*s == '$' && (ft_isspace(*(s + 1)) || *(s + 1) == '\0'))
			len++;
		if (*s == '$' && !ft_isspace(*(s + 1)) && *(s + 1) != '/')
		{
			ft_strlcpy(env, s + 1, ft_strcspn(s + 1, "$ =\'\"\t\f\v\r/") + 1);
			len += (ft_strlen(get_env(nv, env)));
		}
		len++;
		s++;
	}
	return (len);
}

int	normal_expansion(char *s, t_env *nv, char *buf, int size)
{
	char	env[1024];
	char	c[2];
	char	*tmp;

	c[0] = -40;
	c[1] = '\0';
	ft_strlcpy(env, s + 1, ft_strcspn(s + 1, "$ =\'\"\t\f\v\r/") + 1);
	if (get_env(nv, env) == NULL)
		ft_strlcat(buf, c, size);
	else
	{
		tmp = get_env(nv, env);
		if (ft_strchr(tmp, '\'') != NULL || ft_strchr(tmp, '\"') != NULL)
		{
			ft_strlcat(buf, "\"", size);
			ft_strlcat(buf, tmp, size);
			ft_strlcat(buf, "\"", size);
		}
		else
			ft_strlcat(buf, tmp, size);
	}
	return (ft_strlen(env) + 1);
}

int	redirection_expansion(char *s, t_env *nv, char *buf, int size)
{
	char	env[1024];
	char	*d;

	d = "$ =\'\"\t\f\v\r/";
	ft_strlcpy(env, s + 1, ft_strcspn(s + 1, d) + 1);
	if (*s == -100 && get_env(nv, env) == NULL)
		ft_strlcat(buf, s, ft_strcspn(s + 1, d) + ft_strlen(buf) + 2);
	if (*s == -100 && get_env(nv, env) != NULL)
	{
		if (ft_count_words(get_env(nv, env), ' ') != 1)
			ft_strlcat(buf, s, (ft_strcspn(s + 1, d) + ft_strlen(buf) + 2));
		else
			ft_strlcat(buf, get_env(nv, env), size);
	}
	if (*s == -99)
		ft_strlcat(buf, s, (ft_strcspn(s + 1, d) + ft_strlen(buf) + 2));
	return (ft_strlen(env) + 1);
}

int	get_variables(char *s, char *buf, t_env *nv, int size)
{
	char	*tmp;

	if (ft_strncmp(s, "$?", 2) == 0)
		return (ft_strlcat(buf, (tmp = ft_itoa(g_exit_status)), size),
			free(tmp), 2);
	if (ft_strncmp(s, "$$", 2) == 0)
		return (ft_strlcat(buf, "$$", size), 2);
	if (ft_strncmp(s, "$#", 2) == 0)
		return (ft_strlcat(buf, "0", size), 2);
	if (ft_strncmp(s, "\"$\"", 3) == 0)
		return (ft_strlcat(buf, "$", size), 3);
	if (ft_strncmp(s, "$0", 2) == 0)
		return (ft_strlcat(buf, "minishell", size), 2);
	if (*s == '$' && (ft_isspace(*(s + 1)) || *(s + 1) == '\0'))
		return (ft_strlcat(buf, "$", size), 1);
	if (*s == '$' && !ft_isspace(*(s + 1)) && *(s + 1) != '/')
		return (normal_expansion(s, nv, buf, size));
	if ((*s == -99 || *s == -100) && !ft_isspace(*(s + 1)) && *(s + 1) != '/')
		return (redirection_expansion(s, nv, buf, size));
	return (ft_strlcat(buf, s, ft_strlen(buf) + 2), 1);
}

void	expand(t_shell *shell)
{
	char	*buf;
	char	*s;
	int		size;

	s = shell->s;
	size = get_variable_size(s, shell->nv) * 2;
	buf = ft_calloc(size, 1);
	if (buf)
	{
		while (*s)
			s += get_variables(s, buf, shell->nv, size);
		free(shell->s);
		shell->s = ft_strmapi(buf, toggle);
		free(buf);
	}
}
