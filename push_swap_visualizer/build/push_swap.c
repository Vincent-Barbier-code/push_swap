/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:48:43 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/17 04:01:14 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	supb_in_a(t_list **list_a, t_list **list_b)
{
	t_list	*cop_a;
	t_list	*cop_b;
	int	sup;

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
	//ft_printf("up = %d down = %d \n",up,down);
	if (up <= down)
		return (-down);
	if (up > down)
		return (up);
	return (0);
}

int	val_abs(int nb)
{
	if (nb < 0)
		return(-nb);
	return(nb);
}

int	who_to_push(t_list **list_a, t_list **list_b)
{
	int	cost1;
	int	cost2;
	int pos;
	int pos2;
	int cmp;
	t_list *copy;

	cmp = 1;
	pos = 0;
	copy = *list_b;
	cost1 = val_abs(up_or_down(list_a, &copy));
	if (!cost1)
		return (0);
	// ft_printf("JE RENTRE");
	while (copy->next && cmp < (len_list(list_b) / 2))
	{
		cost2 = val_abs(up_or_down(list_a, &copy)) + cmp;
		//ft_printf("UP OR DOWN: %d \n", up_or_down(list_a, &copy));
		// ft_printf("cost1: %d \n", cost1);
		// ft_printf("cost2: %d \n", cost2);
		if (cost2 < cost1)
		{
			cost1 = cost2;
			pos = cmp;	
		}
		//if (cmp < len_list(list_b) \ 2)
		cmp++;
		copy = copy->next;
	}
	cmp = len_list(list_b) / 2;
	while (copy->next)
	{
		cost2 = val_abs(up_or_down(list_a, &copy)) + cmp;		
		if (cost2 < cost1)
		{
			cost1 = cost2;
			pos2 = cmp;	
		}
		//if (cmp < len_list(list_b) \ 2)
		cmp--;
		copy = copy->next;
	}
			ft_printf("pos: %d \n", pos);
			print(list_a);
			ft_printf("listb: \n");
			print(list_b);
	if (pos < pos2)
	{
		while (pos && len_list(list_b) > 1)
		{
			// ft_printf("ROTATE A ----------------");
			rotate_b(list_b);
			pos--;
			//sleep(20);
		}
	}
	else
	{
		while (pos2 && len_list(list_b) > 1)
		{
			// ft_printf("ROTATE A ----------------");
			rrb(list_b);
			pos2--;
			//sleep(20);
		}
		sleep(30);
	}
	return (pos);
}

int min_up(t_list **list_a)
{
	t_list	*cop_a;
	int i;

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
		return (1);
	else
		return (-1);
}

void	push_tob(t_list **list_a, t_list **list_b)
{
	t_list	*copy;
	int		maximum;

	copy = (*list_a);
	maximum = max(list_a);
	while (copy->next)
	{
		if (copy->content == maximum)
			rotate_a(&copy);
		push_b(&copy, list_b);
	}
	*list_a = copy;
}

void meds_sort(t_list **list_a, t_list **list_b)
{

	while (len_list(list_a) != 1)
	{
		if (len_list(list_a) == -1)
			error_ll(list_a, list_b);
		push_medtob(list_a, list_b);
	}
}

void final_sort(t_list **list_a)
{
	while (min_up(list_a))
	{
		if ((min_up(list_a) == 1))
		{
			while (min_up(list_a))
				rotate_a(list_a);
			// ft_printf("lista: \n");
			// print(&list_a);
			// sleep(1);
		}
		else if ((min_up(list_a) == -1))
		{
			while (min_up(list_a))
				rra(list_a);
			//ft_printf("lista: \n");
			//print(&list_a);
			//sleep(1);
		} 
	}
}

void	refill_a(t_list **list_a,t_list **list_b)
{	
	while (len_list(list_b) != 0 && len_list(list_b) != -1)
	{
		// ft_printf("ICIIIIII = %d\n", up_or_down(list_a, list_b));
	//who_to_push(list_a, list_b); NULLE LA FCT
	// 	rotate_b(list_b);
	if (up_or_down(list_a, list_b) < 0)
		{
			while (up_or_down(list_a, list_b) != 0)
			{	
				rotate_a(list_a);
				//ft_printf("lista: \n");
				//print(list_a);
				//sleep(1);
			}
			//rotate_a(list_a);
		}
	else if (up_or_down(list_a, list_b) > 0)
		{
			while (up_or_down(list_a, list_b) != 0)
			{	
				rra(list_a);
				// ft_printf("lista: \n");
				// print(list_a);
				//sleep(1);
			}
			//rra(list_a);
		}
			//ft_printf("up or d =%d \n", up_or_down(list_a, list_b));
			// ft_printf("lista: \n");
			// print(list_a);
			// ft_printf("listb: \n");
			// print(list_b);
			//if (len_list(list_b) == 1)
	else
			push_a(list_a, list_b);
		
			
		//ft_printf("SORTIE---------------------------------------------------------");
	}
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;

	list_b = NULL;
	error_pars_initlst(ac, av, &list_a);
	if (!(checkdbandsort(&list_a)))
	{
		//printf("TRIE LA LISTE\n");
	//	if (len_list(&list_a) <= 100)
	//	 	push_tob(&list_a, &list_b);
	//	else
			meds_sort(&list_a, &list_b);
		refill_a(&list_a, &list_b);
		final_sort(&list_a);
	}
//	printf("finis\n");
//	printf("lista: \n");
//	print(&list_a);
//	ft_printf("listb: \n");
//	print(&list_b);	
	ft_clear(&list_a);
	//ft_clear(&list_b);
	exit(1);
}
