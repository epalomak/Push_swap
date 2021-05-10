/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:27:39 by epalomak          #+#    #+#             */
/*   Updated: 2021/04/28 19:19:28 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_count(long nb)
{
	long	c;

	c = 0;
	if (nb < 0)
		nb = nb * -1;
	while (nb >= 10)
	{
		nb = nb / 10;
		c++;
	}
	return (c + 1);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*dst;
	long	nb;

	nb = n;
	i = ft_nb_count(nb);
	if (nb < 0)
	{
		if (!(dst = ft_strnew(i + 1)))
			return (NULL);
		dst[0] = '-';
		nb = -nb;
	}
	else if (!(dst = ft_strnew(i--)))
		return (NULL);
	if (nb == 0)
		dst[0] = '0';
	while (nb > 0)
	{
		dst[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return (dst);
}
