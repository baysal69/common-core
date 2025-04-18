NAME = push_swap

B_NAME = checker_aaf

RM = rm -rf

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.
SRCS = push_swap.c sorting.c ranking.c on_the_top.c the_algorithm.c \
	op_s.c op_r.c op_rr.c op_p.c \
	ft_split.c list_function.c errors.c libft.c errors2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c  $< -o $@
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean
