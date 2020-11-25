/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:29:53 by epalomak          #+#    #+#             */
/*   Updated: 2020/11/25 14:32:04 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		main(int ac, char **av)
{
	int		i;
	t_ps	*ps;

	if (!(ps = (t_ps*)malloc(sizeof(t_ps))))
		display_errors();
	i = 0;
	if (ac <= 1)
		display_errors();
	else
	{
		ps->ac = ac;
		ps->st_a = ft_memalloc(sizeof(int) * ac);
		ps->st_b = ft_memalloc(sizeof(int) * ac);
		ps->st_a = get_numbers(ps ,av);
		sort(ps);
	}
	return(0);
}