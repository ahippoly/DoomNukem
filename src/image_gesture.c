/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_gesture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:32:09 by alebui            #+#    #+#             */
/*   Updated: 2020/07/06 19:32:32 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

//OK
void put_pixel(unsigned int *pixels, SDL_Point p_pos, t_size img_size, unsigned int color)
{
    pixels[p_pos.x + p_pos.y * img_size.w] = color;
}

void calc_transparency(unsigned int *color_dst, unsigned int *color2, float alpha)
{
    int i;
    unsigned char *nb;
    unsigned char *nb2;
	float rev_alp;

    i = 0;
    nb = (unsigned char*)color_dst;
    nb2 = (unsigned char*)color2;
	rev_alp = 1 - alpha;
    while (i++ < 4)
        nb[i] = rev_alp * nb[i] + alpha * nb2[i];
}

unsigned int calc_transparency2(unsigned int color_dst, unsigned int color2, float alpha)
{
    int i;
    unsigned char *nb;
    unsigned char *nb2;
	float rev_alp;

    i = 0;
    nb = (unsigned char*)&color_dst;
    nb2 = (unsigned char*)&color2;
	rev_alp = 1 - alpha;
	if (!nb2[i])
		return (color_dst);
    while (i++ < 3)
		nb[i] = rev_alp * nb[i] + alpha * nb2[i];
	return (color_dst);
}

void put_pixel_transparency(unsigned int *pixels, SDL_Rect pos_size, unsigned int color, float alpha)
{
    unsigned int pixel_pos;
    unsigned int dst_color;

    pixel_pos = pos_size.x + pos_size.y * pos_size.w;
    dst_color = pixels[pixel_pos];
    calc_transparency(&color, &dst_color, alpha);
    pixels[pixel_pos] = color;
}

void put_pixel_attempt(unsigned int *pixels, SDL_Point p_pos, t_size img_size, unsigned int color)
{
    int pixel_pos;

    pixel_pos = p_pos.x + p_pos.y * img_size.w;
    if (!pixels[pixel_pos])
        pixels[pixel_pos] = color;
}
