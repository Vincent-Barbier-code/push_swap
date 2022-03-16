#include "push_swap.h"

/* Print all the elements in the linked list */
void print(t_list **list)
{
	t_list *current_node;
	if (!list)
		return;
	current_node = *list;
   	while (current_node != NULL) 
	{
        printf("%d ", current_node->content);
        current_node = current_node->next;
    }
}

t_list	*ft_lstnew_int(int nb)
{
	t_list	*listenew;

	listenew = (t_list *)malloc(sizeof(t_list));
	if (!listenew)
		return (NULL);
	listenew->content = nb;
	listenew ->next = NULL;
	return (listenew);
}

void	ft_lstadd_front_int(t_list **list, int nb)
{
	t_list *new;

	new = ft_lstnew_int(nb);
	if (!new || !*list)
		return ;
	new->next = *list;
	*list = new;
}

void	ft_clear(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst));
		(*lst) = tmp;
	}
}
