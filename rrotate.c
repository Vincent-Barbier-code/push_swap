/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:33:36 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/23 17:05:54 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **list)
{
	t_list	*cp_list;
	t_list	*der;

	if (!*list)
		return ;
	cp_list = *list;
	while (cp_list->next->next)
		cp_list = cp_list->next;
	der = cp_list->next;
	(*list)->previous = der;
	der->next = *list;
	cp_list->next = NULL;
	der->previous = NULL;
	(*list) = der;
}

void	rra(t_list **list_a)
{
	reverse_rotate(list_a);
	ft_printf("rra\n");
}

void	rrb(t_list **list_b)
{
	reverse_rotate(list_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **list_a, t_list **list_b)
{
	reverse_rotate(list_a);
	reverse_rotate(list_b);
	ft_printf("rrr\n");
}
