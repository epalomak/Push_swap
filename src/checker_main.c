/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:17:54 by epalomak          #+#    #+#             */
/*   Updated: 2020/11/05 15:14:09 by epalomak         ###   ########.fr       */
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
	char	**st_a;
	int		i;

	i = 0;
	if (ac < 1)
		display_errors();
	else
		st_a = get_numbers(ac ,av);
	while(st_a[i] != NULL)
	{	
		printf("%s\n", st_a[i++]);
	}
	return(0);
}