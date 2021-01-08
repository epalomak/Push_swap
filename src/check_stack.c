/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:57:34 by epalomak          #+#    #+#             */
/*   Updated: 2020/12/08 16:12:16 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int		check_final(t_ps *ps)
{
	int i;
	int j;

	i = 0;
	if (ps->size_b != 0)
		return (0);
	while(i < ps->size_a)
	{
		j = i + 1;
		while (j < ps->size_a)
		{
			if (ps->st_a[i] > ps->st_a[j++])
				return (0);
		}
		i++;
	}
	return (1);
}

int		check_stack(t_ps *ps)
{
	int i;
	int j;

	i = 0;
	while(i < ps->size_a)
	{
		j = i + 1;
		while (j < ps->size_a)
		{
			if (ps->st_a[i] > ps->st_a[j++])
				return (0);
		}
		i++;
	}
	return (1);
}