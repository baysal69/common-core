#ifndef MINISHELL_H
#define MINISHELL_H

#include "./exec/libft/libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

typedef struct s_token
{
	char *token;
	char *label;
	struct s_token *next;
	struct s_token *prev;
} t_token;

t_token *lst_new (const char *text);
t_token  *lst_last(t_token *lst);
t_token *check_redirect(t_token *head);
int count_redirect(t_token *head);
int check_nl(t_token *head);
int redirect_type(t_token *head);
int redirect_occur(t_token *head, t_token *word,char *s,int nl_flag);
void echo_file(t_token *head, char *s,int flag);
void append_file(t_token *head, char *s, int flag);
void echo(t_token *head);
int token_len(t_token *head);
void pwd(t_token *head);
void check_command(t_token *head);
#endif
