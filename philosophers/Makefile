NAME 	= philo

SRC	 	= philo.c utils.c states.c checks.c

OBJ 	= $(SRC:.c=.o)

#FLAGS 	= -Wall -Wextra -Werror

all 	: $(NAME)

$(NAME) : $(OBJ)
	cc $(FLAGS) $(SRC) -o $(NAME)

clean 	:
	rm -rf $(OBJ)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all

.PHONY 	: all clean fclean re