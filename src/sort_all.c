/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:11:09 by epalomak          #+#    #+#             */
/*   Updated: 2020/12/09 14:34:49 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	shortest_to_b(t_ps *ps, int low, int s_low)
{
	

}

void			best_way_to_b(t_ps *ps)
{
	int	low;
	int	s_low;	

	low = lowest_elem(ps);
	s_low = second_lowest_elem(ps);
	if (low == 0)
		push(ps, "pb");
	if (s_low == 1)
		push(ps, "pb");
	else if (low == ps->size_a - 1)
	{
		rev_rotate(ps, "rra");
		push(ps, "pb");
	}
	else if (s_low == 0 && low != 1)
		push(ps, "pb");
	else if (s_low == 0 && low == 1)
	{
		swap(ps, "sa");
		push(ps, "pb");
		push(ps, "pb");
	}
	else if (s_low == ps->size_a - 1)
	{
		rev_rotate(ps, "rra");
		push(ps, "pb");
	}
	shortest_to_b(ps, low, s_low);

}