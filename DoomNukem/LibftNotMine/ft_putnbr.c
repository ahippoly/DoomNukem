/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:05:57 by apons             #+#    #+#             */
/*   Updated: 2018/11/28 15:02:30 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned	int	no_sign;
	int				divider;

	if (n >= 0)
		no_sign = n;
	else
	{
		ft_putchar('-');
		no_sign = -n;
	}
	divider = 1;
	while (no_sign / divider >= 10)
		divider = divider * 10;
	while (divider != 1)
	{
		ft_putchar(no_sign / divider + 48);
		no_sign = no_sign % divider;
		divider = divider / 10;
	}
	ft_putchar(no_sign + 48);
}
