/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:16:37 by waissi            #+#    #+#             */
/*   Updated: 2025/04/18 01:35:17 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				rank;
	int				position;
	struct s_list	*next;
}	t_list;

int		get_max(t_list **stack);
void	radix_sort(t_list **stack_a, t_list **stack_b);
char	**ft_split(char const *s, char c);
void	chunk_sort(t_list **a, t_list **b);
void	on_top_a(t_list **a, t_list **b, t_list *node);
void	on_top_b(t_list **a, t_list **b, t_list *node);
void	positioning(t_list **a);
void	ranking(t_list **a);
void	on_top(t_list **a, t_list **b, t_list *node);
t_list	*get_the_one(t_list *a, int i);
void	sort_tree(t_list **ab);
void	sort_20orless(t_list **a, t_list **b);
int		is_increase(t_list **ab);
void	push(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	reverse_rotation(t_list **ab);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	rotation(t_list **ab);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	ft_swap(t_list **ab);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *nptr, t_list **a, t_list **b, char **a1);
void	check_the_sign(const char *str, t_list **a, t_list **b, char **a1);
void	del(void *content);
void	lookthedouble(t_list **a, t_list **b, char **a1);
void	ft_error(char *msg, t_list **a, t_list **b, char **a1);
int		check_and_atoi(char *str, t_list **a, t_list **b, char **a1);
int		free_all(char **str_array);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);

#endif
