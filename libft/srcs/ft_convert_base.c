/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:06:51 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/15 18:11:47 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_base(char *str)
{
	int	len;
	int	i;

	len = 0;
	while (str[len])
	{
		if (str[len] == '+' || str[len] == '-')
			return (0);
		i = len;
		while (i-- >= 0)
			if (str[i] == str[len])
				return (0);
		len++;
	}
	return (len);
}

static void		ft_fake_putnbr_base(int nb, char *base, char **str, int i)
{
	int		l_base;
	long	nbr;

	nbr = nb;
	l_base = check_base(base);
	if (l_base >= 2)
	{
		if (nbr < 0)
		{
			str[0][0] = '-';
			ft_fake_putnbr_base(-nbr, base, str, 1);
		}
		else if (nbr >= l_base)
		{
			ft_fake_putnbr_base(nbr / l_base, base, str, i + 1);
			ft_fake_putnbr_base(nbr % l_base, base, str, i);
		}
		else
			str[0][i] = base[nbr];
	}
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		number;
	int		j;
	char	*str;
	char	tmp;

	number = ft_atoi_base(nbr, base_from);
	if (!(str = (char *)malloc(sizeof(char) * 50)))
		return (0);
	i = 0;
	while (i < 50)
		str[i++] = 0;
	ft_fake_putnbr_base(number, base_to, &str, 0);
	i = 0;
	str += (str[i] == '-' ? 1 : 0);
	j = 0;
	while (str[j])
		j++;
	while (i < j / 2)
	{
		tmp = str[i];
		str[i] = str[j - i - 1];
		str[j - i++ - 1] = tmp;
	}
	return (str[-1] == '-' ? str - 1 : str);
}
