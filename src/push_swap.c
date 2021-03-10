/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:29:53 by epalomak          #+#    #+#             */
/*   Updated: 2021/02/26 17:24:54 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		main(int ac, char **av)
{
	t_ps	*ps;

	if (!(ps = (t_ps*)malloc(sizeof(t_ps))))
		display_errors();
	if (ac <= 1)
		display_errors();
	else
	{
		ps->ac = ac;
		ps->print_it = 1;
		ps->st_a = get_numbers(ps, av);
		ps->st_b = ft_memalloc(sizeof(int) * (ps->size_a + 1));
		sort(ps);
	}
	free(ps->st_a);
	free(ps->st_b);
	free(ps);
	return (0);
}
