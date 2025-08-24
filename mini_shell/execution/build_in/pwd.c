/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:12:15 by waissi          #+#    #+#             */
/*   Updated: 2024/11/21 23:49:30 by waissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd(t_shell *shell)
{
	char	buf[PATH_MAX];
	char	*pwd;

	(void)shell;
	pwd = getcwd(buf, PATH_MAX);
	if (!pwd)
	{
		perror("getcwd:");
		g_exit_status = -1;
	}
	if (pwd)
	{
		printf("%s\n", pwd);
		g_exit_status = 0;
	}
}

void	nothing(t_oken *t)
{
	open_error(t->next->value);
	g_exit_status = 1;
}
