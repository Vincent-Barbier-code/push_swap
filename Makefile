CC = gcc
CFLAGS = #-Wall -Wextra -Werror -g #-fsanitize=address -g3
NAME = push_swap
INC_PATH = ./
SRC = push_swap.c error.c \
	list_utils.c list_utils1.c \
	swap.c push.c rotate.c rrotate.c \
	parsing.c small_case.c large_case.c \
	final_sort.c
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