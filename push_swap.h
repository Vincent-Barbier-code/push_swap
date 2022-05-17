/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:48:49 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/17 16:13:39 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./ft_printf/ft_printf.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

typedef	struct	s_put
{
	int	nb;
	int	pass;
}	t_put;

typedef	struct s_med
{
	int	sup;
	int	inf;
	int mediane;
}	t_med;

//list_utils.c
void	print(t_list **list);
t_list	*ft_lstnew_int(int nb);
void	ft_lstadd_front_int(t_list **list, int nb);
void	ft_lstadd_back_int(t_list **list, int nb);
void	ft_clear(t_list **lst);

//list_utils1.c
int	len_list(t_list **list);
int	min(t_list **list_a);
int	max(t_list **list_a);

//parsing.c
t_put	ft_atoi(const char *str, t_list **list_a);
void	fill_list_a(char *str, t_list **list_a);
int		checkdbandsort(t_list **list_a);
int		parsing(char *str);

//error.c
void	error();
void	error_l(t_list **list_a);
void	error_ll(t_list **list_a, t_list **list_b);
void	error_pars_initlst( int ac, char **av, t_list **list_a);

//mediane.c
t_med	calcul_med(int copy, int new, t_med med);
int		mediane(t_list **list_a);
int		verif_med(t_list **list_a, int med);
void	push_medtob(t_list **list_a, t_list **list_b);

void	sort_2_3(t_list **list);

//operations : push.c swap.c rotate.c rrtotate.c
void	swap_a(t_list **list_a);
void	swap_b(t_list **list_b);
void	push_a(t_list **list_a, t_list **list_b);
void	push_b(t_list **list_a, t_list **list_b);
void	rotate_a(t_list **list_a);
void	rotate_b(t_list **list_a);
void	rr(t_list **list_a, t_list **list_b);
void	rra(t_list **list_a);
void	rrb(t_list **list_a);
void	rrr(t_list **list_a, t_list **list_b);


#endif
