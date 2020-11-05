/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:34:06 by epalomak          #+#    #+#             */
/*   Updated: 2020/02/04 14:34:08 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers.h"

static	int	ft_ncount(intmax_t nb, int base)
{
	size_t	c;

	c = 0;
	if (nb < 0)
	{
		c++;
		nb = -nb;
	}
	while (nb)
	{
		nb /= base;
		c++;
	}
	return (c);
}

static	int	ft_un_ncount(uintmax_t nb, int base)
{
	size_t	c;

	c = 0;
	if (nb < 0)
	{
		c++;
		nb = -nb;
	}
	while (nb)
	{
		nb /= base;
		c++;
	}
	return (c);
}

char		*ft_intmax_itoa_base(intmax_t src, int base, int uppercase)
{
	char		*base_tab;
	char		*dst;
	intmax_t	i;

	i = ft_ncount(src, base);
	if (base < 2 || base > 16 || !(dst = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	if (uppercase == 1)
		base_tab = "0123456789ABCDEF";
	else
		base_tab = "0123456789abcdef";
	dst[i--] = '\0';
	if (src < 0)
	{
		src = -src;
		dst[0] = '-';
	}
	if (src == 0)
		dst[0] = '0';
	while (src)
	{
		dst[i--] = base_tab[src % base];
		src /= base;
	}
	return (dst);
}

char		*ft_uintmax_itoa_base(uintmax_t src, int base, int uppercase)
{
	char		*base_tab;
	char		*dst;
	uintmax_t	i;

	i = ft_un_ncount(src, base);
	if (base < 2 || base > 16 || !(dst = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	if (uppercase == 1)
		base_tab = "0123456789ABCDEF";
	else
		base_tab = "0123456789abcdef";
	dst[i--] = '\0';
	if (src < 0)
	{
		src = -src;
		dst[0] = '-';
	}
	if (src == 0)
		dst[0] = '0';
	while (src)
	{
		dst[i--] = base_tab[src % base];
		src /= base;
	}
	return (dst);
}

char		*ft_itoa_base(int src, int base, int uppercase)
{
	char		*base_tab;
	char		*dst;
	int			i;

	i = ft_ncount(src, base);
	if (base < 2 || base > 16 || !(dst = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	if (uppercase == 1)
		base_tab = "0123456789ABCDEF";
	else
		base_tab = "0123456789abcdef";
	dst[i--] = '\0';
	if (src < 0)
	{
		src = -src;
		dst[0] = '-';
	}
	if (src == 0)
		dst[0] = '0';
	while (src)
	{
		dst[i--] = base_tab[src % base];
		src /= base;
	}
	return (dst);
}
