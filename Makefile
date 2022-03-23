PUSH_SWAP_H = -L./push_swap -lft
#LIB = -L./ft_printf/ft_printf.h
#FT_PRINTF = -l./ft_printf/libftprintf.a
UTILITAIRES = utilitaires.c
OPERATIONS = operations.c
CC = gcc
FLAGS = -Wall -Wextra -Werror

all : operations

operations : $(OPERATIONS)
		$(CC)	$(UTILITAIRES) $(OPERATIONS) -o operations

#operations : $(OPERATIONS)
#		$(CC) $(OPERATIONS)  -o operations

.c.o :
		$(CC) $(FLAGS) -c -I 

fclean:
		rm -f operations

re: 
	fclean all 

.PHONY: all clean fclean re

#PUSH_SWAP_H = -L./push_swap -lft
FT_PRINTF = ./ft_printf/libftprintf.a
UTILITAIRES = utilitaires.c
OPERATIONS = operations.c
CC = gcc
FLAGS = -Wall -Wextra -Werror

all : operations

operations : $(OPERATIONS)
		$(CC)	$(UTILITAIRES) $(OPERATIONS) $(FT_PRINTF) -o operations

#operations : $(OPERATIONS)
#		$(CC) $(OPERATIONS)  -o operations

.c.o :
		$(CC) $(FLAGS) -c -I 

fclean:
		rm -f operations

re: 
	fclean all 

.PHONY: all clean fclean re

