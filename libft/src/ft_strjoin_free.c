/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 23:04:14 by alebui            #+#    #+#             */
/*   Updated: 2019/03/12 13:18:51 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strjoin_free(char **s1, char *s2)
{
	size_t	len;
	char	*strjoin;

	if ((!s1 || !*s1) && !s2)
		return (NULL);
	len = 0;
	if (s1 && *s1)
		len += ft_strlen(*s1);
	if (s2)
		len += ft_strlen(s2);
	if (!(strjoin = ft_strnew(len)))
		return (NULL);
	if (s1 && *s1)
		strjoin = ft_strcpy(strjoin, *s1);
	if (s2)
		strjoin = ft_strcat(strjoin, s2);
	ft_strdel(s1);
	return (strjoin);
}

char		*ft_strjoin_free2(char *s1, char **s2)
{
	size_t	len;
	char	*strjoin;

	if ((!s2 || !*s2) && !s1)
		return (NULL);
	len = 0;
	if (s1)
		len += ft_strlen(s1);
	if (*s2 && s2)
		len += ft_strlen(*s2);
	if (!(strjoin = ft_strnew(len)))
		return (NULL);
	if (s1)
		strjoin = ft_strcpy(strjoin, s1);
	if (s2 && *s2)
		strjoin = ft_strcat(strjoin, *s2);
	ft_strdel(s2);
	return (strjoin);
}
