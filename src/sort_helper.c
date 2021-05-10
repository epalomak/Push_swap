/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:35:56 by epalomak          #+#    #+#             */
/*   Updated: 2021/04/29 16:11:10 by epalomak         ###   ########.fr       */
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

void	rb_rrb_x_times(t_ps *ps, int pos)
{
	if (pos <= ps->size_b / 2)
	{
		while (pos-- > 0)
			rotate(ps, "rb");
	}
	else if (pos >= ps->size_b / 2)
	{
		pos++;
		while (pos <= ps->size_b)
		{
			rev_rotate(ps, "rrb");
			pos++;
		}
	}
}

void	back_to_a(t_ps *ps)
{
	int pos;

	while (ps->size_b > 0)
	{
		pos = highest_elem(ps->st_b, ps->size_b);
		if (pos == 1)
			swap(ps, "sb");
		else if (pos != 0)
			rb_rrb_x_times(ps, pos);
		if (highest_elem(ps->st_b, ps->size_b) == 0)
			push(ps, "pa");
		if (ps->st_a[0] > ps->st_a[1])
			swap(ps, "sa");
	}
}
