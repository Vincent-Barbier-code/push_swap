PUSH_SWAP_H = -L./push_swap -lft
UTILITAIRES = utilitaires.c
OPERATIONS = operations.c
CC = gcc
FLAGS = -Wall -Wextra -Werror

all : operations

operations : $(OPERATIONS)
		$(CC) $(UTILITAIRES) $(OPERATIONS) -o utilitaires

#operations : $(OPERATIONS)
#		$(CC) $(OPERATIONS)  -o operations

.c.o :
		$(CC) $(FLAGS) -c -I 

fclean:
		rm -f utilitaires operations

re: 
	fclean all 

.PHONY: all clean fclean re
