CC 	= gcc

FLAGS 	= -Wall -Wextra -Werror

NAME 	= Client Server

SRV 	= Server 

CLT	= Client

SRC_SRV	= Server.c

SRC_CLT	= Client.c

PTF	= libftprintf.a

LBFT	= libft.a

PPTF	= ./ft_printf/libftprintf.a

PLBFT	= ./libft/libft.a

all	: $(SRV) $(CLT) $(PPTF) $(PLBFT)

$(SRV)	: Server.c $(PLBFT) $(PPTF) Minitalk.h
	cc $(FLAGS) server.c $(PPTF) $(PLBFT) -o $(SRV)

$(CLT) 	: Client.c $(PLBFT) $(PPTF) Minitalk.h
	cc $(FLAGS) Client.c $(PPTF) $(PLBFT) -o $(CLT)

clean:
	rm -rf 

fclean:
	rm -rf $(SRV) $(CLT)
	
re: fclean all

.PHONY: all clean fclean re $(PPTF) $(PLBFT)
