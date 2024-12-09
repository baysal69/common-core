NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_puthex.c \
		ft_putchar.c \
		ft_putaddr.c \

OBJS = $(SRCS:%.c=%.o)

CC = cc

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all