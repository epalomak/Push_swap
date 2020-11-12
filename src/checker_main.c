/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:17:54 by epalomak          #+#    #+#             */
/*   Updated: 2020/11/12 12:15:47 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	display_errors()
{
	ft_putstr_fd("error\n", 1);
	exit(0);
}

void	read_inst(t_ps *ps)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		if ((ft_strcmp(line, "sa") || ft_strcmp(line, "sb") || 
		ft_strcmp(line, "ss")) == 0)
			swap(ps, line);
		if ((ft_strcmp(line, "pa") || ft_strcmp(line, "pb")) == 0)
			push(ps, line);
		if ((ft_strcmp(line, "ra") || ft_strcmp(line, "rb") || 
		ft_strcmp(line, "rr")) == 0)
			rotate(ps, line);
		if ((ft_strcmp(line, "rra") || ft_strcmp(line, "rrb") || 
		ft_strcmp(line, "rrr")) == 0)
			rev_rotate(ps, line);
		
			
	}
}

int		main(int ac, char **av)
{
	int		i;
	t_ps	*ps;
	char	*line;

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
		read_inst(ps);
	}
	return(0);
}

/* CTRL-D to stop giving arguments to get_next_line*/