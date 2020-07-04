/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 22:14:12 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/04 22:25:12 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void init_data_var(t_data *d)
{
	d->screen_height = HALF_WIN_SIZE_Y;
    d->player_height = 0;
    d->z_force = 0;
    d->air_time = 0;
    d->z_ground = 2;
    d->z_pos = 10;
    d->z_offset = PLAYER_HEIGHT;
    d->speed_modifier = 1;
    d->framerate = 0;
    d->time = 0;
	d->grabbed_wall = NULL;
	d->nb_repulsed = 0;
	d->bullet = 0;
	d->shoot_repeat = 0;
	d->player_pos = create_t_point(0.500148 + d->map.player_spawn.x, 0.500148 + d->map.player_spawn.y);
    d->rot = -1.00015592 * M_PI_2; 
	d->fov = (float)FOV_ANGLE / 90;
	d->fov_rad = ((float)FOV_ANGLE * M_PI_2) / 90;
	d->skybox = read_img_surface(SKY_PATH_0, SDL_PIXELFORMAT_ARGB32);
}

void init_data(t_data *d, int ac, char **av)
{
	ft_putendl("init data...");
    init_sdl_ressources_rend(d);
	init_sprite(d);
	init_hud(d);
	init_menu(d);
	init_gameover(d, av); //doit etre avant le check des arguments
	init_ttf(d);
	if (ac > 1)
	{
		d->map = read_map(av[1]);
	}
	else
    	d->map = read_map("maps/editor_map_0");
	if (d->map.is_valid == 0)
		exit_with_msg("error : wrong map file\n");
    init_mini_map(d, &d->map);
	init_data_var(d);
    d->p_screen = alloc_image(WIN_SIZE_X, WIN_SIZE_Y);
    ft_bzero(d->p_screen, sizeof(int) * MAP_SIZE_Y * MAP_SIZE_X);
    load_bmp_files(d);
	init_sprites_img(d);
	init_rend_img(d);
	load_icons(d, &d->map);
	init_obj_list(d);
    d->jetpack = 0;
}
