/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:37:52 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/25 21:46:29 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	put.nb = signe * nb;
	if (put.nb > INT_MAX || put.nb < INT_MIN)
		error_l(list_a);
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
