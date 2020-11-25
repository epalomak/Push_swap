/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:17:54 by epalomak          #+#    #+#             */
/*   Updated: 2020/11/25 14:55:02 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	read_inst(t_ps *ps)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line, "sa") == 0 || ft_strcmp(line, "sb") == 0 ||
		ft_strcmp(line, "sr") == 0)
			swap(ps, line);
		if (ft_strcmp(line, "pa") == 0 || ft_strcmp(line, "pb") == 0)
			push(ps, line);
		if (ft_strcmp(line, "ra") == 0 || ft_strcmp(line, "rb") == 0 ||
		ft_strcmp(line, "rr") == 0)
			rotate(ps, line);
		if (ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "rrb") == 0 ||
		ft_strcmp(line, "rrr") == 0)
			rev_rotate(ps, line);
		
			
	}
}

int		main(int ac, char **av)
{
	int		i;
	t_ps	*ps;
	int		result;

	if (!(ps = (t_ps*)malloc(sizeof(t_ps))) || ac <= 1)
		display_errors();
	i = 0;
	ps->ac = ac;
	ps->st_a = ft_memalloc(sizeof(int) * ac);
	ps->st_b = ft_memalloc(sizeof(int) * ac);
	ps->st_a = get_numbers(ps ,av);
	read_inst(ps);
	result = check_stack(ps);
	if (result == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return(0);
}

/* CTRL-D to stop giving arguments to get_next_line*/