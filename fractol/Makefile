CC     = cc

FLAGS     = -Wall -Wextra -Werror -g

NAME     = fractol

SRC   = fractol2.c utils.c

OBJ = $(SRC:.c=.o)

PTF    = libftprintf.a


PPTF    = ../ft_printf/libftprintf.a


all    : printf $(NAME) 

$(NAME)    : $(OBJ) $(PPTF) fractol.h
	cc  $(FLAGS) $(OBJ) $(PPTF) /usr/include/minilibx-linux/libmlx.a -lX11 -lXext -lm -Wall -Wextra -Werror -g -o $(NAME)

printf	:
	@make -C ../ft_printf

%.o    : %.c 
	cc $(FLAGS) -c $< -o $@

clean:
	@make clean -C ../ft_printf
	rm -rf $(OBJ) 

fclean: clean
	@make fclean -C ../ft_printf
	rm -rf $(NAME)

re: fclean all

.SECONDARY: $(OBJ)

.PHONY: all clean fclean re
