/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:02:45 by didimitr          #+#    #+#             */
/*   Updated: 2025/03/18 17:35:21 by didimitr         ###   ########.fr       */
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
    int max = list_len(stack) - 1; // Největší index
    int bits = 0;
    while (max >> bits) // Počet bitů potřebných k reprezentaci max indexu
        bits++;
    return bits;
}

// Radix sort pomocí bitového třídění
void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int size = list_len(*stack_a);
    int max_bits = get_max_bits(*stack_a);
    int i, j;
    
    for (i = 0; i < max_bits; i++) // Iterujeme přes jednotlivé bity
    {
        j = 0;
        while (j < size)
        {
            if ((((*stack_a)->index >> i) & 1) == 0) // Kontrola i-tého bitu
                pb(stack_a, stack_b); // Pokud je 0, pushujeme do stack_b
            else
                ra(*stack_a); // Pokud je 1, rotujeme v stack_a
            j++;
        }
        while (*stack_b) // Vracíme čísla zpět do stack_a
            pa(stack_a, stack_b);
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

void    sort(t_stack *list_a, t_stack *list_b)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = list_a;
    stack_b = list_b;
    add_index(stack_a);
    //if(list_len(stack_a) <= 6)
    //    small_sort(stack_a);
    radix_sort(&stack_a, &stack_b);
}