/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:15:02 by didimitr          #+#    #+#             */
/*   Updated: 2025/03/11 18:06:43 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *a, t_stack *b)
{
	t_stack c;
	
	c.next = a->next;
	a->next = b->next;
	b->next = c.next;
	c = *a;
	*a = *b;
	*b = c;
}

void	sa(t_stack *list)
{
	t_stack *next;

	next = list->next;
	ft_swap(list, next);
}
void	sb(t_stack *list)
{
	t_stack *next;

	next = list->next;
	ft_swap(list, next);
}
void	ss(t_stack *list_a, t_stack *list_b)
{
	sa(list_a);
	sb(list_b);
}
void	ra(t_stack *list)
{
	t_stack *next;

	next = list->next;
	while(list->next)
	{
		ft_swap(list, next);
		list = list->next;
		next = next->next;
	}
}
void	rb(t_stack *list)
{
	t_stack *next;

	next = list->next;
	while(list->next)
	{
		ft_swap(list, next);
		list = list->next;
		next = next->next;
	}
}
void	rr(t_stack *list_a, t_stack *list_b)
{
	ra(list_a);
	rb(list_b);
}
void	rra(t_stack *list)
{
    t_stack	*tmp;
    t_stack	*last;

    tmp = list;
    while (tmp->next->next)
        tmp = tmp->next;
    last = tmp->next;
    tmp->next = NULL;
    last->next = list;
    list = last;
}