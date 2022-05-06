/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:48:53 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/06 20:55:06 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	swap(t_list *list)
{
	int	cpnb1;
	int	cpnb2;

	if	(!list || !list->next)
		return ;
	cpnb1 = list->content;
	cpnb2 = list->next->content;


	list->content = cpnb2;
	list->next->content = cpnb1;
}

void	swap_a(t_list *list_a)
{
	swap(list_a);
	ft_printf("sa\n");
}

void	swap_b(t_list *list_b)
{
	swap(list_b);
	ft_printf("sb\n");
}

void	ss(t_list *list_a, t_list *list_b)
{
	swap(list_a);
	swap(list_b);
	ft_printf("ss\n");
}

static void	push(t_list **list_a, t_list **list_b)
{
	t_list *tmp;

	if (!*list_b)
		return ;
	ft_lstadd_back_int(list_a, (*list_b)->content);
	tmp = (*list_b)->next;
	free(*list_b);
	*list_b = tmp;
}

void	push_a(t_list **list_a, t_list **list_b)
{
	push(list_a, list_b);
	ft_printf("pa\n");
}

void	push_b(t_list **list_a, t_list **list_b)
{
	push(list_b, list_a);
	ft_printf("pb\n");
}

static void	rotate(t_list **list)
{
	t_list	*cp_list;
	t_list	*prems;

	if (!*list)
		return ;
	cp_list = *list;
	prems = *list;
	*list = prems->next;
	while (cp_list->next)
		cp_list = cp_list->next;
	cp_list->next = prems;
	prems->next = NULL;
}

void	rotate_a(t_list **list_a)
{
	rotate(list_a);
	ft_printf("ra\n");
}

void	rotate_b(t_list **list_b)
{
	rotate(list_b);
	ft_printf("rb\n");
}

void	rr(t_list **list_a, t_list **list_b)
{
	rotate(list_a);
	rotate(list_b);
	ft_printf("rr\n");
}

static void	reverse_rotate(t_list **list)
{
	t_list	*cp_list;
	t_list	*der;

	if (!*list)
		return ;
	cp_list = *list;
	while (cp_list->next->next)
		cp_list = cp_list->next;
	der = cp_list->next;
	cp_list->next = NULL;
	der->next=*list;
	*list = der;
}

void	rra(t_list **list_a)
{
	reverse_rotate(list_a);
	ft_printf("rra\n");
}

void	rrb(t_list **list_b)
{
	reverse_rotate(list_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **list_a, t_list **list_b)
{
	reverse_rotate(list_a);
	reverse_rotate(list_b);
	ft_printf("rrr\n");
}


/*
int main(void)
{
	t_list	*list_a;
	t_list 	*list_b;

	list_a = ft_lstnew_int(15);
	ft_lstadd_front_int(&list_a, 35);
	ft_lstadd_front_int(&list_a, 19);
	// list_a = 19 35 15
	list_b = ft_lstnew_int(18);
	ft_lstadd_front_int(&list_b, 38);
	ft_lstadd_front_int(&list_b, 16);

	// list_a = 16 38 18
	swap_a(list_a); //list_a = 35 19 15  
	swap_b(list_b); //list_b = 38 16 18

	ss(list_a, list_b); //list_a = 19 35 15 
						//list_b = 16 38 18 

	push_a(&list_a, &list_b); //list_a = 16 19 35 15
							  //list_b =  38 18
	
	printf("\nlista :\n");
	print(&list_a);
	printf("\nlistb :\n");
	print(&list_b);

	rotate_a(&list_a); //list_a = 19 35 15 16

	rr(&list_a, &list_b); //list_a = 35 15 16 19
						  //list_b = 18 38

	rra(&list_a);//list_a = 19 35 15 16

	rrr(&list_a, &list_b); //list_a = 16 19 35 15
						  //list_b = 38 18 
	
	push_a(&list_a, &list_b);
	printf("\nlista :\n");
	print(&list_a);
	printf("\nlistb :\n");
	print(&list_b);

	ft_clear(&list_a);
	ft_clear(&list_b);	
	
}
*/