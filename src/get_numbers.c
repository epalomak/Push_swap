/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:06:34 by epalomak          #+#    #+#             */
/*   Updated: 2021/04/29 16:17:52 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void			display_errors(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

int		check_double(int *nbr, t_ps *ps)
{
	int tmp;
	int i;
	int	j;

	i = 0;
	while (i < ps->size_a)
	{
		tmp = nbr[i];
		j = i;
		while (++j < ps->size_a)
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
	int		i;
	int		dst;

	i = 0;
	while (src[i] != '\0')
	{
		if (!((int)src[i] >= 47 && (int)src[i] <= 57))
		{
			if (src[0] == '-')
				break ;
			display_errors();
		}
		i++;
	}
	if (ft_atol(src) > 2147483647 || ft_atol(src) < -2147483648)
		display_errors();
	dst = ft_atoi(src);
	free(src);
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
	ps->size_a = j;
	if (check_double(nbr, ps) != 0)
		display_errors();
	ps->size_b = 0;
	free(args);
	return (nbr);
}
