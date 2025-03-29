CC     = cc

FLAGS     = -Wall -Wextra -Werror -g

NAME     = client server

SRV     = server 

CLT    = client

SRC_SRV    = server.c

SRC_CLT    = client.c

OBJ_SRV = $(SRC_SRV:.c=.o)

OBJ_CLT = $(SRC_CLT:.c=.o)

PTF    = libftprintf.a


PPTF    = ./ft_printf/libftprintf.a


all    : printf $(SRV) $(CLT) 

$(SRV)    : $(OBJ_SRV) $(PPTF) Minitalk.h
	cc  $(FLAGS) $(OBJ_SRV) $(PPTF) -o $(SRV)

$(CLT)     : $(OBJ_CLT) $(PPTF) Minitalk.h
	cc $(FLAGS) $(OBJ_CLT) $(PPTF) ft_atoi.c -o $(CLT)

printf	:
	@make -C ./ft_printf

%.o    : %.c 
	cc $(FLAGS) -c $< -o $@

clean:
	@make clean -C ./ft_printf
	rm -rf $(OBJ_SRV) $(OBJ_CLT) 

fclean: clean
	@make fclean -C ./ft_printf
	rm -rf $(SRV) $(CLT)

re: fclean all

.SECONDARY: $(OBJ_CLT) $(OBJ_SRV)

.PHONY: all clean fclean re
