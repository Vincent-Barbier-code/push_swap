/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:48:43 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/02 00:43:57 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_list **list_a)
{
	if (*list_a)
		ft_clear(list_a);
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
		error(list_a);
	put.nb = signe * nb;
	put.pass = i;
	return (put);
}

void	fill_list_a(char *str, t_list **list_a)
{
	t_put	put;
	
	static int		start = 1;

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
		while(put.pass--)
			str++;
	}
}

int	checkdbandsort(t_list **list_a)
{
	int sort;
	t_list *listnew;
	t_list *copnew;

	sort = 1;
	if ((!list_a || !(*list_a)->next))
		return (0);
	listnew = *list_a;
	while (listnew->next)
	{
		copnew = listnew->next;
		if (listnew->content > copnew->content)
			sort = 0;
		while (copnew)
		{
			if (listnew->content == copnew->content)
				error(list_a);
			copnew = copnew->next;
		}
		listnew = listnew->next;
	}
	return(sort);
}

int	parsing(char *str, t_list **list_a)
{
	int i;
	int flag;

	i = 0;
	flag = 3;
	while(str[i + 1])
	{
		if ((str[i] == '-' || str[i] == '+') && (flag != 1 && flag != 2))
			flag = 1;
		else if (str[i] >= '0' && str[i] <= '9')
			flag = 2;
		else if (str[i] == ' ' && (flag != 1 || flag == 3))
			flag = 3;
		else
			error(list_a);
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		error(list_a);
	return(1);
}
/*
int	mediane_impair(t_list **list_a)
{
	t_list list_new;

	if (!l)
	while ()
	{
		/* code 
	}
	
}
*/
int main(int ac, char **av)
{
	int i;
	t_list *list_a;

	i = 1;
	if (ac >= 2)
	{
		while (i < ac)
		{
			if (!parsing(av[i++], &list_a))
				error(&list_a);
		}
	}
	else
		exit(1);
	i = 1;
	while (i < ac)
		fill_list_a(av[i++], &list_a);
	if (!(checkdbandsort(&list_a)))
	{
		printf("TRIE MOI CA\n");
	}
	printf("finis\n");
	print(&list_a);
	ft_clear(&list_a);
	exit(1);
}
