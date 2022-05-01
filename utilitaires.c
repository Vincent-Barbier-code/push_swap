/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitaires.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:48:58 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/01 22:59:13 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        printf("nb = %d \n", current_node->content);
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
	{
		*list = new;
		return ;
	}
	new->next = *list;
	*list = new;
}

void	ft_lstadd_back_int(t_list **list, int nb)
{
	t_list	*new;
	t_list *tmp;

	new = ft_lstnew_int(nb);
	if (!new)
		return ;
	if(!list)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while ((tmp)->next)	
		tmp = (tmp)->next;
	(tmp)->next = new;
}

void	ft_clear(t_list **list)
{
	t_list	*tmp;

	if (!list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list));
		*list = tmp;
	}
}
