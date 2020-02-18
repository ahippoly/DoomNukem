/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:42:16 by ahippoly          #+#    #+#             */
/*   Updated: 2019/03/26 15:43:06 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_header.h"
#include "editor.h"

t_point create_t_point(double x, double y)
{
	t_point p;
	p.x = x;
	p.y = y;
	return (p);
}

t_range create_t_range(int start, int end)
{
	t_range range;

	range.start = start;
	range.end = end;
	return (range);
}

t_size create_t_size(int w, int h)
{
	t_size size;

	size.w = w;
	size.h = h;
	return (size);
}