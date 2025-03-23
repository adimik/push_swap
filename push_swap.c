/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:12:29 by didimitr          #+#    #+#             */
/*   Updated: 2025/03/18 12:43:12 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

t_stack	*node_malloc(long long buf)
{
	t_stack *new_node;

	new_node = malloc(sizeof(t_stack));
	if(!new_node)
		return(NULL);
	new_node->num = (int)buf;
	new_node->next = NULL;
	return(new_node);
}
t_stack	*node_append(t_stack *stack, t_stack *new_node)
{
	t_stack *tmp;

	if(!stack)
		return(new_node);
	tmp = stack;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new_node;
	return(stack);
}

t_stack	*ll_get(int argc, char **argv, int i)
{
	long long buf;
	t_stack	*stack;
	t_stack *new_node;

	stack = NULL;
	while(i < argc)
	{
		if(!InputIsInt(argv[i]))
			return(NULL);
		buf = ft_atol(argv[i]);
		if(buf > 2147483647 || buf < -2147483648)
			return(NULL);
		if(AlreadyInList(stack, buf))
			return(NULL);
		new_node = node_malloc(buf);
		stack = node_append(stack, new_node);
		i++;
	}
	return(stack);
}
int	ft_arraylen(char **arr)
{
	int	i;
	i = 0;
	while(arr[i] && arr[i][0])
	{
		i++;
	}
	return(i);
}
t_stack *ft_splitll(char *arr)
{
	t_stack *stack_a;
	char	**split;
	int	i;

	split = ft_split(arr, ' ');
	i = ft_arraylen(split);
	stack_a = ll_get(i , split, 0);
	return(stack_a);
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_b = NULL;
	if(argc == 2)
	{
		stack_a = ft_splitll(argv[1]);
	}
	else
		stack_a = ll_get(argc, argv, 1);
	if(stack_a == NULL)
		return(write(2, "Error\n", 6));
	sort(stack_a, stack_b);
	list_free(stack_a);
	list_free(stack_b);
	return(0);
}
