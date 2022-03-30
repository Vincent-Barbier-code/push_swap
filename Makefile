CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
NAME = push_swap
INC_PATH = ./

SRC =    operations.c utilitaires.c
OBJ = $(SRC:.c=.o)
INCLUDES = push_swap.h

LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a

all : $(NAME)

$(NAME) : $(OBJ)
  $(CC) $(CFLAGS) $^ -I $(INC_PATH) -L ./ft_printf -lftprintf -o push_swap

$(OBJ) : $(INC_PATH)$(INCLUDES)

%.o : %.c
    $(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH)
clean : 
    rm -f $(OBJ)

fclean : clean
    rm -f $(NAME)

re : fclean all

test : $(NAME)
    echo "" && ./a.out && echo ""

.PHONY : all fclean clean re exec test