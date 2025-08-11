NAME 	= philo
SRC	 	= philo.c life.c utils.c states.c checks.c inits.c clean.c
OBJ 	= $(SRC:.c=.o)
CC 		= cc -fsanitize=undefined -pthread
CFLAGS	= -Wall -Wextra -Werror

all 	: $(NAME)

$(NAME) : $(OBJ)
		@$(CC) $(CFLAGS)  $(OBJ) -o $(NAME)
		@echo " ╰┈➤$(NAME) is ready"

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null

clean :
		@rm -f $(OBJ)
		@echo " ╰┈➤object files got cleaned"

fclean	: clean
		@rm -rf $(NAME)
		@echo " ╰┈➤./$(NAME) got cleaned"

re	: fclean all

.PHONY 	: all clean fclean re
