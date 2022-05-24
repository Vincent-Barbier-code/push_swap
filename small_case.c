/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:55:16 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/23 17:14:35 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_2(t_list **list)
{
	if (((*list)->content > (*list)->next->content))
		swap_a(list);
}

static int	whatcase_3(t_list **list)
{
	if ((((*list)->content > (*list)->next->content) && \
	((*list)->next->content) < (*list)->next->next->content) && \
	((*list)->content < (*list)->next->next->content))
		return (1);
	if (((*list)->content > (*list)->next->content) && \
	((*list)->next->content) > (*list)->next->next->content)
		return (2);
	if (((*list)->content > (*list)->next->content) && \
	((*list)->next->content) < (*list)->next->next->content)
		return (3);
	if ((((*list)->content < (*list)->next->content) && \
	((*list)->next->content) > (*list)->next->next->content) && \
	((*list)->content < (*list)->next->next->content))
		return (4);
	if ((((*list)->content < (*list)->next->content) && \
	((*list)->next->content) > (*list)->next->next->content) && \
	((*list)->content > (*list)->next->next->content))
		return (5);
	return (0);
}

void case_3(t_list **list)
{
	if (whatcase_3(list) == 1)
		swap_a(list);
	else if (whatcase_3(list) == 2)
	{
		swap_a(list);
		rra(list);
	}
	else if (whatcase_3(list) == 3)
		rotate_a(list);
	else if (whatcase_3(list) == 4)
	{
		swap_a(list);
		rotate_a(list);
	}
	else if (whatcase_3(list) == 5)
		rra(list);
}

void case_5(t_list **list_a, t_list **list_b)
{
	while (1)
	{
		if (max(list_a) == (*list_a)->content)
			rotate_a(list_a);
		if (len_list(list_a) == 3)
		{
			case_3(list_a);
			return ;	
		}
		else
			push_b(list_a, list_b);
	}
	
}
