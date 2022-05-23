/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:51:32 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/23 16:57:21 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_up(t_list **list_a)
{
	t_list	*cop_a;
	int		i;

	i = 0;
	cop_a = *list_a;
	while (cop_a->content != min(list_a))
	{
		i++;
		cop_a = cop_a->next;
	}
	if (i == 0)
		return (0);
	if ((len_list(list_a)) / 2 < i)
		return (-1);
	else
		return (1);
}

void	final_sort(t_list **list_a)
{
	while (min_up(list_a))
	{
		if ((min_up(list_a) == 1))
		{
			while (min_up(list_a))
				rotate_a(list_a);
		}
		else if ((min_up(list_a) == -1))
		{
			while (min_up(list_a))
				rra(list_a);
		}
	}
}
