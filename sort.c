/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:02:45 by didimitr          #+#    #+#             */
/*   Updated: 2025/03/25 18:52:37 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     list_len(t_stack *list)
{
    int i;
    i = 0;
    while(list)
    {
        list = list->next;
        i++;
    }
    return(i);
}
int get_max_bits(t_stack *stack)
{
    int max = list_len(stack) - 1;
    int bits = 0;
    while (max >> bits)
        bits++;
    return bits;
}

void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int size = list_len(*stack_a);
    int max_bits = get_max_bits(*stack_a);
    int i = 0;
    int j;

    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if ((((*stack_a)->index >> i) & 1) == 0)
                pb(stack_a, stack_b);
            else
                ra(*stack_a);
            j++;
        }
        while (*stack_b)
            pa(stack_a, stack_b);
        i++;
    }
}
t_stack *find_min(t_stack *list)
{
    t_stack *tmp;
    t_stack *min;
    
    tmp = list;
    min = NULL;
    while(tmp)
    {
        if((min == NULL || tmp->num < min->num) && tmp->index == -1)
        {
            min = tmp;
        }
        tmp = tmp->next;
    }
    return(min);
}

void    add_index(t_stack *list)
{
    int index;
    t_stack *tmp;
    t_stack *min_node;

    min_node = NULL;
    tmp = list;
    index = 0;
    while(tmp)
    {
        tmp->index = -1;
        tmp = tmp->next;
    }
    while((min_node = find_min(list)))
    {
        min_node->index = index++;
    }
}
int sorted(t_stack *stack)
{
    while(stack)
    {
        if(stack->next && stack->num > stack->next->num)
            return(0);
        stack = stack->next;
    }
    return(1);
}
void    small_sort(t_stack **stack_a, t_stack **stack_b, int len)
{
    if(len == 3)
        sort_3(stack_a);
    if(len == 4)
        sort_4(stack_a, stack_b);
}
int get_min_pos(t_stack *stack)
{
    int i;

    i = 0;
    while(stack)
    {
        if(stack->index == 0)
            return(i);
        i++;
        stack = stack->next;
    }
    return(i);
}

void    sort_4(t_stack **stack_a, t_stack **stack_b)
{
    int min_pos;

    min_pos = get_min_pos(*stack_a);

    if(min_pos == 1)
        sa(*stack_a);
    else if(min_pos == 2)
        ra(*stack_a);
    else if(min_pos == 3)
        rra(stack_a);
    pb(stack_a, stack_b);
    sort_3(stack_a);
    pa(stack_a, stack_b);
}

void    sort_3(t_stack **stack)
{
    int a;
    int b;
    int c;

    a = (*stack)->num;
    b = (*stack)->next->num;
    c = (*stack)->next->next->num;
    if(a > b && b < c && c > a)
        sa(*stack);
    else if (a > b && b > c)
    {
        ra(*stack);
        sa(*stack);
    }
    else if (a > b && b < c)
        ra(*stack);
    else if (a < b && b > c && a < c)
    {
        sa(*stack);
        ra(*stack);
    }
    else if (a < b && b > c && a > c)
        rra(stack);
}

void    sort(t_stack *list_a, t_stack *list_b)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int i;

    stack_a = list_a;
    stack_b = list_b;
    i = list_len(stack_a);
    add_index(stack_a);
    if(sorted(stack_a))
        return;
    if(i < 6)
        small_sort(&stack_a, &stack_b, i);
    else radix_sort(&stack_a, &stack_b);
}