/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:59:57 by waissi            #+#    #+#             */
/*   Updated: 2025/08/25 00:29:34 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

# define ARGS 0    // arguments
# define PIPE 1    // "|"
# define CMD 2     // command
# define OUTPUT 3  // ">"
# define INPUT 4   // "<"
# define APPEND 5  // ">>"
# define HEREDOC 6 // "<<"
# define END 7     // ""
# define EMPTY 8   // empty expansoin
# define MPT 9     // empty expansoin

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define EXIT_SUCCESS 0
# define EXIT_ERROR 2
# define SIGSPECIAL 1337

// error type def
# define CTRL_C 130        // ctrl c
# define MISS_USAGE 1      // wrong usage of command
# define ERR_EXECUTE 126   // command invoked cannot execute
# define ERR_SIGFAULT 139  // segmentation fault
# define CMD_NOT_FOUND 127 // comand not found

// error custom
# define ERR_SYNTAX 258 // syntax error

# define ONEKB 1024          // 1KB
# define BUFFER_SML 40960    // 40KB
# define BUFFER_BIG 10485760 // 10MB
# define CMD_MAX_LENGTH 1024

// ANSI color codes for ayu dark theme
# define COLOR_BLUE "\033[0;34m"  // Blue
# define COLOR_GREEN "\033[0;92m" // Bright green
# define COLOR_RED "\033[0;91m"   // Bright red
# define COLOR_RESET "\033[0m"    // Reset color
# define BOLD_ON "\e[1m"
# define BOLD_OFF "\e[m"

typedef struct s_tree
{
	char			*op;
	char			*file_name;
	struct s_tree	*left;
	struct s_tree	*right;
	int				type;
	int				fd;
	int				index;
}					t_tree;

typedef struct s_herdoc
{
	int				herdoc;
	char			**line;
	int				fd;
}					t_herdoc;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_shell
{
	char			*s;
	t_env			*nv;
	char			**av;
	int				*type;
	int				status;
	int				fd;
	int				err;
	int				len;
	int				begin;
	int				end;
	int				i;
	t_herdoc		*herdoc;
	t_tree			*tree;
	t_tree			*tree_copy;
	t_oken			*token;
	t_oken			*t;
	int				r_fd;
	int				i_fd;
	char			**env;
	char			*export_error;
	int				st;
	t_oken			*tmp;
	pid_t			pid;
	pid_t			pid2;
	int				d_change;
	int				has_pipe;
	int				pipe_count;
	char			*name_list[1000];
	int				allow;
}					t_shell;

typedef struct s_var
{
	int				i;
	int				j;
	int				has_pipe;
	int				has_rederect;
	int				has_herd;
	char			**av;
	char			*cmd_path;
	int				value_len;
	int				key_len;
	char			**env;
	int				size;
	pid_t			pid;
	char			*cpy_av[CMD_MAX_LENGTH];
	char			*cpy_env[CMD_MAX_LENGTH];
	char			*cpy_cmd_path;
	int				len;
	int				check;
	char			*key;
	int				begin;
	int				end;
	int				area_len;
}					t_var;

// -- main -- //
void				init(t_shell **shell, int ac, char **av, char **nv);
void				init_env(t_shell **shell, char **nv);
void				handle_signals(int sig);
void				free_all(t_shell *shell);
void				free_nv(t_env **env);
void				free_av(char ***av);
int					error(void *ptr, t_shell *shell);
char				*var(char *s, t_env *nv);
char				*get_next_line(int fd);
void				handle_signals(int sig);
void				heredoc_signals(int sig);
// -- parsing -- //
void				parse(t_shell *shell);
void				spacing(t_shell *shell);
void				lexer(t_shell *shell);
void				valid(t_shell *shell);
void				expand(t_shell *shell);
void				token(t_shell *shell, char **str);
void				squish(t_shell *shell);

//--- parse utils ----//
char				*get_env(t_env *nv, char *key);
int					metachar(char c);
int					getcount(char *s);
int					inquotes(char *s, int i, int x);
int					metachar(char c);
char				*var(char *s, t_env *nv);
size_t				len_av(char **av);
//---execution---//
int					execute(t_shell *shell);
int					ft_size(char **av);
void				ft_found(t_shell *shell, t_var *var, int start, int end);
void				ft_free_tree(t_tree *root);
void				executing(t_shell *shell);
int					is_rederaction(char *c);
char				*ft_strcat(char *dest, char *src);
char				*ft_strcpy(char *dest, char *src);
char				*creating_cmd_path(int len, char **path_split, int i,
						char *av);
void				s_free(char **av);
int					check_cmd(t_shell *shell);
int					is_rederaction(char *c);
char				**creat_env(t_env *nv);
void				lazy_free(char **env, int i);
int					env_size(t_env *nv);
void				ft_exec_rederect(t_shell *shell);
void				ft_pipe(t_shell *shell);
int					is_herd(char *c);
void				ft_exec_rederect_herd(t_shell *shell, int j);
void				ft_str_cpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
void				free_herdoc(t_shell *shell, t_herdoc *herdoc);
t_oken				*creat_token(t_oken *tokens, t_oken *last_redirection);
t_tree				*creat_tree_pipe(t_shell *shell, t_oken *tokens,
						t_oken *last_red_p);
void				ft_free_token(t_oken *token);
int					set(t_oken *token);
void				process_export_entry(char *entry, t_shell *shell,
						int *check);
void				handle_export_error(void);
void				print_env(t_shell *shell);
int					is_space(char c);
void				create_env(char *key, char *value, t_shell *shell, int i);
void				update_existing_env(t_env *env, char *value, int i,
						char *key);
void				found_key(t_shell *shell, char *key);
void				update_paths(t_shell *shell, char *past_path);
void				handle_home_directory(t_shell *shell);
void				change_directory(t_shell *shell, char *path, char **av);
void				update_env(t_env *nv, char *key, char *value);
char				*get_env_cd(t_env *nv, char *key);
void				exit_pipe(t_shell *shell);
void				handle_exit_too_many_args(void);
void				handle_exit_numeric(t_shell *shell);
size_t				overfl(int g_exit_status);
int					is_numeric(char *str);
void				ft_exec_rederect_herd(t_shell *shell, int j);
void				redirect_output(t_shell *shell, int fd, int i);
int					open_file_for_writing(char *file_name);
void				handle_open_error(void);
void				handle_left_subtree(t_shell *shell, t_tree *root,
						t_oken *tokens, t_oken *last_r_pip);
t_tree				*creat_node(t_oken *token, char *file_name, int fd);
t_oken				*creat_token(t_oken *tokens, t_oken *last_redirection);
t_oken				*last_p_r(t_shell *shell, t_oken *tokens);
t_oken				*find_last_redirection(t_oken *tokens);
t_oken				*find_last_pipe(t_shell *shell, t_oken *tokens);
t_oken				*find_next_token(t_oken *current);
int					pipe_count(t_oken *token);
t_herdoc			*s(int i);
char				*check_access(char **path_split, char *av);
char				**get_path_split(void);
char				*find_cmd_path(char **av, t_env *nv);
void				free_av1(char **av);
char				**cmd_maker(t_shell *shell);
void				handle_exec_error(t_var *var, t_shell *shell, int i);
void				count_tree_nodes(t_tree *tree, int *count);
char				**av_m(t_shell *shell);
int					already_exist(char *key, t_shell *shell);
void				free_keys(char *key, char *value);
int					type_check(t_tree *tree);
int					check_directory(t_var *var, t_shell *shell);
int					is_space(char c);
char				*random_name_gen(void);
void				unlinker(t_shell *shell);
void				set_file(t_shell *shell);
void				_reset(t_oken *token);
int					set_up_file_name(t_shell *shell, int range);
int					check_is_dir_path(char *path);
void				for_norminet(t_var *var, t_shell *shell);
int					isnt_red(int type, int i);
int					creat_fd_2(char *file_name, int i);
int					file_creation(t_oken *t);
int					checks_err(t_shell *shell);
t_oken				*return_tmp(t_shell *shell);
// -- built in -- //
void				ft_exit(t_shell *shell, int i, int j);
void				free_all_shell(t_shell *shell, int i);
void				echo(t_shell *shell);
void				cd(t_shell *shell);
void				env(t_shell *shell);
void				pwd(t_shell *shell);
void				export(t_shell *shell);
void				unset(t_shell *shell);
int					creat_fd_2(char *file_name, int i);
void				nothing(t_oken *t);
void				handle_child_termination(int status);
void				ambiguous_error(char *str);
void				print_err(char *str, int i);
void				open_error(char *str);

// new
void				change_signals(int type);
void				readline_mode(int sig);
void				run_mode(int sig);
void				heredoc_mode(int sig);
int					validate(char *s, t_shell *shell);
t_tree				*create_tree(t_shell *shell, t_oken *tokens);
t_tree				*creat_tree_red(t_shell *shell, t_oken *tokens,
						t_oken *last_r_pip);
void				handle_right_subtree(t_shell *shell, t_tree *root,
						t_oken *last_r_pip);
t_tree				*create_simple_tree(t_shell *shell, t_oken *tokens);
int					creat_fd(t_shell *shell, int range, int reset);
void				heredoc_warning(t_shell *shell, int i);

extern int			g_exit_status;
#endif
