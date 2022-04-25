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
        printf("%d", current_node->content);
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
	t_list	*new;

	new = ft_lstnew_int(nb);
	if (!new)
		return ;
	if (!list)
		*list = new;
	new->next = *list;
	*list = new;
}
// bug a regler sur ft_lst_add_back leak
void	ft_lstadd_back_int(t_list **list, int nb)
{
	t_list	*new;

	new = ft_lstnew_int(nb);
	if (!new)
		return ;
	if (!list)
		*list = new;
	while (*list)
		list++;
	new->next = *list;
	*list = new;
}

void	ft_clear(t_list **list)
{
	t_list	*tmp;

	if (!list)
		return ;
	while (*list)
	{
		//printf("p = %p \n", (*list));
		printf("n = %d \n", (*list)->content);
		tmp = (*list)->next;
		free((*list));
		list = &tmp;
	}
}
