/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmem2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:12:01 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/22 17:26:15 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_printmem(void *mem, int n)
{
	int i;

	i = 0;
	write(1, "Pos\tChar\tAscii\tInt\n", 19);
	while (i < n)
	{
		ft_putnbr(i);
		write(1, "\t", 1);
		ft_putchar(((unsigned char*)mem)[i]);
		write(1, "\t", 1);
		ft_putnbr(((unsigned char*)mem)[i]);
		write(1, "\t", 1);
		ft_putnbr(((int*)mem)[i]);
		write(1, "\n", 1);
		i++;
	}
}
