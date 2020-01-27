/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:01:25 by apons             #+#    #+#             */
/*   Updated: 2019/05/16 14:45:05 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_add(int charnb)
{
	if (charnb >= 48 && charnb <= 57)
		return (charnb - 48);
	if (charnb >= 65 && charnb <= 70)
		return (charnb - 55);
	return (500);
}

static int	ft_check_valid(const char *str, int base)
{
	int c;
	int check;

	if (base < 2 || base > 16)
		return (1);
	c = 0;
	while (str[c])
	{
		check = ft_get_add(str[c]);
		if (check >= base)
			return (1);
		c++;
	}
	return (0);
}

long		ft_atoi_base(const char *str, int base)
{
	int		i;
	long	nb;

	if (ft_check_valid(str, base))
		return (0);
	if (base == 10)
		return (ft_atoi(str));
	i = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 70))
	{
		nb = nb * base + ft_get_add(str[i]);
		if (nb > 2147483647)
			return (0);
		i++;
	}
	return (nb);
}
