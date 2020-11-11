/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:17:54 by epalomak          #+#    #+#             */
/*   Updated: 2020/11/11 12:06:24 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	display_errors()
{
	ft_putstr_fd("error\n", 1);
	exit(0);
}

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
		ps->st_a = get_numbers(ps ,av);
		while(i < (ac - 1))
			printf("%d\n", ps->st_a[i++]);
	}
	return(0);
}