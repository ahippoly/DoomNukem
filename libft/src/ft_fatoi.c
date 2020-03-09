/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 21:28:27 by ahippoly          #+#    #+#             */
/*   Updated: 2020/03/09 21:55:48 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_fatoi(const char *str)
{
	double	nb;
	double	pow;
	int		neg;

	nb = 0;
	neg = 1;
	while ((*str < 14 && *str > 8) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		str++ && (neg = -1);
	while (*str >= '0' && *str <= '9')
		nb = (nb * 10) + (*(str++) - '0');
	if (*str == '.')
	{
		str++;
		pow = 0.1;
		while (*str >= '0' && *str <= '9')
		{
			nb += (*(str++) - '0') * pow;
			pow /= 10;
		}
	}
	return (nb * neg);
}