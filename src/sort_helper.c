/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:35:56 by epalomak          #+#    #+#             */
/*   Updated: 2020/12/08 16:32:22 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		highest_elem(t_ps *ps)
{
	int i;
	int	max_elem;
	int tmp;

	i = 0;
	max_elem = 0;
	tmp = ps->st_a[i];
	while(++i < ps->size_a)
	{
		if(ps->st_a[i] > tmp)
		{
			max_elem = i;
			tmp = ps->st_a[i];
		}		
	}
	return (max_elem);
}

int		lowest_elem(t_ps *ps)
{
	int i;
	int	min_elem;
	int tmp;

	i = 0;
	min_elem = 0;
	tmp = ps->st_a[i];
	while(++i < ps->size_a)
	{
		if(ps->st_a[i] < tmp)
		{
			min_elem = i;
			tmp = ps->st_a[i];
		}		
	}
	return (min_elem);
}

int		second_lowest_elem(t_ps *ps)
{
	int i;
	int	min_elem;
	int	s_min_elem;
	int tmp;
	int tmp_2;

	i = 0;
	min_elem = -1;
	s_min_elem = 0;
	tmp = ps->st_a[i];
	tmp_2  = INT_MAX;
	while (++i < ps->size_a)
	{
		if (ps->st_a[i] < tmp)
		{
			min_elem = i;
			tmp = ps->st_a[i];
		}
		if (ps->st_a[i] < tmp_2 && ps->st_a[i] > tmp)
		{
			s_min_elem = i;
			tmp_2 = ps->st_a[i];
		}
	}
	if (ps->st_a[0] < ps->st_a[s_min_elem] && min_elem != -1)
		s_min_elem = 0;
	return (s_min_elem);
}

