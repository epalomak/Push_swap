/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:07:05 by epalomak          #+#    #+#             */
/*   Updated: 2020/11/18 15:46:24 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	print_it(t_ps *ps)
{
	int i;

	i = 0;
	while (i < ps->size_a)
		printf("%d\n",ps->st_a[i++]);
}

void	swap(t_ps *ps, char *cmd)
{
	int tmp;

	if (cmd[1] == 'a')
	{
		tmp = ps->st_a[0];
		ps->st_a[0] = ps->st_a[1];
		ps->st_a[1] = tmp;
	}
	if (cmd[1] == 'b')
		ft_swap(&ps->st_b[0], &ps->st_b[1]);
	if (cmd[1] == 's')
	{
		ft_swap(&ps->st_a[0], &ps->st_a[1]);
		ft_swap(&ps->st_a[0], &ps->st_a[1]);
	}
	print_it(ps);
}

void	push(t_ps *ps, char *cmd)
{
	int i;

	if (cmd[1] == 'a' && ps->size_b >= 1)
	{
		i = ps->size_a + 1;
		while (i-- > 0)
			ps->st_a[i] = ps->st_a[i - 1];
		ps->st_a[0] = ps->st_b[0];
		ps->size_a += 1;
		ps->size_b -= 1;
		i = -1;
		while (i++ < ps->size_b)
			ps->st_b[i] = ps->st_b[i + 1];
	}
	else if (cmd[1] == 'b' && ps->size_a >= 1)
	{
		i = ps->size_b + 1;
		while (i-- > 0)
			ps->st_b[i] = ps->st_b[i - 1];
		ps->st_b[0] = ps->st_a[0];
		ps->size_b += 1;
		ps->size_a -= 1;
		i = -1;
		while (i++ < ps->size_a)
			ps->st_a[i] = ps->st_a[i + 1];
	}
	print_it(ps);
}

void	rotate(t_ps *ps, char *cmd)
{
	int	i;
	int	tmp;

	if ((cmd[1] == 'a' || cmd[1] == 'r') && ps->size_a >= 2)
	{
		i = -1;
		tmp = ps->st_a[0];
		while (i++ < (ps->size_a))
			ps->st_a[i] = ps->st_a[i + 1];
		ps->st_a[ps->size_a - 1] = tmp;
	}
	if ((cmd[1] == 'b' || cmd[1] == 'r') && ps->size_b >= 2)
	{
		i = 0;
		tmp = ps->st_b[0];
		while (i++ < (ps->size_b))
			ps->st_b[i] = ps->st_b[i + 1];
		ps->st_b[ps->size_b - 1] = tmp;
	}
	print_it(ps);
}

void	rev_rotate(t_ps *ps, char *cmd)
{
	int	i;
	int	tmp;

	if ((cmd[2] == 'a' || cmd[2] == 'r') && ps->size_a >= 2)
	{
		i = ps->size_a;
		tmp = ps->st_a[ps->size_a - 1];
		while (i-- > 1)
			ps->st_a[i] = ps->st_a[i - 1];
		ps->st_a[0] = tmp;
	}
	if ((cmd[2] == 'b' || cmd[2] == 'r') && ps->size_b >= 2)
	{
		i = 0;
		tmp = ps->st_a[ps->size_b - 1];
		while (i-- > 1)
			ps->st_b[i] = ps->st_b[i - 1];
		ps->st_b[0] = tmp;
	}
	print_it(ps);
}