/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:45:08 by apons             #+#    #+#             */
/*   Updated: 2019/05/15 14:00:28 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int nb, int base)
{
	char	*base_numbers;
	char	*strnb;
	int		unit;
	int		a;

	if (base < 2 || base > 16)
		return (NULL);
	if (base == 10 || nb == 0)
		return (ft_itoa(nb));
	unit = 1;
	base_numbers = "0123456789ABCDEF";
	while (nb / ft_power_x(base, unit) && ft_power_x(base, unit) < 2147483648)
		unit++;
	if (!(strnb = ft_strnew(unit)))
		return (NULL);
	a = 0;
	while (--unit >= 0)
	{
		strnb[a] = base_numbers[nb / ft_power_x(base, unit)];
		nb = nb % ft_power_x(base, unit);
		a++;
	}
	strnb[a] = '\0';
	return (strnb);
}
