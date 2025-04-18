/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:31:09 by waissi            #+#    #+#             */
/*   Updated: 2025/04/18 01:38:10 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (lst)
	{
		tmp = lst;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		return (tmp);
	}
	return (NULL);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (*alst == NULL)
		*alst = new;
	else
	{
		temp = ft_lstlast(*(alst));
		temp->next = new;
	}
}
