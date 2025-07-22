NAME	= test
SRC_1	= minishell.c ./exec/minishell2.c ./exec/utils_lst.c ./exec/checks.c
OBJ_1	= $(SRC_1:.c=.o)

all	: $(NAME)

$(NAME)	: $(OBJ_1) minishell.h
	cc $(OBJ_1) ./exec/libft/libft.a -o $(NAME) -g -lreadline
%.o	: %.c
	cc -c $< -o $@ -g
clean	: 
	rm -rf $(OBJ_1) $(OBJ_2)
fclean 	: clean
	rm -rf $(NAME)
re	: fclean all
