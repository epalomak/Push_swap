/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:40:38 by epalomak          #+#    #+#             */
/*   Updated: 2021/03/17 15:56:17 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	sort_three(t_ps *ps)
{
	int	max;

	max = highest_elem(ps->st_a, ps->size_a);
	if (max == 0)
		rotate(ps, "ra");
	if (max == 1)
		rev_rotate(ps, "rra");
	if (ps->st_a[0] > ps->st_a[1])
		swap(ps, "sa");
}

void	sort_ten(t_ps *ps)
{
	while (ps->size_a > 3)
	{
		while (lowest_elem(ps->st_a, ps->size_a) == 0 && ps->size_a > 3)
			push(ps, "pb");
		if (lowest_elem(ps->st_a, ps->size_a) == (ps->size_a - 1) &&
		ps->size_a != 3)
			rev_rotate(ps, "rra");
		else if (lowest_elem(ps->st_a, ps->size_a) == 1 && ps->size_a != 3)
		{
			swap(ps, "sa");
			if (check_stack(ps) == 0)
				return ;
		}
		else if (ps->size_a != 3)
			rotate(ps, "ra");
	}
	if (check_stack(ps) == 0)
		return ;
	sort_three(ps);
	while (ps->size_b > 0)
		push(ps, "pa");
}

void	sort(t_ps *ps)
{
	if (check_stack(ps) == 0)
		return ;
	if (ps->size_a == 1)
		return ;
	if (ps->size_a == 2)
	{
		if (ps->st_a[0] > ps->st_a[1])
			swap(ps, "sa");
		return ;
	}
	if (ps->size_a <= 3)
		return (sort_three(ps));
	else if (ps->size_a <= 10)
		return (sort_ten(ps));
	else if (ps->size_a <= 505)
	{
		sort_500(ps);
		if (ps->size_a <= 3)
			sort_three(ps);
		back_to_a(ps);
	}
//	int i = -1;
//	while (++i < ps->size_a)
//		printf("%d\n", ps->st_a[i]);
}
