/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:34:26 by waissi            #+#    #+#             */
/*   Updated: 2025/08/25 23:03:59 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_token
{
	char			*value;
	int				type;
	int				index;
	int				read;
	int				quote;
	int				fd;
	struct s_token	*next;
	struct s_token	*prev;
}					t_oken;

// mandatory
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_numvalid(const char *s);
size_t				ft_strlen(const char *s);
size_t				ft_arrlen(char **s);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
long				ft_atoi(const char *str);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strchr(const char *s, int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strcpy(char *d, char *s);
char				*ft_strreplace(char *s, int replace, int c);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strcspn(const char *s, const char *d);
void				*ft_calloc(size_t n, size_t size);
char				*ft_strdup(const char *str);
char				*ft_strndup(const char *s, size_t n);
char				**ft_split(char const *s, char c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strpbrk(const char *s, const char *accept);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strnstr(const char *h, const char *n, size_t l);
char				*ft_strjoin(char *s1, char *s2);
char				toggle(unsigned int i, char c);
size_t				ft_count_words(const char *s, char c);
void				ft_charneg(char *arr, size_t index);
char				*ft_itoa(int n);
int					get_num_len(long n);

// bonus
t_oken				*ft_lnew(char *value, int type, int index, t_oken *prev);
t_oken				*ft_lstlast(t_oken *token);
int					ft_lstsize(t_oken *token);
void				ft_lstclear(t_oken **lst);
void				ft_lstadd_front(t_oken **token, t_oken *new);
void				ft_lstadd_back(t_oken **token, t_oken *new);
void				ft_lstdelone(t_oken *lst);
void				ft_dellast(t_oken **lst);

// get_next_line

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char				*get_next_line(int fd);
size_t				ln_exists(char *buf);
size_t				ln_index(char *buf);
char				*join_string(char *line, char *buf);
char				*cutstr(char *s, unsigned int start, size_t len);
size_t				catnate(char *dst, char *src, size_t dstsize);

#endif
