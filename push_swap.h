#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_stack
{
    int index;
    int num;
    struct s_stack *next;
}t_stack;

long long	ft_atol(char *str);
int	AlreadyInList(t_stack *stack, long long buf);
int	InputIsInt(char *arr);
t_stack	*node_malloc(long long buf);
t_stack	*node_append(t_stack *stack, t_stack *new_node);
t_stack	*ll_get(int argc, char **argv, int i);
int	ft_arraylen(char **arr);
t_stack *ft_splitll(char *arr);
void	ft_swap(t_stack *a, t_stack *b);
void	sa(t_stack *list);
void	ra(t_stack *list);
void	rra(t_stack **list);
void	rrb(t_stack **list);
void	pa(t_stack **list_a, t_stack **list_b);
void	pb(t_stack **list_a, t_stack **list_b);
void	list_free(t_stack *list);
void	rrr(t_stack **list_a, t_stack **list_b);


void    sort(t_stack *list_a, t_stack *list_b);
void radix_sort(t_stack **stack_a, t_stack **stack_b);
int get_max_bits(t_stack *stack);
int     list_len(t_stack *list);
void    add_index(t_stack *list);
t_stack *find_min(t_stack *list);
void    sort_3(t_stack **stack);
void    sort_4(t_stack **stack_a, t_stack **stack_b);
int get_min_pos(t_stack *stack);
#endif
