CC 	= gcc

FLAGS 	= -Wall -Wextra -Werror

NAME 	= Client Server

SRV 	= Server 

CLT	= Client

SRC_SRV	= Server.c

SRC_CLT	= Client.c

OBJ_SRV = $(SRC_SRV:.c=.o)

OBJ_CLT = $(SRC_CLT:.c=.o)

PTF	= libftprintf.a

LBFT	= libft.a

PPTF	= ./ft_printf/libftprintf.a

PLBFT	= ./libft/libft.a

all	: $(SRV) $(CLT) $(PPTF) $(PLBFT)

$(SRV)	: Server.c $(OBJ_SRV) $(PLBFT) $(PPTF) Minitalk.h
	cc $(FLAGS) $(OBJ_SRV) $(PPTF) $(PLBFT) -o $(SRV)

$(CLT) 	: Client.c $(OBJ_CLT) $(PLBFT) $(PPTF) Minitalk.h
	cc $(FLAGS) $(OBJ_CLT) $(PPTF) $(PLBFT) -o $(CLT)

%.o	: %.c Minitalk.h
	cc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_SRV) $(OBJ_CLT) 

fclean:
	rm -rf $(SRV) $(CLT)
	
re: fclean all

.PHONY: all clean fclean re $(PPTF) $(PLBFT)
