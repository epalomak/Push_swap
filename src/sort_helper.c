/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:35:56 by epalomak          #+#    #+#             */
/*   Updated: 2021/03/01 16:44:02 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		highest_elem(int *stack, int stack_size)
{
	int i;
	int	max_elem;
	int tmp;

	i = 0;
	max_elem = 0;
	tmp = stack[i];
	while (++i < stack_size)
	{
		if (stack[i] > tmp)
		{
			max_elem = i;
			tmp = stack[i];
		}
	}
	return (max_elem);
}

int		lowest_elem(int *stack, int stack_size)
{
	int i;
	int	min_elem;
	int tmp;

	i = 0;
	min_elem = 0;
	tmp = stack[i];
	while (++i < stack_size)
	{
		if (stack[i] < tmp)
		{
			min_elem = i;
			tmp = stack[i];
		}
	}
	return (min_elem);
}

int		average_value(t_ps *ps)
{
	int		i;
	long	value;

	i = 0;
	value = 0;
	while (i <= ps->size_a)
	{
		value += ps->st_a[i];
		i++;
	}
	return ((value / ps->size_a + 1));
}
