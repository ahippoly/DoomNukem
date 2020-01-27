/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:10:25 by apons             #+#    #+#             */
/*   Updated: 2018/11/28 14:25:51 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned	int	no_sign;
	int				divider;

	if (n >= 0)
		no_sign = n;
	else
	{
		ft_putchar_fd('-', fd);
		no_sign = -n;
	}
	divider = 1;
	while (no_sign / divider >= 10)
		divider = divider * 10;
	while (divider != 1)
	{
		ft_putchar_fd(no_sign / divider + 48, fd);
		no_sign = no_sign % divider;
		divider = divider / 10;
	}
	ft_putchar_fd(no_sign + 48, fd);
}
