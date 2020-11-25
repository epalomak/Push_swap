/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:40:38 by epalomak          #+#    #+#             */
/*   Updated: 2020/11/25 16:27:24 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_ps *ps)
{
	int	max;

	max = highest_elem(ps);
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
	else
	{
		if (max == 0)
		{
			rotate(ps, "ra");
			ft_printf("ra\n");
		}	
		if (max == 1)
		{
			rev_rotate(ps, "rra");
			ft_printf("rra\n");
		}
		if (ps->st_a[0] > ps->st_a[1])
		{
			swap(ps, "sa");
			ft_printf("sa\n");
		}
	}
}

void	sort_five(t_ps *ps)
{
	int max;
	int min;

	max = highest_elem(ps);
	min = lowest_elem(ps);



}

void	sort(t_ps *ps)
{
	if (check_stack(ps) == 1)
		return;
	if (ps->size_a <= 3)
		sort_three(ps);
	else if (ps->size_a <= 5)
		sort_five(ps);
//	else
//		sort_all(ps);
}