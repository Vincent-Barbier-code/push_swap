/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:42:26 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/17 03:39:47 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_med	calcul_med(int copy, int new, t_med med)
{
	if (copy > new)
		med.sup++;
	if (copy < new)
		med.inf++;
	return (med);
}

int	mediane(t_list **list_a)
{
	t_list	*list_new;
	t_list	*copy;
	t_med	med;

	copy = *list_a;
	list_new = (*list_a)->next;
	med.sup = 0;
	med.inf = 0;
	while (copy)
	{
		list_new = *list_a;
		while (list_new)
		{
			med = calcul_med(copy->content, list_new->content, med);
			list_new = list_new->next;
		}
		if (med.sup + 1 == med.inf)
			med.mediane = copy->content;
		if (med.sup == med.inf)
			med.mediane = copy->content;
		med.sup = 0;
		med.inf = 0;
		copy = copy->next;
	}
	return (med.mediane);
}

int	verif_med(t_list **list_a, int med)
{
	t_list	*copy;

	copy = *list_a;
	while(copy)
	{
		if (copy->content <= med)
			return(1);
		copy = copy->next;
	}
	return (0);
}

void	push_medtob(t_list **list_a, t_list **list_b)
{
	t_list	*copy;
	int		med;

	med = mediane(list_a);
	copy = (*list_a);
	//ft_printf("med = %d \n",med);
	while (verif_med(&copy, med))
	{
		//print(list_a);
//		printf("\n%d\n",i);
		//ft_printf("dedans = %d \n",copy->content);
		//sleep(1);
		if (copy->content > med)
		{
			//ft_printf("copy->prev = %p",copy->previous);
			rra(&copy);
		}
//		ft_printf("apres swap = %d \n",copy->content);
		if (copy->content <= med)
		{
//			ft_printf("WTFFFFF");
			
		//	print(list_b);
			//ft_printf("copy->prev = %p",copy->previous);
			//ft_printf("copy->prev = %p",copy->next);
			push_b(&copy, list_b); 
		}
		//else
		//	copy = copy->next;
		//sleep(1);
	}
	*list_a = copy;
//	printf("cop: \n");
//	print(&copy);
//	ft_printf("a: \n");
//	print(list_a);
//	ft_printf("LIST :\n");
	//ft_printf("SORTIE-------------------------------------------------------------------\n");
}