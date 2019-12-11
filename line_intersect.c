/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:48:11 by ahippoly          #+#    #+#             */
/*   Updated: 2019/10/15 16:44:56 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/SDL2/SDL.h"
#include "libft/libft.h"

SDL_Point segment_intersect(SDL_Point p1, SDL_Point p2, SDL_Point p3, SDL_Point p4)
{
	double a1;
	double a2;
	double b1;
	double b2;
	SDL_Point inter;

	if (p2.x - p1.x != 0 && p4.x - p3.x != 0)
	{
		a1 = (double)(p2.y - p1.y) / (p2.x - p1.x);
		b1 = p1.y - (double)p1.x * a1;

		a2 = (double)(p4.y - p3.y) / (p4.x - p3.x);
		b2 = p3.y - (double)p3.x * a2;
		
		inter.x = (double)(b2 - b1) / (a1  - a2);
		//printf("inter.x = %f, max x = %f, min x = %f\n", inter.x, ft_fmax(p2.x, p1.x), ft_fmin(p2.x, p1.x));
		if (inter.x > ft_max(p1.x, p2.x) || inter.x < ft_min(p1.x, p2.x))
		{
			inter.x = - 42;
			inter.y = - 42;
		}
		else
			inter.y = a1 * inter.x + b1;
	}
	else if (p4.x - p3.x != 0)
	{
		a2 = (double)(p4.y - p3.y) / (p4.x - p3.x);
		b2 = p3.y - (double)p3.x * a2;
		inter.x = p1.x;
		inter.y = a2 * inter.x + b2;
		//printf("inter.y = %f, max x = %f, min x = %f\n", inter.y, ft_fmax(p2.y, p1.y), ft_fmin(p2.y, p1.y));
		if (inter.y > ft_max(p2.y, p1.y) || inter.y < ft_min(p2.y, p1.y))
		{
			inter.x = - 42;
			inter.y = - 42;
		}
	}
	else if (p2.x - p1.x != 0)
	{
		a1 = (double)(p2.y - p1.y) / (p2.x - p1.x);
		b1 = p1.y - (double)p1.x * a1;
        inter.x = p3.x;
        inter.y = a1 * inter.x + b1;
		// printf("inter.y = %f, max x = %f, min x = %f\n", inter.y, ft_fmax(p2.y, p1.y), ft_fmin(p2.y, p1.y));
        if (inter.y > ft_max(p4.y, p3.y) || inter.y < ft_min(p4.y, p3.y))
        {
            inter.x = - 42;
            inter.y = - 42;
        }
	}
	else
	{
		inter.x = - 42;
		inter.y = - 42;
	}
	//printf("a1 = %f, b1 = %f\na2 = %f, b2 = %f\n",a1, b1, a2, b2);
	//printf("sin_rot = %f, cos_rot = %f\n", sin_rot, cos_rot);
	//printf("inter.x = %f, inter.y = %f\n", inter.x, inter.y);
	return (inter);
}
