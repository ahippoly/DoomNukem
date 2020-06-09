/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 06:45:01 by saneveu           #+#    #+#             */
/*   Updated: 2020/01/17 16:35:59 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		itoa_is_neg(int *nb, int *neg)
{
	if (*nb < 0)
	{
		*nb *= -1;
		*neg = 1;
	}
}

static int		len_init(int nb)
{
	int len;

	len = 2;
	while (nb /= 10)
		len++;
	return (len);
}

char			*ft_itoa(int nb)
{
	int		len;
	int		neg;
	char	*dest;

	neg = 0;
	itoa_is_neg(&nb, &neg);
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	len = len_init(nb);
	len += neg;
	if (!(dest = (char *)malloc(sizeof(char) * len)))
		return (0);
	if (neg)
		dest[0] = '-';
	dest[--len] = '\0';
	while (len--)
	{
		dest[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (neg)
		dest[0] = '-';
	return (dest);
}
