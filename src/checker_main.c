/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:17:54 by epalomak          #+#    #+#             */
/*   Updated: 2021/03/17 13:48:49 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	read_inst(t_ps *ps)
{
	char	*line;

	while (get_next_line(0, &line))
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
		//else
		//{
		//	free(line);
		//	display_errors();
		//}
		free(line);
	}
}

int		main(int ac, char **av)
{
	int		i;
	t_ps	*ps;

	if (ac > 1)
	{
		if (!(ps = (t_ps*)malloc(sizeof(t_ps))) || ac <= 1)
			display_errors();
		i = 0;
		ps->ac = ac;
		ps->print_it = 0;
		ps->st_a = get_numbers(ps, av);
		ps->st_b = ft_memalloc(sizeof(int) * (ps->size_a + 1));
		read_inst(ps);
		if (check_final(ps) == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (0);
}
