#include "../minishell.h"

void append_file(t_token *head, char *s, int flag)  // append ">>"
{
	t_token *tmp;
	int fd;
                tmp = check_redirect(head);
		if (tmp)
		{
			fd = open(tmp->next->token, O_CREAT | O_RDWR | O_APPEND, 0644);
			ft_putstr_fd(s,fd);
			if (!flag)
                        	ft_putstr_fd("\n",fd);
                }
		head = head->next;
}

void echo_file(t_token *head, char *s, int flag)  // input '>'
{
	t_token *tmp;
	int fd;
	while (head)
        {
                tmp = check_redirect(head);
		if (tmp)
		{
			fd = open(tmp->next->token, O_CREAT | O_RDWR | O_TRUNC, 0644);
			ft_putstr_fd(s,fd);
			head = head->next;
			if (!flag)
                        	ft_putstr_fd("\n",fd);
                }
		head = head->next;
	}
}

int token_len(t_token *head)
{
	int i = 0, ttl = 0;
	while(head && head->token[0] != '>' && head->token[0] != '<' )
	{
		while (head->token[i])
			i++;
		head = head->next;
		ttl += i +1;
	}
	return ttl;
}

int redirect_occur(t_token *head, t_token *word,char *s,int nl_flag)
{
	t_token *tmp = head;

        if (word && (redirect_type(word) == 1))
        {
                while (tmp != word)
                {
                        ft_strcat(s, tmp->token);
                        if (tmp->next != word)
                                ft_strcat(s," ");
                        tmp = tmp->next;
                }
                echo_file(head,s,nl_flag);
		return 1;
        }
        else if (word && (redirect_type(word) == 2))
        {
                while (tmp != word)
                {
                        ft_strcat(s, tmp->token);
                        if (tmp->next != word)
                                ft_strcat(s," ");
                        tmp = tmp->next;
                }
                append_file(head,s,nl_flag);
		return 1;
        }	
	return 0;
}

void echo(t_token *head)
{
	if (!head)
	{
		printf("invalid\n");
		return;
	}
	//	int count;
	char *s = malloc(token_len(head));
	s[0] = '\0';
	t_token *word;
	int nl_flag;

	nl_flag = check_nl(head);
//	count = count_redirect(head);
	word = check_redirect(head);
	if (nl_flag)
		head = head->next;
	if (word)
	{
		redirect_occur(head,word,s,nl_flag);
	}
	else
	{
   		while (head)
		{
				
       	 		printf("%s", head->token);
       	 		if (head->next)
            			putchar(' ');
        		head = head->next;
		}
		if (nl_flag == 0)	
    			putchar('\n');
    	}
	free(s);
}
void pwd(t_token *head) // should accept no arguments
{
	char *s;
       	s = getcwd(NULL,0); // protect this
	t_token *word = check_redirect(head);
	if (word)
	{
		if (redirect_type(word) == 1)
			echo_file(head,s,0);
		else if (redirect_type(word) == 2)
			append_file(head,s,0);
	}
	else
		printf("%s\n",s);
}

void cd(t_token *head)
{
	if (head->next == NULL)
	{
		char *user = getenv("USER"); //protect this malloc
		char *path = malloc(7 + ft_strlen(user)); // this too
		ft_strcpy(path,"/home/");
		strcat(path,user); //do ft_strcat
		chdir(path);
	}
	else
		head = head->next;
	if(chdir(head->token))
		printf(RED"Invalid director or path isn't relative or absolute\n"RESET);
}

int executable(t_token *head)
{
	char *prog_name = malloc(ft_strlen(head->token) * 999);	// protecc
	int i = 0, j = 1;
	char **path = ft_split(getenv("PATH"),':');
	char **args;
       	args = malloc (token_len(head));
	t_token *tmp = head;
	while(tmp)
	{
		args[j] = strdup(tmp->token);
		//printf("%s\n",args[j]);
		tmp = tmp->next;
		j++;
	}
	while(path[i])
	{
		strcpy(prog_name, path[i]);
		ft_strcat(prog_name,"/");
		ft_strcat(prog_name,head->token);
	//	printf("%s\n",prog_name);
		if (!access(prog_name, X_OK))
		{
			int pid = fork();
			if (pid == 0)
			{
				execve(prog_name,args,NULL);
				exit(0);
			}
			else
			{
				wait(NULL);
				break;
			}
		}
		i++;
	}
	if (!path[i])
		printf("command not found\n");
	i = 0;

}
void check_command(t_token *head)
{
	if (!strcmp(head->token, "echo")) //do strcmp ra makinach f libft
	{
		head = head->next;
		echo(head);
	}	
	else if (!strcmp(head->token, "pwd"))
		pwd(head);
	else if (!strcmp(head->token, "cd"))
		cd(head);
	else
		//printf("invalid command\n");
		executable(head);
}
/*
int main(void)
{
	t_token *tk1 = lst_new("-n");
	t_token *tk2 = lst_new("bibo");
	t_token *tk3 = lst_new("a");
	t_token *tk4 = lst_new("kbir.txt");
	t_token *tk5 = lst_new("a");
	t_token *tk6 = lst_new("w.txt");
	t_token *tk7 = lst_new(">");
	t_token *tk8 = lst_new("kbiiiiir.txt");
	t_token *tk9 = lst_new(">");
	t_token *tk10 = lst_new("mn.txt");

	tk1->next = tk2;
	tk2->next = tk3;
	tk2->prev = tk1;
	tk3->next = tk4;
	tk3->prev = tk2;
	tk4->next = tk5;
	tk4->prev = tk3;
	tk5->next = tk6;
	tk5->prev = tk4;
	tk6->prev = tk5;
	tk6->next = tk7;
	tk7->next = tk8;
	tk7->prev = tk6;
	tk8->next = tk9;
	tk8->prev = tk7;
	tk9->next = tk10;
	tk9->prev = tk8;
	tk10->prev = tk9;

	echo(tk1);
}
*/
