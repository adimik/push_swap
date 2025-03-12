/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:25:33 by didimitr          #+#    #+#             */
/*   Updated: 2025/03/11 14:34:29 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	AlreadyInList(t_stack *stack, long long buf)
{
	while(stack)
	{
		if(stack->num == buf)
			return(1);
		stack = stack->next;
	}
	return(0);
}
int	InputIsInt(char *arr)
{
	int	i;
	
	i = 0;
	if(arr[i] == '-')
			i++;
	while(arr[i])
	{
		if(i >= 11)
			return(0);
		if(arr[i] < '0' || arr[i] > '9')
			return(0);
		i++;
	}
	return(1);
}
