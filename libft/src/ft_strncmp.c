/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:24:24 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/21 18:31:02 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*(s1) == *(s2) && *s2 != 0 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*((unsigned char*)s1) - *((unsigned char*)s2));
}
