/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbetween.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 10:35:54 by apons             #+#    #+#             */
/*   Updated: 2019/11/15 11:14:26 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isbetween(double a, double low, double high)
{
	if (high < low)
		return (-1);
	if (low <= a && a <= high)
		return (1);
	return (0);
}
