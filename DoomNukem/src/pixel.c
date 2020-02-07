/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:05:36 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/07 22:54:16 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

uint32_t		get_pixel_floor(t_enval *env, int si, float x, float y)
{
	uint8_t			*p;
	SDL_Surface		*surface;
	Uint32			pixel;

	surface = env->wtex[si].img;
	p = (uint8_t *)surface->pixels + (int)y * surface->pitch
		+ (int)x * surface->format->BytesPerPixel;
	pixel = (p[2] | p[1] << 8 | p[0] << 16 | 255 << 24);
	return (fog(env, pixel, env->ray.distcurrent));
}

uint32_t		get_pixel_wall(t_enval *env, int si, float x, float y)
{
	uint8_t			*p;
	SDL_Surface		*surface;
	Uint32			pixel;

	surface = env->wtex[si].img;
	p = (uint8_t *)surface->pixels + (int)y * surface->pitch
		+ (int)x * surface->format->BytesPerPixel;
	pixel = (p[2] | p[1] << 8 | p[0] << 16 | 255 << 24);
	return (fog(env, pixel, env->ray.perpwalldist));
}

void			put_pixel(SDL_Surface *surface, int x, int y, uint32_t color)
{
	unsigned int	*pixels;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	pixels = (unsigned int *)surface->pixels;
	pixels[x + (y * WIN_W)] = color;
}
