/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:42:16 by ahippoly          #+#    #+#             */
/*   Updated: 2020/06/14 21:52:25 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_header.h"
#include "editor.h"

t_point create_t_point(float x, float y)
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

SDL_Rect set_sdl_rect(int x, int y, int w, int h)
{
    SDL_Rect rect;

    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    return (rect);
}

t_size set_size(int w, int h)
{
    t_size size;

    size.w = w;
    size.h = h;
    return (size);
}

SDL_Rect adapt_border(SDL_Rect pos_size, t_size max)
{
    adapt_min(&pos_size.x, &pos_size.w);
    adapt_min(&pos_size.y, &pos_size.h);
    adapt_max(&pos_size.x, &pos_size.w, max.w);
    adapt_max(&pos_size.y, &pos_size.h, max.h);
    return (pos_size);
}

void draw_rectangle(unsigned int *pixels, SDL_Rect rect, t_size screen_size, int color)
{
    int x;
    int y;
    SDL_Point end;

    rect = adapt_border(rect, screen_size);
    end.x = rect.x + rect.w;
    end.y = rect.y + rect.h;
    y = rect.y;
    while (y < end.y)
    {
        x = rect.x;
        while (x < end.x)
            pixels[x++ + y * screen_size.w] = color;
        y++;
    }
}

void create_straight_line(unsigned int *pixels, SDL_Rect pos_size, t_size screen_length, int color)
{
    int i;
    int end;

    pos_size = adapt_border(pos_size, screen_length);
    i = pos_size.x;
    end = pos_size.x + pos_size.w;
    while (i < end)
    {
        pixels[i + pos_size.y * screen_length.w] = color;
        i++;
    }
}

void create_straight_column(unsigned int *pixels, SDL_Rect pos_size, t_size screen_length, int color)
{
    int i;
    int end;

    pos_size = adapt_border(pos_size, screen_length);
    i = pos_size.y;
    end = pos_size.x + pos_size.w;
    while (i < end)
    {
        pixels[pos_size.x + i * screen_length.w] = color;
    }
}

void adapt_min(int *pos, int *length)
{
    if (*pos < 0)
    {
        *length += *pos;
        *pos = 0;
    }
}

void adapt_max(int *pos, int *length, int max)
{
    if (*pos + *length > max)
        *length = ft_max(0, max - *pos);
}

float get_float_part(float value)
{
    int int_part;

    int_part = (int)value;
    return (value - int_part - INTER_TOLERANCE);
}

t_point sdl_p_to_t_p(SDL_Point p)
{
	t_point new;

	new.x = p.x;
	new.y = p.y;
	return (new);
}

t_rot calc_sin_cos_rot(float rot)
{
	t_rot new;

	new.rot = rot;
	new.cos_rot = cos(rot);
	new.sin_rot = sin(rot);
	return (new);
}

void sort_int(int *a, int *b)
{
	int *tmp;

	if (*a > *b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
}