/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:21:47 by epalomak          #+#    #+#             */
/*   Updated: 2021/03/17 15:27:28 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void			back_to_a(t_ps *ps)
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
	}
}

static	void	double_rev_rot(t_ps *ps, int posa, int posb)
{
	while (posb <= ps->size_b && posa <= ps->size_a)
	{
		rev_rotate(ps, "rrr");
		posb++;
		posa++;
	}
}

static	void	shortest_way(t_ps *ps, int avg_v)
{
	int posb;
	int posa;

	posa = 0;
	posb = highest_elem(ps->st_b, ps->size_b);
	if (ps->st_b[0] > ps->st_b[1] && ps->st_a[0] > ps->st_a[1])
		swap(ps, "ss");
	while (posa < ps->size_a)
	{
		if (ps->st_a[posa] < avg_v)
			break ;
		posa++;
	}
	if (posb <= ps->size_b / 2 && posa <= ps->size_a / 2)
	{
		while (posb-- > 0 && posa-- > 0)
			rotate(ps, "rr");
	}
	else if (posb >= ps->size_b / 2 && posa >= ps->size_a / 2)
		double_rev_rot(ps, posa++, posb++);
	ra_rra_x_times(ps, posa);
}

void			sort_250(t_ps *ps)
{
	int i;
	int	a_size;
	int	avg_v;

	avg_v = average_value(ps);
	a_size = ps->size_a;
	i = 0;
	while (i < (a_size / 2))
	{
		if (ps->st_a[0] < avg_v)
		{
			push(ps, "pb");
			i++;
		}
		else
			shortest_way(ps, avg_v);
	}
	if (ps->size_a > 4)
		sort_250(ps);

}
