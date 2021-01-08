/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:11:09 by epalomak          #+#    #+#             */
/*   Updated: 2021/01/08 14:01:24 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

static	void	shortest_to_b(t_ps *ps, int low)
{
	int tmp;

	tmp = low;
	if (low <= (ps->size_a / 2))
	{	
		while(tmp-- > 0)
		{
			rotate(ps, "ra");
		}
		push(ps, "pb");
	}
	else if (low >= (ps->size_a / 2))
	{
		tmp++;
		while(tmp <= ps->size_a)
		{
			rev_rotate(ps, "rra");
			tmp++;
		}
		push(ps, "pb");
	}

}

/*static int		check_s_low(t_ps *ps, int s_low, int low, int moved)
{
	if (s_low == 1 && low == 0 && ps->size_a > 1)
	{
		push(ps, "pb");
		moved += 2;
	}
	else if (s_low == 0 && low != 1 && ps->size_a > 1)
	{
		push(ps, "pb");
		moved += 2;
	}
	else if (s_low == 0 && low == 1 && ps->size_a > 1)
	{
		swap(ps, "sa");
		push(ps, "pb");
		if (ps->st_b[ps->size_b - 1] > ps->st_b[ps->size_b - 2])
			swap(ps, "sb");
		push(ps, "pb");
		moved += 2;
	}
	else if (s_low == ps->size_a - 1 && ps->size_a > 1)
	{
		rev_rotate(ps, "rra");
		push(ps, "pb");
		moved += 2;
	}
	return (moved);
}
*/
void			best_way_to_b(t_ps *ps)
{
	int	low;
	int	s_low;
	int moved;

	moved = 0;
	low = lowest_elem(ps);
	s_low = second_lowest_elem(ps);
	if (low == 0)
	{
		push(ps, "pb");
		moved++;
	}
	else if (low == ps->size_a - 1)
	{
		rev_rotate(ps, "rra");
		push(ps, "pb");
		moved++;
	}
//	else if (s_low == 0 && low == 1 && ps->size_a > 2)
//	{
//		swap(ps, "sa");
//		push(ps, "pb");
//		if (ps->st_b[ps->size_b - 1] > ps->st_b[ps->size_b - 2])
//			swap(ps, "sb");
//		push(ps, "pb");
//		moved++;
//	}
	if (moved == 0)
		shortest_to_b(ps, low);
	printf("1\n");
}