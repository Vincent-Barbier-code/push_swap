/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 20:03:10 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/25 17:20:46 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_l(t_list **list_a)
{
	if (list_a)
		ft_clear(list_a);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_ll(t_list **list_a, t_list **list_b)
{
	if (list_a)
		ft_clear(list_a);
	if (list_b)
		ft_clear(list_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
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
