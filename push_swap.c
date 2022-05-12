/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:48:43 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/12 01:59:35 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	printf("Error\n");
	exit(1);
}

void	error_l(t_list **list_a)
{
	if (list_a)
		ft_clear(list_a);
	printf("Error\n");
	exit(1);
}

void	error_ll(t_list **list_a, t_list **list_b)
{
	if (list_a)
		ft_clear(list_a);
	if (list_b)
		ft_clear(list_b);
	printf("Error\n");
	exit(1);
}

t_put	ft_atoi(const char *str, t_list **list_a)
{
	int			i;
	int			signe;
	long int	nb;
	t_put		put;

	signe = 1;
	i = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	if (nb > INT_MAX || nb < INT_MIN)
		error_l(list_a);
	put.nb = signe * nb;
	put.pass = i;
	return (put);
}

void	fill_list_a(char *str, t_list **list_a)
{
	t_put		put;
	static int	start = 1;

	while (*str)
	{
		put = ft_atoi(str, list_a);
		if (start)
		{
			*list_a = ft_lstnew_int(put.nb);
			start = 0;
		}
		else
			ft_lstadd_back_int(list_a, put.nb);
		while (put.pass--)
			str++;
	}
}

int	checkdbandsort(t_list **list_a)
{
	int		sort;
	t_list	*listenew;
	t_list	*copnew;

	sort = 1;
	if ((!list_a || !(*list_a)->next))
		return (0);
	listenew = *list_a;
	while (listenew->next)
	{
		copnew = listenew->next;
		if (listenew->content > copnew->content)
			sort = 0;
		while (copnew)
		{
			if (listenew->content == copnew->content)
				error_l(list_a);
			copnew = copnew->next;
		}
		listenew = listenew->next;
	}
	return (sort);
}

int	parsing(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 3;
	while (str[i + 1])
	{
		if ((str[i] == '-' || str[i] == '+') && (flag != 1 && flag != 2))
			flag = 1;
		else if (str[i] >= '0' && str[i] <= '9')
			flag = 2;
		else if (str[i] == ' ' && (flag != 1 || flag == 3))
			flag = 3;
		else
			error();
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		error();
	return (1);
}

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

void	error_pars_initlst( int ac, char **av, t_list **list_a)
{
	int	i;

	i = 1;
	if (ac >= 2)
	{
		while (i < ac)
			if (!parsing(av[i++]))
				error();
	}
	else
		exit(1);
	i = 1;
	while (i < ac)
		fill_list_a(av[i++], list_a);
}

void	push_medtob(t_list **list_a, t_list **list_b)
{
	t_list	*copy;
	int		med;

	med = mediane(list_a);
	copy = *list_a;
//	ft_printf("med = %d \n",med);
	while (copy)
	{
//		printf("dedans = %d \n",copy->content);
		if (copy->previous == NULL && copy->content <= med)
		{
			swap_a(&copy);
			copy = copy->next;
		}
//		printf("apres swap = %d \n",copy->content);
		if ((copy)->content <= med)
		{
//			ft_printf("WTFFFFF");
			push_b(&copy, list_b); 
		}
		else
		{
			// if ((copy)->previous)
			// 	ft_printf("ok  = %d \n", (copy)->previous->content);
			copy = (copy)->next;
		}
		//sleep(1);
	}	
//	ft_printf("LIST :\n");
//	ft_printf("SORTIE-------------------------------------------------------------------\n");
}

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
	if (up < down)
		return (1);
	if (up > down)
		return (-1);
	return (0);
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

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;
//	int rotate;
//	int reverse;

	list_b = NULL;
	error_pars_initlst(ac, av, &list_a);
	if (!(checkdbandsort(&list_a)))
	{
		//printf("TRIE LA LISTE\n");
		while (len_list(&list_a) != 1)
		{
			if (len_list(&list_a) == -1)
				error_ll(&list_a, &list_b);
			push_medtob(&list_a, &list_b);
			//ft_printf("len = %d\n", len_list(&list_a));
			//supb_in_a(&list_a, &list_b);
		}
		while (len_list(&list_b) != 0 && len_list(&list_b) != -1)
		{
				if (up_or_down(&list_a, &list_b) == 1)
				{
					while (up_or_down(&list_a, &list_b) != 0 && len_list(&list_a) != 1 )
					{	
						rotate_a(&list_a);
						sleep(1);
					}
				//	rotate_a(&list_a);
				}
				//	ft_printf("up or d =%d \n", up_or_down(&list_a, &list_b));
				else if (up_or_down(&list_a, &list_b) == -1)
				{
					while (up_or_down(&list_a, &list_b) != 0 && len_list(&list_a) != 1)
					{	
						rra(&list_a);
						//ft_printf("lista: \n");
						//print(&list_a);
					}
				//	rra(&list_a);
				}
				//ft_printf("up or d =%d \n", up_or_down(&list_a, &list_b));
				//ft_printf("lista: \n");
				// print(&list_a);
				// ft_printf("listb: \n");
				// print(&list_b);
		
			//ft_printf("SORTIE---------------------------------------------------------");
		/*	if (rotate)
				rotate_a(&list_a);
			if (reverse)
				rra(&list_a);
		*/
			//if (len_list(&list_b) == 1)
			//	clear_and_finish(&list_a, &list_b);
			push_a(&list_a, &list_b);
		}
	while (min_up(&list_a))
		{
			if ((min_up(&list_a) == 1))
			{
				while (min_up(&list_a))
					rotate_a(&list_a);
				//ft_printf("lista: \n");
				//print(&list_a);
				//sleep(1);
			}
			else if ((min_up(&list_a) == -1))
			{
				while (min_up(&list_a))
					rra(&list_a);
				//ft_printf("lista: \n");
				//print(&list_a);
				//sleep(1);
			} 
		}

	}
	else
		exit(1);
	//	printf("DEJA TRIE\n");
	//printf("finis\n");
//	printf("lista: \n");
//	print(&list_a);
	//ft_printf("listb: \n");
	//print(&list_b);
	ft_clear(&list_a);
	ft_clear(&list_b);
	exit(1);
}
