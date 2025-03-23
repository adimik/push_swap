/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:39:56 by didimitr          #+#    #+#             */
/*   Updated: 2025/03/17 17:33:10 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atol(char *str)
{
	int	i;
	long long	res;
	int sign;

	res = 0;
	sign = 1;
	i = 0;
	if(str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while(str[i] && str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	res = res * sign;
	return(res);
}
void	list_free(t_stack *list)
{
	t_stack *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}