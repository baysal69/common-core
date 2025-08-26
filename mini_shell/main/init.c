/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahab <adahab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:37:19 by adahab            #+#    #+#             */
/*   Updated: 2025/08/25 15:02:58 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_value(char *key)
{
	char	*value;

	if (ft_strcmp(key, "PWD") == 0)
		value = ft_strdup(getcwd(NULL, 0));
	else if (ft_strcmp(key, "SHLVL") == 0)
		value = ft_strdup("1");
	else if (ft_strcmp(key, "_") == 0)
		value = ft_strdup("/usr/bin/env");
	else
		value = ft_strdup("");
	return (value);
}

void	init_basic_env(t_shell **shell, char **nv)
{
	t_env	*tmp;
	int		i;

	i = 0;
	(*shell)->nv = ft_calloc(1, sizeof(t_env));
	if ((*shell)->nv)
	{
		tmp = (*shell)->nv;
		while (nv[i])
		{
			(*shell)->nv->key = ft_strdup(nv[i]);
			(*shell)->nv->value = get_value(nv[i]);
			if (nv[i + 1] != NULL)
			{
				(*shell)->nv->next = ft_calloc(1, sizeof(t_env));
				(*shell)->nv = (*shell)->nv->next;
			}
			i++;
		}
		(*shell)->nv->next = NULL;
		(*shell)->nv = tmp;
	}
}

void	init(t_shell **shell, int ac, char **av, char **nv)
{
	char	*basic[4];

	signal(SIGINT, readline_mode);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGABRT, SIG_IGN);
	basic[0] = "PWD";
	basic[1] = "SHLVL";
	basic[2] = "_";
	basic[3] = NULL;
	(void)ac;
	(void)av;
	*shell = ft_calloc(1, sizeof(t_shell));
	(*shell)->status = 0;
	if (nv == NULL)
		init_basic_env(shell, basic);
	else
		init_env(shell, nv);
}
