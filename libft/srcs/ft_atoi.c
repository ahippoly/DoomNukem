/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:09:41 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/15 17:05:16 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				neg;
	unsigned long	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\r') ||
			(str[i] == '\f') || (str[i] == '\n') || (str[i] == '\v'))
		i++;
	if (str[i] == '-')
		neg = -1;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	if (nb > 9223372036854775807)
		return (neg == 1 ? -1 : 0);
	return (nb * neg);
}
