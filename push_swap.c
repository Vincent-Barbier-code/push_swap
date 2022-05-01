/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:48:43 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/01 22:28:51 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int i)
{
	if ((i >= 48) && (i <= 57))
		return (1);
	else
		return (0);
}

void	error()
{	
	printf("Error\n");
	exit(1);
}

t_put	ft_atoi(const char *str)
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
		error();
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
		put = ft_atoi(str);
		if (start)
		{
			*list_a = ft_lstnew_int(put.nb);
			start = 0;
			//printf("nb F= %d \n", (*list_a)->content);
		}
		else
			ft_lstadd_back_int(list_a, put.nb);
		while(put.pass--)
			str++;
	}
}
/*
int	checksort(int nb, t_list *list_new, int init)
{
	static copy;

	if (!list_a)
		return (0);
	if (init)
		copy = list_new->content; 

}
*/
int	checkdbandsort(t_list **list_a)
{
	int sort;
	t_list *listenew;
	t_list *copnew;

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
				error();
			copnew = copnew->next;
		}
		listenew = listenew->next;
	}
	return(sort);
}

int	parsing(char *str)
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
			error();
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		error();
	return(1);
}

int main(int ac, char **av)
{
	int i;
	t_list *list_a;

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
		fill_list_a(av[i++], &list_a);
	if (checkdbandsort(&list_a))
		exit(0);
	printf("finis");
	printf("sort ? =%d", checkdbandsort(&list_a));
	print(&list_a);
	ft_clear(&list_a);
	exit(1);
		// push dans la liste creer back int
}

