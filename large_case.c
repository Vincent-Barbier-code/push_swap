/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:43:21 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/25 22:08:22 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	up_or_down2(t_list **list_a, int sup)
{
	t_list	*cop_a;
	int		up;
	int		down;

	up = 0;
	down = 0;
	cop_a = *list_a;
	while (cop_a->next && cop_a->content < sup)
	{
		up++;
		cop_a = cop_a->next;
	}
	while (cop_a->next)
	{
		cop_a = cop_a->next;
	}
	while (cop_a->previous && cop_a->content < sup)
	{
		down++;
		cop_a = cop_a->previous;
	}
	if (up <= down)
		return (-1);
	else
		return (1);
}

int	verif_tob(t_list **list_a, int sup)
{
	t_list	*copy;

	copy = *list_a;
	while (copy)
	{
		if (copy->content < sup)
			return (1);
		copy = copy->next;
	}
	return (0);
}

void	push_tob100(t_list **list_a, t_list **list_b, t_ext ext)
{
	t_list	*copy;
	int		sup;

	sup = 20;
	copy = (*list_a);
	while (len_list(&copy) != 1)
	{
		while (verif_tob(&copy, sup) && len_list(&copy) != 1)
		{
			if (copy->content < sup && (copy->content != ext.max))
				push_b(&copy, list_b);
			else
			{
				if (up_or_down2(&copy, sup) < 0)
					rotate_a(&copy);
				else if (up_or_down2(&copy, sup) > 0)
					rra(&copy);
			}
		}
		*list_a = copy;
		sup = sup + 21;
	}
}

void	push_tob500(t_list **list_a, t_list **list_b, t_ext ext)
{
	t_list	*copy;
	int		sup;

	copy = (*list_a);
	sup = 46;
	while (len_list(&copy) != 1)
	{
		while (verif_tob(&copy, sup) && len_list(&copy) != 1)
		{
			if (copy->content < sup && (copy->content != ext.max))
				push_b(&copy, list_b);
			else
			{
				if (up_or_down2(&copy, sup) < 0)
					rotate_a(&copy);
				else if (up_or_down2(&copy, sup) > 0)
					rra(&copy);
			}
		}
		*list_a = copy;
		sup = sup + 47;
	}
}
