/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:25:33 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/15 21:35:27 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_list(t_list **list)
{
	int		i;
	t_list	*copy;
	
	i = 0;
	if (!*list)
		return (-1);
	copy = *list;
   	while (copy) 
	{
        i++;
		//ft_printf("OK %d \n",copy->content);
        copy = copy->next;
    }
	return (i);
}

int	min(t_list **list_a)
{
	t_list	*cop_a;
	int	min;

	min = INT_MAX;
	cop_a = *list_a;
	while (cop_a)
	{
		if (cop_a->content < min)
			min = cop_a->content;
		cop_a = cop_a -> next;
	}
	return (min);
}

int	max(t_list **list_a)
{
	t_list	*cop_a;
	int	max;

	max = INT_MIN;
	cop_a = *list_a;
	while (cop_a)
	{
		if (cop_a->content > max)
			max = cop_a->content;
		cop_a = cop_a -> next;
	}
	return (max);
}
