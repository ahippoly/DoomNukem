/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:14:11 by apons             #+#    #+#             */
/*   Updated: 2019/05/14 11:39:01 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char			*ft_num_to_c(unsigned int n, int units,
											int divider, int neg_c)
{
	char	*nb;

	if (!(nb = ft_strnew(units + neg_c)))
		return (NULL);
	nb[0] = '-';
	while (divider != 1)
	{
		nb[neg_c] = (n / divider) + 48;
		n = n % divider;
		neg_c++;
		divider = divider / 10;
	}
	nb[neg_c] = (n / divider) + 48;
	nb[neg_c + 1] = '\0';
	return (nb);
}

char					*ft_itoa(int n)
{
	unsigned int	e;
	int				units;
	int				divider;
	int				neg_c;

	divider = 1;
	units = 1;
	neg_c = 0;
	if (n < 0)
		neg_c = 1;
	e = ft_abs(n);
	while (e / (divider) >= 10)
	{
		divider = divider * 10;
		units++;
	}
	return (ft_num_to_c(e, units, divider, neg_c));
}
