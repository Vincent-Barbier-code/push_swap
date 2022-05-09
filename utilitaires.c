/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitaires.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:48:58 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/09 16:41:37 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Print all the elements in the linked list */
void print(t_list **list)
{
	t_list *current_node;
	
	if (!*list)
		return;
	current_node = *list;
   	while (current_node != NULL) 
	{

		// if (!(current_node->previous == NULL))
		// 	ft_printf("previous content = %d \n", current_node->previous->content);
        ft_printf("nb = %d \n", current_node->content);
        current_node = current_node->next;
    }
}

int	len_list(t_list **list)
{
	int		i;
	t_list	*copy;
	
	i = 0;
	if (!*list)
		return (-1);
	copy = *list;
   	while (copy) 
	{
        i++;
		//ft_printf("OK %d \n",copy->content);
        copy = copy->next;
    }
	return (i);
}

t_list	*ft_lstnew_int(int nb)
{
	t_list	*listnew;

	listnew = (t_list *)malloc(sizeof(t_list));
	if (!listnew)
		return (NULL);
	listnew->content = nb;
	listnew->next = NULL;
	listnew->previous = NULL;
	return (listnew);
}

void	ft_lstadd_front_int(t_list **list, int nb)
{
	t_list	*new;

	new = ft_lstnew_int(nb);
	if (!list)
	{
		*list = new;
		return ;
	}
	new->next = *list;
	new->next->previous = new;
	*list = new;
}

void	ft_lstadd_back_int(t_list **list, int nb)
{
	t_list	*new;
	t_list	*tmp;

	new = ft_lstnew_int(nb);
	if(!list)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while ((tmp)->next)	
		tmp = (tmp)->next;
	tmp->next = new;
	new->previous = tmp;
}

void	ft_clear(t_list **list)
{
	t_list	*tmp;

	if (!list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}
