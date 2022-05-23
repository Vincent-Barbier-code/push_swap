/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:30:52 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/23 17:07:56 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;

	if (!*list_b)
		return ;
	if (!*list_a)
		*list_a = ft_lstnew_int((*list_b)->content);
	else
		ft_lstadd_front_int(list_a, (*list_b)->content);
	tmp = (*list_b)->next;
	if (len_list(list_b) == 1)
	{
		ft_clear(list_b);
	}
	else
		free(*list_b);
	*list_b = tmp;
	if (tmp)
		(*list_b)->previous = NULL;
}

void	push_a(t_list **list_a, t_list **list_b)
{
	push(list_a, list_b);
	ft_printf("pa\n");
}

void	push_b(t_list **list_a, t_list **list_b)
{
	push(list_b, list_a);
	ft_printf("pb\n");
}
