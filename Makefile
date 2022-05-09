CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address -g3
NAME = push_swap
INC_PATH = ./
SRC = operations.c utilitaires.c push_swap.c
OBJ = $(SRC:.c=.o)
DEPS = push_swap.h Makefile

LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -I $(INC_PATH) -L ./ft_printf -lftprintf -o push_swap

$(OBJ) : $(INC_PATH)$(DEPS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH)
clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all fclean clean re