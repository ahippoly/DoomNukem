/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:42:16 by ahippoly          #+#    #+#             */
/*   Updated: 2020/06/27 18:04:09 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"
#include "proto_global.h"

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
    end = pos_size.y + pos_size.h;
    while (i < end)
    {
        pixels[pos_size.x + i * screen_length.w] = color;
		i++; //rajout alex car boucle inf
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

void	*ft_memcpy_int(unsigned int *dst, const unsigned int *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

float	get_dist(t_point pos1, t_point pos2)
{
	t_point diff;

	diff.x = pos2.x - pos1.x;
	diff.y = pos2.y - pos1.y;
	return (hypot(diff.x, diff.y));
}

t_rot	get_angle(t_point pos1, t_point pos2)
{
	t_point diff;
	t_rot rot;

	diff.x = (pos2.x - pos1.x);
	diff.y = (pos2.y - pos1.y);
	if (diff.x > 0)
	{
		rot.rot = atan(diff.y / diff.x);
		rot.cos_rot = cos(rot.rot);
	}
	else
	{
		rot.rot = -atan(diff.y / diff.x);
		rot.cos_rot = -cos(rot.rot);
	}
	rot.sin_rot = sin(rot.rot);
	return (rot);
}

float ft_interpolate(float val1, float val2, float scale)
{
	return(val1 * (1 - scale) + val2 * (scale));
}

void	*ft_memmove2(void *dst, const void *src, size_t len)
{
	char	*csrc;
	char	*cdst;
	size_t	i;

	if (src == dst)
		return (dst);
	csrc = (char *)src;
	cdst = (char *)dst;
	if (src < dst)
	{
		i = len;
		while (i-- > 0)
			cdst[i] = csrc[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	return (dst);
}

void del_from_array(void *list, int *size, void *to_remove, int obj_size)
{
	int i;

	i = 0;
	while (i < *size)
	{
		printf("i = %i, size = %i\n", i, *size);
		if ((list + obj_size * i) == to_remove)
			break;
		i++;
	}
	(*size)--;
	printf("deleted from array, size = %i\n", *size);
	ft_memmove2(list + obj_size * i, list + obj_size * (i + 1), (*size - i) * obj_size);
}

void print_text_screen(unsigned int *p_tab, t_img *text, SDL_Rect draw)
{
	SDL_Point	end;
	t_point		t_scale;
	t_point		t_step;
	int ty;
	float tx_start;
	int x_start;
	unsigned int *pixels;

	t_step.x = (float)text->w / draw.w;
	t_step.y = (float)text->h / draw.h;
	end.x = ft_min(draw.x + draw.w, WIN_SIZE_X);
	end.y = ft_min(draw.y + draw.h, WIN_SIZE_Y) * WIN_SIZE_Y;
	tx_start = 0;
	if (draw.x < 0)
		tx_start = t_step.x * -draw.x;
	if (draw.y < 0)
		t_scale.y = t_step.y * -draw.y;
	draw.y = ft_max(draw.y, 0) * WIN_SIZE_Y;
	x_start = ft_max(draw.x, 0);
	pixels = (unsigned int*)text->pixels;
	while (draw.y < end.y)
	{
		t_scale.x = tx_start;
		ty = (int)t_scale.y * text->w;
		draw.x = x_start;
		while (draw.x < end.x)
		{
			//printf("draw : %d,%d, t_scale : %f,%f\n", draw.x, draw.y, t_scale.x, t_scale.y);
			p_tab[draw.x + draw.y] = pixels[(int)t_scale.x + ty];
			t_scale.x += t_step.x;
			draw.x++;
		}
		t_scale.y += t_step.y;
		draw.y += WIN_SIZE_Y;
	}

}

void    copy_frame(unsigned int *dst, SDL_Rect dst_size, unsigned int *src, SDL_Rect pos_size)
{
    SDL_Point pos;
    SDL_Point pos2;
    SDL_Point frame_max;

    pos.y = pos_size.y * pos_size.w;
	pos2.y = 0;
	frame_max.y = dst_size.h * dst_size.w;
    while (pos2.y < frame_max.y)
    {
        pos.x = pos_size.x;
        pos2.x = 0;
        while (pos2.x < dst_size.w)
        {
        	dst[pos2.x + pos2.y] = src[pos.x + pos.y];
			pos2.x++;
            pos.x++;
        }
        pos2.y += dst_size.w;
        pos.y += pos_size.w;
    }
}

void    copy_frame_scale(unsigned int *dst, SDL_Rect dst_size, unsigned int *src, SDL_Rect pos_size)
{
    t_point pos;
    SDL_Point pos2;
    SDL_Point frame_max;
	t_point		step;
	int y;
	
	pos2.y = 0;
	frame_max.y = dst_size.h * dst_size.w;
	step.x = (double)dst_size.x / dst_size.w;
	step.y = (double)dst_size.y / dst_size.h;
	// printf("dst_x : %f,%f\n", step.x, step.y);
	// printf("step : %f,%f\n", step.x, step.y);
	pos.y = pos_size.y;
    y = pos_size.y * pos_size.w;
    while (pos2.y < frame_max.y)
    {
        pos.x = pos_size.x;
        pos2.x = 0;
        while (pos2.x < dst_size.w)
        {
        	dst[pos2.x + pos2.y] = src[(int)pos.x + y];
			pos2.x++;
            pos.x += step.x;
        }
        pos2.y += dst_size.w;
		pos.y += step.y;
        y = (int)pos.y * pos_size.w;
    }
}

SDL_Texture *t_img2sdl_text(SDL_Renderer *rend , t_img src)
{
	SDL_Texture *new;

	new = SDL_CreateTexture(rend, SDL_PIXELFORMAT_ARGB32, SDL_TEXTUREACCESS_STREAMING, src.w, src.h);
	SDL_UpdateTexture(new, NULL, src.pixels, src.w * 4);
	return (new);
}