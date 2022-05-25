/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:48:43 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/25 14:00:16 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	supb_in_a(t_list **list_a, t_list **list_b)
{
	t_list	*cop_a;
	t_list	*cop_b;
	int		sup;

	sup = INT_MAX;
	cop_a = *list_a;
	cop_b = *list_b;
	while (cop_a)
	{
		if (cop_b->content < cop_a->content && cop_a->content < sup)
			sup = cop_a->content;
		cop_a = cop_a -> next;
	}		
	return (sup);
}

int	up_or_down(t_list **list_a, t_list **list_b)
{
	t_list	*cop_a;
	int		up;
	int		down;

	up = 0;
	down = 0;
	cop_a = *list_a;
	while (cop_a->content != supb_in_a(list_a, list_b))
	{
		up++;
		cop_a = cop_a->next;
	}
	if (!up)
		return (0);
	while (cop_a)
	{
		down++;
		cop_a = cop_a->next;
	}
	if (up <= down)
		return (-down);
	if (up > down)
		return (up);
	return (0);
}

void	refill_a(t_list **list_a, t_list **list_b)
{	
	while (len_list(list_b) != 0 && len_list(list_b) != -1)
	{
		if (up_or_down(list_a, list_b) < 0)
		{
			while (up_or_down(list_a, list_b) != 0)
				rotate_a(list_a);
		}
		else if (up_or_down(list_a, list_b) > 0)
		{
			while (up_or_down(list_a, list_b) != 0)
				rra(list_a);
		}
		else
			push_a(list_a, list_b);
	}
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;
	t_ext	ext;

	list_b = NULL;
	error_pars_initlst(ac, av, &list_a);
	if (!(checkdbandsort(&list_a)))
	{
		ext.min = min(&list_a);
		ext.max = max(&list_a);
		if (len_list(&list_a) == 2)
			case_2(&list_a);
		else if (len_list(&list_a) == 3)
			case_3(&list_a);
		else if (len_list(&list_a) == 5)
			case_5(&list_a, &list_b);
		else if (len_list(&list_a) < 500)
			push_tob100(&list_a, &list_b, ext, len_list(&list_a));
		else
			push_tob500(&list_a, &list_b, ext, len_list(&list_a));
		refill_a(&list_a, &list_b);
		final_sort(&list_a);
	}
	ft_clear(&list_a);
	exit(1);
}
