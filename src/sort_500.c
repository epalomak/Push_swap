/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:33:09 by epalomak          #+#    #+#             */
/*   Updated: 2021/02/26 17:30:31 by epalomak         ###   ########.fr       */
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
	while (i++ < ps->size_a - 1)
		stack[i] = ps->st_a[i];
	return (stack);
}

static int	*get_lowest(t_ps *ps)
{
	int i;
	int *stack_a;
	int size;
	int *dest;

	i = 0;
	stack_a = copy_stack(ps);
	size = ps->size_a;
	dest = ft_memalloc(sizeof(int) * ps->size_a / 4);
	while (i < ps->size_a / 4)
	{
		dest[i++] = stack_a[lowest_elem(stack_a, size)];
		stack_a[lowest_elem(stack_a, size--)] = INT_MAX;
	}
	free(stack_a);
	return (dest);
}

void		sort_500(t_ps *ps)
{
	int size;
	int i;
	int *lowest;

	lowest = get_lowest(ps);
	size = ps->size_a / 2;
	i = 0;
	while (i < (size / 2))
	{
		if (ft_intcmp(ps->st_a[0], lowest, (size / 2)) == 0)
		{
			push(ps, "pb");
			i++;
		}
		else
			rotate(ps, "ra");
	}
	free(lowest);
	if (ps->size_a > 4)
		sort_500(ps);
}
