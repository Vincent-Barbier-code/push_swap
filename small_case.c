/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:55:16 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/17 16:13:22 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_3(t_list **list)
{
	if ((*list)->content > (*list)->next->content \
		&& (*list)->content > (*list)->next->next->content)
	{
		if((*list)->next->content > (*list)->next->next->content)
			return (1);
		return (2);
	}
	if ((*list)->content < (*list)->next->content \
		&& (*list)->content < (*list)->next->next->content)
		return (3);
	if ((*list)->content < (*list)->next->content)
		return (4);
	else
		return (5);
}

void	sort_2_3(t_list **list)
{
	int	cas;
	
	if (len_list(list) == 2)
	{
		swap_a(list);
		return ;
	}
	cas = case_3(list);
	if (cas == 1)
	{
		swap_a(list);
		rra(list);
	}
	if (cas == 2)
		rotate_a(list);
	if (cas == 3)
	{
		swap_a(list);
		rotate_a(list);
	}
	if (cas == 4)
		rra(list);
	if (cas == 5)
		swap_a(list);
}
/*
void	sort_first_a(t_li **stack)
{
	int		first;
	t_li	*start;

	start = *stack;
	first = (*stack)->content;
	while ((*stack)->next)
	{
		if ((*stack)->next->content < first)
			op_sa(stack);
		*stack = (*stack)->next;
	}
	*stack = start;
}

void	sort_5(t_li **stack_a, t_li **stack_b)
{
	if (len_stack(*stack_a) < 5)
	{
		op_pb(stack_a, stack_b);
		sort_3(stack_a);
		op_pa(stack_a, stack_b);
		sort_first_a(stack_a);
		return ;
	}
	op_pb(stack_a, stack_b);
	op_pb(stack_a, stack_b);
	sort_3(stack_a);
	op_pa(stack_a,stack_b);
	sort_first_a(stack_a);
	op_pa(stack_a,stack_b);
	sort_first_a(stack_a);
}
*/	