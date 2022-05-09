/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:48:43 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/09 19:56:15 by vbarbier         ###   ########.fr       */
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

void	push_medtob(t_list **list_a, t_list **list_b, int med)
{
	t_list	*copy;
	copy = *list_a;
	ft_printf("med = %d \n",med);
	while (copy)
	{
		printf("dedans = %d \n",copy->content);
		if (copy->previous == NULL && copy->content <= med)
		{
			swap_a(&copy);
			copy = copy->next;
		}
		printf("apres swap = %d \n",copy->content);
		if ((copy)->content <= med)
		{
			ft_printf("WTFFFFF");
			push_b(&copy, list_b); 
		}
		else
		{
			if ((copy)->previous)
				ft_printf("ok  = %d \n", (copy)->previous->content);
			copy = (copy)->next;
		}
		//sleep(1);
	}	
	ft_printf("LIST :\n");
	ft_printf("SORTIE-------------------------------------------------------------------\n");
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;
	int med;

	list_b = NULL;
	error_pars_initlst(ac, av, &list_a);
	if (!(checkdbandsort(&list_a)))
	{
		printf("TRIE LA LISTE\n");
		while (len_list(&list_a) != 1)
		{
			if (len_list(&list_a) == -1)
				error_ll(&list_a, &list_b);
			med = mediane(&list_a);
			push_medtob(&list_a, &list_b, med);
		//	if (!list_a)
		//		list_a = list_a->next;
			ft_printf("len = %d\n", len_list(&list_a));
			
		//	push_medtob(&list_a, &list_b);
		//	print(&list_a);
		//	sleep(2);
		
		}
	}
	printf("finis\n");
	printf("lista: \n");
	print(&list_a);
	ft_printf("listb: \n");
	print(&list_b);
	ft_clear(&list_a);
	ft_clear(&list_b);
	exit(1);
}
