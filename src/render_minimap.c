/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 22:50:42 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/08 16:19:19 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	update_player_pos_mini_map(t_data *d)
{
	d->mini_map_player_pos.x = ft_range(MINIMAPSIZEX * 0.5,
			0, MINIMAPSIZEX);
	d->mini_map_player_pos.y = ft_range(MINIMAPSIZEY * 0.5,
			0, MINIMAPSIZEY);
}

void	print_player_look_vector(t_data *d, float rot)
{
	SDL_Point	screen_player_pos;
	float		fov;

	fov = d->fov_rad / 2;
	screen_player_pos = create_point(d->mini_map_player_pos.x
		+ MINI_MAP_PLAYER_SIZE / 2, d->mini_map_player_pos.y
		+ MINI_MAP_PLAYER_SIZE / 2);
	draw_line(screen_player_pos, create_point(screen_player_pos.x
		+ cos(rot + fov) * 45, screen_player_pos.y + sin(rot + fov) * 45),
		(t_img){d->p_mini_map,
		(SDL_Rect){0, 0, MINIMAPSIZEX, MINIMAPSIZEY}, 0, 0}, 0xFF00DDDD);
	draw_line(screen_player_pos, create_point(screen_player_pos.x
		+ cos(rot - fov) * 45, screen_player_pos.y + sin(rot - fov) * 45),
		(t_img){d->p_mini_map,
		(SDL_Rect){0, 0, MINIMAPSIZEX, MINIMAPSIZEY}, 0, 0}, 0xFF00DDDD);
}

void	print_mini_map(t_data *d)
{
	SDL_Rect	tmp;

	tmp = set_sdl_rect(0, 0, MINIMAPSIZEX, MINIMAPSIZEY);
	ft_memcpy_int(d->p_mini_map, d->p_mini_map_bg, MINIMAPSIZEX * MINIMAPSIZEY);
	print_player_look_vector(d, d->rot);
	if ((SDL_UpdateTexture(d->mini_map, &tmp,
		d->p_mini_map, MINIMAPSIZEX * 4)) < 0)
		exit_game(d, "error : failed to update texture");
	if ((SDL_UpdateTexture(d->mini_map, &d->mini_map_player_pos,
		d->p_player_pos, MINI_MAP_PLAYER_SIZE * 4)) < 0)
		exit_game(d, "error : failed to update texture");
}
