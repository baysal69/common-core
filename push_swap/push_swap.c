/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:15:42 by waissi            #+#    #+#             */
/*   Updated: 2025/04/18 01:34:57 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeing_both(t_list **a, t_list **b)
{
	ft_lstclear(a, del);
	free(a);
	ft_lstclear(b, del);
	free(b);
}

void	list_the_input(char *str, t_list **a, t_list **b)
{
	int		j;
	char	**a1;
	long	r;
	t_list	*node;

	a1 = ft_split(str, ' ');
	if (!a1 || !*a1)
		ft_error("Error\n", a, b, a1);
	j = 0;
	while (a1[j])
	{
		r = check_and_atoi(a1[j], a, b, a1);
		node = ft_lstnew(r);
		ft_lstadd_back(a, node);
		j++;
	}
	lookthedouble(a, b, a1);
	free_all(a1);
}

void	sorting(t_list **a, t_list **b)
{
	int	len;

	len = ft_lstsize(*a);
	if (!is_increase(a))
	{
		if (len <= 2)
			sa(a);
		else if (len == 3)
			sort_tree(a);
		else if (len <= 5)
			sort_20orless(a, b);
		else
			radix_sort(a, b);
	}
	freeing_both(a, b);
}

int	main(int ac, char **av)
{
	int		i;
	t_list	**b;
	t_list	**a;

	i = 1;
	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	if (!a || !b)
		ft_error("Error\n", a, b, NULL);
	*a = NULL;
	*b = NULL;
	if (ac >= 2)
	{
		while (i < ac)
			list_the_input(av[i++], a, b);
		sorting(a, b);
	}
	else
		freeing_both(a, b);
}
