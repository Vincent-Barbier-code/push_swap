/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:31:48 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/17 17:47:30 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **list)
{
	t_list	*cp_list;
	t_list	*prems;

	if (!*list)
		return ;
	cp_list = *list;
	prems = *list;
	*list = prems->next;
	(*list)->previous = NULL;
	while (cp_list->next)
		cp_list = cp_list->next;
	cp_list->next = prems;
	prems->next = NULL;
	prems->previous = cp_list;
}

void	rotate_a(t_list **list_a)
{
	rotate(list_a);
	ft_printf("ra\n");
}

void	rotate_b(t_list **list_b)
{
	rotate(list_b);
	ft_printf("rb\n");
}

void	rr(t_list **list_a, t_list **list_b)
{
	rotate(list_a);
	rotate(list_b);
	ft_printf("rr\n");
}
