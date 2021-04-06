/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:06:34 by epalomak          #+#    #+#             */
/*   Updated: 2021/03/17 12:40:57 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

/*int		check_double(int *nbr, t_ps *ps)
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
	while (src[i] != '\0')
	{
		if (!((int)src[i] >= 47 && (int)src[i] <= 57))
		{
			if(src[0] == '-')
				break ;
			display_errors();
		}
		i++;
	}
	if (atol(src) > 2147483647 || atol(src) < -2147483648)
		display_errors();
	dst = ft_atoi(src);
	return (dst);
}

int		*get_numbers(t_ps *ps, char **av)
{
	int		*nbr;
	int		i;
	int		j;
	int		count;
	char	**args;

	j = 0;
	i = 0;
	count = ft_count(av[1], ' ');
	args = ft_strsplit(av[1], ' ');
	nbr = ft_memalloc(sizeof(int*) * (count + 1));
	while (count > i)
	{
		nbr[j] = check_n_form(args[i++]);
		j++;
	}
	if (check_double(nbr, ps) != 0)
		display_errors();
	ps->size_a = j;
	ps->size_b = 0;
	return (nbr);
}*/

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
		while (++j < (ps->ac - 1))
		{
			if (tmp == nbr[j])
				return (1);
		}
		i++;
	}
	return (0);
}

int		check_n_form(char *src)
{
	int			i;
	int			dst;

	i = 0;
	while (src[i] != '\0')
	{
		if (!(src[i] >= 47 && src[i] <= 57))
		{
			if (src[0] == '-' && (src[1] >= 47 && src[1] <= 57))
				break ;
			display_errors();
		}
		i++;
	}
	if (atol(src) > 2147483647 || atol(src) < -2147483648)
		display_errors();
	dst = ft_atoi(src);
	return ((int)dst);
}

int		*get_numbers(t_ps *ps, char **av)
{
	int		*nbr;
	int		i;
	int		j;

	i = 1;
	j = 0;
	nbr = ft_memalloc(sizeof(int*) * ps->ac);
	while ((ps->ac) > i)
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
