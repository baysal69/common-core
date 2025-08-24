/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_file_gen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:49:37 by aclakhda          #+#    #+#             */
/*   Updated: 2024/11/12 17:21:36 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	creat_fd_2(char *file_name, int i)
{
	int	fd;

	if (i)
	{
		fd = open(file_name, O_RDWR | O_CREAT | O_APPEND, 0644);
		if (fd < 0)
		{
			open_error(file_name);
			g_exit_status = 1;
			return (-1);
		}
	}
	else
	{
		fd = open_file_for_writing(file_name);
		if (fd < 0)
		{
			open_error(file_name);
			g_exit_status = 1;
			return (-1);
		}
	}
	close(fd);
	return (1);
}

int	random_number_gen(void)
{
	unsigned int	r_num;
	int				fd;

	fd = open("/dev/urandom", O_RDONLY);
	read(fd, &r_num, sizeof(r_num));
	close(fd);
	return ((r_num % 10));
}

char	*random_name_gen(void)
{
	char	arr[11];
	char	*str;
	int		i;

	i = 0;
	ft_str_cpy(arr, "aSDmNoZ@_k");
	str = (char *)malloc(sizeof(char) * 11);
	while (i < 9)
	{
		str[i] = arr[random_number_gen()];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	printt(char *file_name)
{
	char	*line;
	int		fd;

	fd = open(file_name, O_CREAT | O_RDWR, 0644);
	line = get_next_line(fd);
	if (line)
	{
		ft_putstr_fd(line, 2);
		free(line);
	}
	close(fd);
}

t_oken	*return_tmp(t_shell *shell)
{
	t_oken	*tmp;

	tmp = shell->token;
	while (shell->tree->index != tmp->index)
		tmp = tmp->next;
	while (tmp && tmp->type != PIPE)
	{
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}
// void	random_err(char **av)
// {
// 	int		fd;
// 	char	*r_file;
// 	char	*n_file;

// 	r_file = random_name_gen();
// 	n_file = ft_strjoin(".", r_file);
// 	fd = open(n_file, O_CREAT | O_RDWR | O_APPEND, 0644);
// 	ft_putstr_fd("minishell: ", fd);
// 	ft_putstr_fd(av[0], fd);
// 	ft_putstr_fd(": is a directory\n", fd);
// 	close(fd);
// 	printt(n_file);
// 	free(r_file);
// 	unlink(n_file);
// 	free(n_file);
// }
