/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:40:38 by epalomak          #+#    #+#             */
/*   Updated: 2021/04/29 16:10:04 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	sort_five(t_ps *ps)
{
	while (ps->size_a > 3)
	{
		if (lowest_elem(ps->st_a, ps->size_a) == 0 && ps->size_a > 3)
			push(ps, "pb");
		else if (lowest_elem(ps->st_a, ps->size_a) == ps->size_a - 1)
		{
			rev_rotate(ps, "rra");
			push(ps, "pb");
		}
		else
			rotate(ps, "ra");
	}
	sort_three(ps);
	back_to_a(ps);
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
	else if (ps->size_a <= 5)
		return (sort_five(ps));
	else
	{
		sort_all(ps);
		if (ps->size_a <= 3)
			sort_three(ps);
		back_to_a(ps);
	}
}
