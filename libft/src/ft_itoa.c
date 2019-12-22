/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:19:12 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/24 17:52:56 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	char	*ft_special_case(int n, char *str)
{
	if (n == -2147483648)
	{
		if (!(str = (char*)malloc(sizeof(*str) * 12)))
			return (NULL);
		ft_strcpy(str, "-2147483648");
	}
	else
	{
		if (!(str = (char*)malloc(sizeof(*str) * 2)))
			return (NULL);
		ft_strcpy(str, "0");
	}
	return (str);
}

static	void	ft_itoa_rec(int n, char *str, int i)
{
	if (n > 0)
	{
		ft_itoa_rec(n / 10, str, i - 1);
		str[i] = n % 10 + 48;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	int		n2;
	int		i;
	int		negative;

	negative = 0;
	str = NULL;
	i = 1;
	if (n == -2147483648 || n == 0)
		return (ft_special_case(n, str));
	else if (n < 0)
		i++ && (n *= -1) && (negative = 1);
	n2 = n;
	while ((n2 /= 10) > 0)
		i++;
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	str[i] = 0;
	if (negative == 1)
		str[0] = '-';
	ft_itoa_rec(n, str, i - 1);
	return (str);
}
