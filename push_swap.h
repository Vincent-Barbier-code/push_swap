#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "./ft_printf/ft_printf.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

void	print(t_list **list);
t_list	*ft_lstnew_int(int nb);
void	ft_lstadd_front_int(t_list **list, int nb);
void	ft_clear(t_list **lst);

//void	swap_a

#endif
