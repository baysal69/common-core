/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:48:28 by waissi            #+#    #+#             */
/*   Updated: 2025/04/18 01:37:46 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_and_atoi(char *str, t_list **a, t_list **b, char **a1)
{
	int		i;
	long	r;

	r = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+')
			i++;
		else
			ft_error("Error\n", a, b, a1);
	}
	r = ft_atoi(str, a, b, a1);
	return (r);
}

void	del(void *content)
{
	free(content);
}

void	ft_error(char *msg, t_list **a, t_list **b, char **a1)
{
	ft_putstr_fd(msg, 2);
	free_all(a1);
	ft_lstclear(a, del);
	ft_lstclear(b, del);
	free(a);
	free(b);
	exit(1);
}

int	free_all(char **str_array)
{
	int	i;

	i = 0;
	if (str_array)
	{
		while (str_array[i] != NULL)
		{
			free(str_array[i]);
			i++;
		}
		free(str_array);
		return (0);
	}
	return (0);
}

void	lookthedouble(t_list **a, t_list **b, char **a1)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
			{
				ft_error("Error\n", a, b, a1);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
