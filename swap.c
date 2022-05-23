/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:30:04 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/23 17:05:24 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list)
{
	int	cpnb1;
	int	cpnb2;

	if (!list || !(*list)->next)
		return ;
	cpnb1 = (*list)->content;
	cpnb2 = (*list)->next->content;
	(*list)->content = cpnb2;
	(*list)->next->content = cpnb1;
}

void	swap_a(t_list **list_a)
{
	swap(list_a);
	ft_printf("sa\n");
}

void	swap_b(t_list **list_b)
{
	swap(list_b);
	ft_printf("sb\n");
}

void	ss(t_list **list_a, t_list **list_b)
{
	swap(list_a);
	swap(list_b);
	ft_printf("ss\n");
}
