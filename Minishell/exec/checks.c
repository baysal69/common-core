#include "../minishell.h"

int redirect_type(t_token *head)
{
	if (head->token[0] == '>')
	{
		if (head->token[1] == '>')
			return 2;
		return 1;
	}
	else if (head->token[0] == '<')
	{
		if (head->token[1] == '<')
			return 4;
		return 3;
	}
	return 0;
}

t_token *check_redirect(t_token *head)
{
	while(head)
	{
		if (redirect_type(head) > 0)
		{
			return head;
		}
		head = head->next;
	}
	return NULL;
}

int count_redirect(t_token *head)
{
	int i = 0;
	while (head)
	{
		if (head->token[0] == '>')
			i++;
		head = head->next;
	}
	return i;
}

int check_nl(t_token *head) //handle "echo -n -n zbi"
{
	int i = 2, flag = 0;
	if (head->token[0] != '-' && head->token[1] != 'n')
		return 0;
	while(head->token[i])
	{
		if (head->token[i] != 'n')
			return 0;
		i++;
	}
	return 1;
}
