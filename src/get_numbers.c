/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:06:34 by epalomak          #+#    #+#             */
/*   Updated: 2020/11/05 15:17:24 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		check_arg(char *src)
{
	int		i;

	i = 0;
	while(src[i])
	{
		if (src[i] < '0' && src[i] > '9')
			return(1);
		i++;
	}

	return(0);
}

char	**get_numbers(int ac, char **av)
{
	char	**nbr;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (!(nbr = (char**)malloc(sizeof(char*) * ac)))	
		exit(0);
	while(ac > i)
	{
		if(check_arg(av[i]) != 0)
			display_errors();
		nbr[j++] = ft_strdup(av[i++]);
	}
	return (nbr);
}