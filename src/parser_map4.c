/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:25:08 by alebui            #+#    #+#             */
/*   Updated: 2020/07/09 15:31:07 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

char		*skip_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

char		*skip_until_num(char *str, char limit)
{
	while ((*str < '0' || *str > '9') && *str != '-' && *str != '\0' &&
			*str != limit)
		str++;
	return (str);
}

char		*skip_until_char(char *str, char searched, char limit)
{
	while (*str != '\0' && *str != searched && *str != limit)
		str++;
	return (str);
}

int			is_white_space(char c)
{
	if ((c < 14 && c > 8) || c == 32)
		return (1);
	return (0);
}
