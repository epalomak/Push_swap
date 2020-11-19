/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:57:34 by epalomak          #+#    #+#             */
/*   Updated: 2020/11/19 09:43:51 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void	print_result(char *str, t_ps *ps)
{
	ft_printf("\n");
	print_it(ps);
	ft_printf("%s\n", str);
	exit (0);
}

void	check_stack(t_ps *ps)
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
				print_result("KO", ps);
		}
		i++;
	}
	print_result("OK", ps);
}