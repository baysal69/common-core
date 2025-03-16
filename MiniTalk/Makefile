CC 	= gcc

FLAGS 	= -Wall -Wextra -Werror

NAME 	= client server

SRV 	= server 

CLT	= client

SRC_SRV	= server.c

SRC_CLT	= client.c

OBJ_SRV = $(SRC_SRV:.c=.o)

OBJ_CLT = $(SRC_CLT:.c=.o)

PTF	= libftprintf.a

LBFT	= libft.a

PPTF	= ./ft_printf/libftprintf.a

PLBFT	= ./libft/libft.a

all	: $(SRV) $(CLT) $(PPTF) $(PLBFT)

$(SRV)	: server.c $(OBJ_SRV) $(PLBFT) $(PPTF) Minitalk.h
	cc $(FLAGS) $(OBJ_SRV) $(PPTF) $(PLBFT) -o $(SRV)

$(CLT) 	: client.c $(OBJ_CLT) $(PLBFT) $(PPTF) Minitalk.h
	cc $(FLAGS) $(OBJ_CLT) $(PPTF) $(PLBFT) -o $(CLT)

%.o	: %.c Minitalk.h
	cc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_SRV) $(OBJ_CLT) 

fclean:
	rm -rf $(SRV) $(CLT)
	
re: fclean all

.PHONY: all clean fclean re $(PPTF) $(PLBFT)
