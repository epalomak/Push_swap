/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:35:56 by epalomak          #+#    #+#             */
/*   Updated: 2020/11/25 16:27:20 by epalomak         ###   ########.fr       */
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