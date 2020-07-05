/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:37:39 by alebui            #+#    #+#             */
/*   Updated: 2020/07/05 21:00:57 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		reverse(char *str, int len)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int			afterfloat_to_str(int x, char *str, int d)
{
	int		i;

	i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i < d)
		str[i++] = '0';
	reverse(str, i);
	str[i] = '\0';
	return (i);
}
 
char		*ft_ftoa(float n, char *res, int afterpoint)
{
	int		ipart;
	float	fpart;
	int		i;
	char	neg;
	char	*ret;

	neg = (n < 0) ? 'n' : 'p';
	ipart = abs((int)n);
	if (afterpoint == 0)
		return (ret = ft_itoa(ipart));
	fpart = n - (float)ipart;
	i = afterfloat_to_str(ipart, res, 0);
	if (afterpoint == 0)
		return (NULL);
	res[i] = '.';
	fpart = fpart * ft_pow(10, afterpoint);
	afterfloat_to_str(abs((int)fpart), res + i + 1, afterpoint);
	ret = ft_itoa(ipart);
	ret = ft_strjoinfree(res, ret, 1);
	if (ipart == 0)
		ret = ft_strjoinfree("0", ret, 1);
	if (neg == 'n')
		ret = ft_strjoinfree("-", ret, 1);
	ft_strdel(&res);
	return (ret);
}
