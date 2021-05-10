/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:57:34 by epalomak          #+#    #+#             */
/*   Updated: 2021/04/29 16:19:19 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		check_final(t_ps *ps)
{
	int i;
	int j;

	i = -1;
	if (ps->size_b != 0)
		return (1);
	while (++i < ps->size_a - 1)
	{
		j = i;
		while (++j < ps->size_a)
		{
			if (ps->st_a[i] > ps->st_a[j])
				return (1);
		}
	}
	return (0);
}

int		check_stack(t_ps *ps)
{
	int i;
	int j;

	i = -1;
	while (++i < ps->size_a)
	{
		j = i;
		while (++j < ps->size_a)
		{
			if (ps->st_a[i] > ps->st_a[j])
				return (1);
		}
	}
	return (0);
}
