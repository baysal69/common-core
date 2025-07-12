NAME 	= philo

SRC	 	= philo.c utils.c states.c checks.c inits.c

OBJ 	= $(SRC:.c=.o)

#FLAGS 	= -Wall -Wextra -Werror -fsanitize=thread -g
# FLAGS 	= -fsanitize=thread -g

all 	: $(NAME)

$(NAME) : $(OBJ)
	cc $(FLAGS)  $(SRC) -o $(NAME) -g

clean 	:
	rm -rf $(OBJ)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all

.PHONY 	: all clean fclean re
