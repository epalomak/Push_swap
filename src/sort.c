/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:40:38 by epalomak          #+#    #+#             */
/*   Updated: 2020/12/08 16:20:10 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

static	void	sort_three(t_ps *ps)
{
	int	max;

	max = highest_elem(ps);
	if (max == 0)
		rotate(ps, "ra");
	if (max == 1)
		rev_rotate(ps, "rra");
	if (ps->st_a[0] > ps->st_a[1])
		swap(ps, "sa");	
}

static	void	sort_eight(t_ps *ps)
{
	while (ps->size_a > 3)
	{
		while (lowest_elem(ps) == 0 && ps->size_a > 3)
			push(ps, "pb");
		if (lowest_elem(ps) == (ps->size_a - 1) && ps->size_a != 3)
			rev_rotate(ps, "rra");
		else if (lowest_elem(ps) == 1 && ps->size_a != 3)
			swap(ps, "sa");
		else if (ps->size_a != 3)
			rotate(ps, "ra");	
	}
	sort_three(ps);
	while (ps->size_b > 0)
		push(ps, "pa");
}

static	void	sort_all(t_ps *ps)
{
	while (lowest_elem(ps) == 0 && (ps->size_a > ps->size_b))
			push(ps, "pb");
	while (ps->size_a > 8)
		best_way_to_b(ps);
	sort_eight(ps);

}

void			sort(t_ps *ps)
{
	printf("%d\n", ps->st_a[second_lowest_elem(ps)]);
	if (check_stack(ps) == 1)
		return;
	if (ps->size_a == 1)
		return ;
	if (ps->size_a == 2)
	{
		if (ps->st_a[0] > ps->st_a[1])
		{
			swap(ps, "sa");
			ft_printf("sa\n");
		}
		return;
	}
	if (ps->size_a <= 3)
		return (sort_three(ps));
	else if (ps->size_a <= 8)
		return (sort_eight(ps));
	else
		sort_all(ps);
}

/*	
	Restrictions:
		no more than 2-3 operations for 3 integers
		no more than 12 operations for 5 integers
		no more than 700 operations for 100 integers
		no more than 5300 operations for 500 integers
	
	Ideas about algorithm solving 9 to 500 numbers and don't segfault at over 500.
	Doesn't need to be fast just least amount of "operations"

*/