FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_printf.c
OBJT = $(SRC:.c=.o)
HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJT)
	ar -rcs $(NAME) $(OBJT)
%.o: %.c ft_printf.h
	cc $(FlAGS) -c $< -o $@
clean:
	rm -rf $(OBJT)
fclean: clean
	rm -rf $(NAME)
re: fclean all



.PHONY: all clean fclean re
