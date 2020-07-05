/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 22:50:42 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/03 23:00:31 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	update_player_pos_mini_map(t_data *d)
{
	d->mini_map_player_pos.x = ft_range(MINI_MAP_SIZE_X * 0.5, 0, MINI_MAP_SIZE_X);
	d->mini_map_player_pos.y = ft_range(MINI_MAP_SIZE_Y * 0.5, 0, MINI_MAP_SIZE_Y);
}

void	print_player_look_vector(t_data *d, t_map_data *map, float rot)
{
    t_point		scale;
    SDL_Point	screen_player_pos;
    float		fov;

    fov =  d->fov_rad / 2;
    scale = calc_map_scale(map);
    screen_player_pos = create_point(d->mini_map_player_pos.x
		+ MINI_MAP_PLAYER_SIZE / 2, d->mini_map_player_pos.y
		+ MINI_MAP_PLAYER_SIZE / 2);
    draw_line(screen_player_pos, create_point(screen_player_pos.x
		+ cos(rot + fov) * 45, screen_player_pos.y + sin(rot + fov) * 45),
		(t_img){d->p_mini_map,
		(SDL_Rect){0, 0, MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y}, 0, 0}, 0xFF00DDDD);
    draw_line(screen_player_pos, create_point(screen_player_pos.x
		+ cos(rot - fov) * 45, screen_player_pos.y + sin(rot - fov) * 45),
		(t_img){d->p_mini_map,
		(SDL_Rect){0, 0, MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y}, 0, 0}, 0xFF00DDDD);
}

void	print_mini_map(t_data *d, t_map_data *map)
{
    SDL_Rect	tmp;

    tmp = set_sdl_rect(0, 0, MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y);
    ft_memcpy_int(d->p_mini_map, d->p_mini_map_bg, MINI_MAP_SIZE_X * MINI_MAP_SIZE_Y);
    print_player_look_vector(d, map, d->rot);
    SDL_UpdateTexture(d->mini_map, &tmp, d->p_mini_map, MINI_MAP_SIZE_X * 4);
    SDL_UpdateTexture(d->mini_map, &d->mini_map_player_pos, d->p_player_pos, MINI_MAP_PLAYER_SIZE * 4);
}