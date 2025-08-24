/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:52:34 by waissi          #+#    #+#             */
/*   Updated: 2024/12/09 15:47:08 by waissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	create_arr(char **arr, t_shell *shell)
{
	t_tree	*tmp;
	int		i;

	if (shell->tree->right == NULL)
		return (1);
	i = 0;
	tmp = shell->tree->right;
	while (tmp)
	{
		arr[i] = tmp->op;
		tmp = tmp->right;
		i++;
	}
	arr[i] = NULL;
	return (0);
}

t_env	*create_new_env(char *key, char *value, int i)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = ft_strdup((const char *)key);
	new->value = ft_strdup((const char *)value);
	if (!new->key || (!new->value && i))
	{
		free(new->key);
		free(new->value);
		free(new);
		return (NULL);
	}
	new->next = NULL;
	free(key);
	free(value);
	return (new);
}

void	create_env(char *key, char *value, t_shell *shell, int i)
{
	t_env	*tmp;
	t_env	*new;

	(void)i;
	tmp = shell->nv;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			update_existing_env(tmp, value, i, key);
			return ;
		}
		tmp = tmp->next;
	}
	new = create_new_env(key, value, i);
	if (!new)
		return ;
	tmp = shell->nv;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	export(t_shell *shell)
{
	char	*arr[1024];
	t_var	tmp;

	tmp.check = 0;
	if (create_arr(arr, shell))
	{
		print_env(shell);
		g_exit_status = 0;
		return ;
	}
	tmp.i = 0;
	while (arr[tmp.i])
	{
		process_export_entry(arr[tmp.i], shell, &tmp.check);
		if (!tmp.check && already_exist(arr[tmp.i], shell))
		{
			tmp.key = ft_substr(arr[tmp.i], 0, ft_strlen(arr[tmp.i]));
			create_env(tmp.key, NULL, shell, 0);
		}
		tmp.i++;
	}
}

void	unset(t_shell *shell)
{
	char	*arr[1024];
	int		i;

	i = 0;
	g_exit_status = 0;
	if (create_arr(arr, shell))
		return ;
	while (arr[i])
	{
		found_key(shell, arr[i]);
		i++;
	}
}
