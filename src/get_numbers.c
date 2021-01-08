/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:06:34 by epalomak          #+#    #+#             */
/*   Updated: 2021/01/08 14:35:48 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		check_double(int *nbr, t_ps *ps)
{
	int tmp;
	int i;
	int	j;

	i = 0;
	while (i < (ps->ac - 1))
	{
		tmp = nbr[i];
		j = i;
		while (++j < (ps->ac -1))
		{
			if (tmp == nbr[j])
				return (1);
		}
		i++;
	}
	return(0);
}

int		check_n_form(char *src)
{
	int		i;
	int		dst;

	i = 0;
	while(src[i] != '\0')
	{
		if (!((int)src[i] >= 47 && (int)src[i] <= 57))
		{
			if(src[0] == '-')
				break ;
			display_errors();
		}
		i++;
	}
	dst = ft_atoi(src);
	if(dst > INT_MAX || dst < INT_MIN)
		display_errors();
	return(dst);
}

int		*get_numbers(t_ps *ps, char **av)
{
	int		*nbr;
	int		i;
	int		j;

	i = 1;
	j = 0;
	nbr = ft_memalloc(sizeof(int*) * ps->ac);
	while((ps->ac) > i)
	{
		nbr[j] = check_n_form(av[i++]);
		j++;
	}
	if (check_double(nbr, ps) != 0)
		display_errors();
	ps->size_a = j;
	ps->size_b = 0;
	return (nbr);
}
