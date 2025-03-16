CC     = cc

FLAGS     = -Wall -Wextra -Werror

NAME     = client server

NAME     = server 

CLT    = client

SRC_SRV    = server.c

SRC_CLT    = client.c

OBJ_SRV = $(SRC_SRV:.c=.o)

OBJ_CLT = $(SRC_CLT:.c=.o)

PTF    = libftprintf.a

LBFT    = libft.a

PPTF    = ./ft_printf/libftprintf.a

PLBFT    = ./libft/libft.a

all    : $(NAME) $(CLT)

$(NAME)    : $(OBJ_SRV) $(PLBFT) $(PPTF)
    cc $(FLAGS) $(OBJ_SRV) $(PPTF) $(PLBFT) -o $(NAME)

$(CLT)     : $(OBJ_CLT) $(PLBFT) $(PPTF)
    cc $(FLAGS) $(OBJ_CLT) $(PPTF) $(PLBFT) -o $(CLT)

%.o    : %.c
    cc $(FLAGS) -c $< -o $@

clean:
    rm -rf $(OBJ_SRV) $(OBJ_CLT) 

fclean: clean
    rm -rf $(NAME) $(CLT)
    
re: fclean all

.PHONY: all clean fclean re
