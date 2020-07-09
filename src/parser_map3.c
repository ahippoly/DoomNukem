/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:24:24 by alebui            #+#    #+#             */
/*   Updated: 2020/07/09 15:30:21 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

int			read_param(char *chunk, char *key, int *to_fill)
{
	int error;
	int i;

	error = 1;
	chunk = ft_strstr(chunk, key);
	if (chunk)
	{
		chunk = skip_until_char(chunk, ' ', ';');
		chunk = skip_until_num(chunk, ';');
		if (*chunk == ';')
			return (error);
		*to_fill = ft_atoi(chunk);
		chunk = skip_until_char(chunk, ',', ';');
		i = 0;
		while (*chunk == ',')
		{
			*(to_fill + ++i) = ft_atoi(++chunk);
			chunk = skip_until_char(chunk, ',', ';');
		}
		error = 0;
	}
	return (error);
}

int			read_paramf(char *chunk, char *key, float *to_fill)
{
	int error;
	int i;

	error = 1;
	chunk = ft_strstr(chunk, key);
	if (chunk)
	{
		chunk = skip_until_char(chunk, ' ', ';');
		chunk = skip_until_num(chunk, ';');
		if (*chunk == ';')
			return (error);
		*to_fill = ft_fatoi(chunk);
		chunk = skip_until_char(chunk, ',', ';');
		i = 0;
		while (*chunk == ',')
		{
			*(to_fill + ++i) = ft_fatoi(++chunk);
			chunk = skip_until_char(chunk, ',', ';');
		}
		error = 0;
	}
	return (error);
}

float		calc_line_angle(t_point p1, t_point p2)
{
	float	a;

	if (p2.x - p1.x < INTER_TOLERANCE && p2.x - p1.x > -INTER_TOLERANCE)
		a = 2147483647;
	else
		a = (float)(p2.y - p1.y) / (p2.x - p1.x);
	return (atan(a));
}
