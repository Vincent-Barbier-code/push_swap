/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indices.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:45:27 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/25 22:12:37 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calcul_ind(int content, int new, int i)
{
	if (content > new)
		i++;
	return (i);
}

static void	cont_to_ind(t_list **list)
{
	t_list	*deb;

	deb = *list;
	while (deb)
	{
		deb->content = deb->indice;
		deb = deb->next;
	}
}

void	trans_ind(t_list **list)
{
	t_list	*list_new;
	t_list	*copy;
	int		i;

	copy = *list;
	list_new = (*list)->next;
	while (copy)
	{
		i = 0;
		list_new = copy->next;
		while (list_new)
		{
			i = calcul_ind(copy->content, list_new->content, i);
			list_new = list_new->next;
		}
		list_new = copy->previous;
		while (list_new)
		{
			i = calcul_ind(copy->content, list_new->content, i);
			list_new = list_new->previous;
		}
		copy->indice = i;
		copy = copy->next;
	}
	cont_to_ind(list);
}
