/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:35:28 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/19 17:24:59 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
		write(1, "-", 1) && (n *= -1);
	if (n / 10 > 0)
		ft_putnbr(n / 10);
	c = n % 10 + 48;
	if (n != -2147483648)
		write(1, &c, 1);
}
