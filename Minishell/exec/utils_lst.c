#include "../minishell.h"

t_token *lst_new (const char *text)
{
	t_token *node = malloc(sizeof(t_token));
	if (!node)
		exit(1);
	node->token = strdup(text);
	node->next = NULL;
	node->prev = NULL;
	return node;
}

t_token  *lst_last(t_token *lst)
{
        t_token  *tmp;

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
