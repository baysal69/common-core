NAME	= test
SRC_1	= minishell.c utils_lst.c checks.c
SRC_2	= minishell2.c utils_lst.c checks.c
OBJ_1	= $(SRC_1:.c=.o)
OBJ_2	= $(SRC_2:.c=.o)
LBFT	= ./libft/libft.a

1	: $(OBJ_1)
	cc $(OBJ_1) $(LBFT) -o $(NAME) -g
2	: $(OBJ_2)
	cc $(OBJ_2) $(LBFT) -o $(NAME) -g
%.o	: %.c
	cc -c $< -o $@ -g
clean	: 
	rm -rf $(OBJ_1) $(OBJ_2)
fclean 	: clean
	rm -rf $(NAME)
