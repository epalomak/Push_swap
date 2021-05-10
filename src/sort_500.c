/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:33:09 by epalomak          #+#    #+#             */
/*   Updated: 2021/04/29 16:10:19 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_intcmp(int s, int *stack, int size)
{
	int i;

	i = -1;
	while (++i < size)
		if (s == stack[i])
			return (0);
	return (1);
}

static int	*copy_stack(t_ps *ps)
{
	int i;
	int *stack;

	stack = ft_memalloc(sizeof(int) * (ps->size_a));
	i = -1;
	while (i++ <= ps->size_a - 1)
		stack[i] = ps->st_a[i];
	return (stack);
}

static int	*get_lowest(t_ps *ps)
{
	int i;
	int *stack_a;
	int *dest;

	i = 0;
	stack_a = copy_stack(ps);
	dest = ft_memalloc(sizeof(int) * ps->size_a / 4);
	while (i < ps->size_a / 4)
	{
		dest[i] = stack_a[lowest_elem(stack_a, ps->size_a)];
		stack_a[lowest_elem(stack_a, ps->size_a)] = INT_MAX - 1;
		i++;
	}
	free(stack_a);
	return (dest);
}

static	int	shortest_way(t_ps *ps, int *lowest, int i)
{
	int count;

	count = 0;
	if (ft_intcmp(ps->st_a[ps->size_a - 1], lowest, ((ps->size_a) / 4)) == 0)
	{
		rev_rotate(ps, "rra");
		push(ps, "pb");
		count++;
		i++;
	}
	if (count == 0)
		rotate(ps, "ra");
	return (i);
}

void		sort_all(t_ps *ps)
{
	int size;
	int i;
	int *lowest;

	lowest = get_lowest(ps);
	size = ps->size_a / 4;
	i = 0;
	while (i < (size))
	{
		if (ft_intcmp(ps->st_a[0], lowest, (size)) == 0)
		{
			push(ps, "pb");
			i++;
		}
		else
			i = shortest_way(ps, lowest, i);
	}
	free(lowest);
	if (check_stack(ps) == 0)
		return ;
	if (ps->size_a > 3)
		sort_all(ps);
}
