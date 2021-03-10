/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 12:43:25 by epalomak          #+#    #+#             */
/*   Updated: 2021/02/26 17:33:08 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ra_rra_x_times(t_ps *ps, int pos)
{
	if (pos <= ps->size_a / 2)
	{
		while (pos-- > 0)
			rotate(ps, "ra");
	}
	else if (pos >= ps->size_a / 2)
	{
		pos++;
		while (pos <= ps->size_a)
		{
			rev_rotate(ps, "rra");
			pos++;
		}
	}
}
