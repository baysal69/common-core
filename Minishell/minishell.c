#include "minishell.h"

t_token	*create_token(char *token)
{
	t_token	*node1;

	node1 = (t_token *)malloc(sizeof(t_token));
	if (!node1)
		return (NULL);
	node1->token = token;
	node1->next = NULL;
	//printf("$%s\n", node1->token);
	return node1;
}

t_token	*ft_lstlast(t_token *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	insert_token(t_token **lst, t_token *new)
{
	t_token *last;

	if (!lst || !new)
		return ;
	last = ft_lstlast(*lst);
	if (*lst)
	{
		last->next = new;
		new->prev = last;
	}
	else
		*lst = new;
}

int	count_input(char *input)
{
	int i;
	int k;
	int l;
	char countspace;
	
	countspace = 0;
	i = 0;
	k = 1;
	l = 0;
	while(input[i])
	{
		if(input[i] == '\"')
		{
			l++;
		}
		if(input[i] == ' ' && countspace)
		{
			k++;
			countspace = 0;
			while(input[i] == ' ')
				i++;
		}
		else
		{
			countspace = 1;
			i++;
		}
	}
	if(i == 0 || input[--i] == ' ')
		k--;
	l /= 2;
	return k + l;
}


void do_absolutely_nothing()
{
	//nothing
}

t_token **split_input(char *input)
{
	int i;
	int j;
	int k;
	char *tmp;
	t_token *head;
	t_token **heads;

	i = 0;
	j = 0;
	k = count_input(input);
	head = NULL;
	while(k--)
	{
		tmp = malloc(ft_strlen(input));
		while(input[i] && input[i] == ' ')
			i++;
		j = 0;
		while(input[i] && input[i] != ' ')
		{
			if(input[i] == '\'')
                        {
                                tmp[j++] = input[i++];
                                if(input[i] == '\'')
                                {
                                        i++;
                                        break;
                                }
                                while(input[i] && input[i] != '\'')
                                        tmp[j++] = input[i++];
                                if(input[i] && input[i] == '\'')
                                        tmp[j] = '\'';
                                if(input[++i] && input[i] == '\'')
                                {
                                        k++;
                                        j++;
                                        break;
                                }
                                if(input[i] && input[i] == ' ')
                                        tmp[++j] = ' ';
                                else
                                        i--;
                                if(input[++i] && input[i] != ' ' && input[i] != '\'')
                                {
                                        j++;
                                        break;
                                }
                                else
                                        i--;
                                if(tmp[j] == ' ')
                                {
                                        j++;
                                }
                        }
			if(input[i] == '\"')
			{
				tmp[j++] = input[i++];
				if(input[i] == '\"')
				{
					i++;
					break;
				}
				while(input[i] && input[i] != '\"')
					tmp[j++] = input[i++];
				if(input[i] && input[i] == '\"')
					tmp[j] = '\"';
				if(input[++i] && input[i] == '\"')
                                {
					k++;
					j++;
					break;
                                }
				if(input[i] && input[i] == ' ')
					tmp[++j] = ' ';
				else
					i--;
				if(input[++i] && input[i] != ' ' && input[i] != '\"')
				{
					j++;
					break;
				}
				else
					i--;
				if(tmp[j] == ' ')
				{
					j++;
				}
			}
			else
			{
				tmp[j++] = input[i++];
				if(input[i] && input[i] == '\"')
				{
					k++;
					break;
				}
			}
		}
		tmp[j] = '\0';
		if((tmp[0] == '\"' && tmp[1] == '\0') || (tmp[0] == '\'' && tmp[1] == '\0'))
			do_absolutely_nothing();	
		else
			insert_token(&head, create_token(tmp));
	}
	heads = &head;
	return heads;
}

int unclosed_quotes(char *input)
{
	int i;
	int d_count;
	int s_count;
	
	s_count = 0;
	d_count = 0;
	i = 0;
	while(input[i])
	{
		if(input[i] == '\"')
		{
			i++;
			d_count++;
			while(input[i] && input[i] != '\"')
				i++;
			if(input[i])
				d_count++;
			else
				return (0);
		}
		if(input[i] == '\'')
                {
			i++;
                        s_count++;
                        while(input[i] && input[i] != '\'')
                                i++;
                        if(input[i])
			       	s_count++;
                        else
                                return (0);
                }
		i++;
	}
	if(s_count || d_count)
	{
		if(((s_count % 2) != 0) || ((d_count % 2) != 0))
			return (0);
	}
	return (1);
}

int main()
{
	char *input;
	t_token **head;

	while(1)
	{
		input = readline(RED"➜  "RESET CYAN"~ "RESET);
		add_history(input);
		if(*input)
		{
			if(!unclosed_quotes(input))
			{
				printf("unclosed quotes\n");
				return 0;
			}
			head = split_input(input);
			check_command(*head);
			//break;
		}
	}
	//printf("%s\n", (*head)->next->token);
}
