/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:29:53 by epalomak          #+#    #+#             */
/*   Updated: 2021/01/08 14:13:58 by epalomak         ###   ########.fr       */
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
		ps->print_it = 1;
		ps->st_b = ft_memalloc(sizeof(int) * ac);
		ps->st_a = get_numbers(ps ,av);
		sort(ps);
	}
	free(ps->st_a);
	free(ps->st_b);
	free(ps);
	while(1)
	{}
	return(0);
}