/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 22:14:12 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/14 02:21:25 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

static void	init_malloc_floor(t_data *d)
{
	int	i;
	int nb_max_floor;

	nb_max_floor = NB_WALL_MAX / 2;
	i = 0;
	while (i < nb_max_floor)
	{
		if (!(d->fl[i] = malloc_floor(WIN_SIZE_Y)))
			exit_game(d, "error : failed to malloc floor");
		i++;
	}
}

void		malloc_data_init(t_data *d)
{
	if (!(d->props = malloc_props(NB_MAX_PROPS)))
		exit_game(d, "error : failed to malloc props");
	if (!(d->mobs = malloc_mob(NB_MAX_MOBS)))
		exit_game(d, "error : failed to malloc mobs");
	if (!(d->obj_list = malloc_obj(NB_MAX_OBJ)))
		exit_game(d, "error : failed to malloc objects");
	if (!(d->repulsed = malloc_obj_tab(NB_MAX_MOBS + NB_MAX_PROPS)))
		exit_game(d, "error : failed to malloc objects tab");
	if (!(d->texture = malloc_img(NB_TEXTURE)))
		exit_game(d, "error : failed to malloc image");
	if (!(d->img = malloc_img(NB_IMG)))
		exit_game(d, "error : failed to malloc image");
	if (!(d->sprite_img = malloc_img(NB_SPRITE)))
		exit_game(d, "error : failed to malloc image");
	if (!(d->fl = malloc_floor_tab(NB_WALL_MAX / 2)))
		exit_game(d, "error : failed to malloc floor");
	if (!(d->p_screen = alloc_image(WIN_SIZE_X, WIN_SIZE_Y)))
		exit_game(d, "error : failed to malloc screens pixel");
	init_malloc_floor(d);
}

void		init_data_var(t_data *d)
{
	malloc_data_init(d);
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
	d->player_pos = create_t_point(0.500148 + d->map.player_spawn.x,
		0.500148 + d->map.player_spawn.y);
	d->rot = -1.00015592 * M_PI_2;
	d->fov = (float)FOV_ANGLE / 90;
	d->fov_rad = ((float)FOV_ANGLE * M_PI_2) / 90;
	d->skybox = ft_load_bmp2(SKY_PATH_0, BMP_TYPE_BGRA, 0);
}

void		init_data(t_data *d, int ac, char **av)
{
	ft_putendl("init data...");
	ft_bzero(d, sizeof(t_data));
	init_sdl_ressources_rend(d);
	init_sprite(d);
	init_hud(d);
	init_menu(d);
	init_gameover(d);
	init_winscreen(d);
	init_ttf(d);
	if (ac > 1)
		d->map = read_map(av[1]);
	else
		d->map = read_map("maps/editor_map_0");
	if (d->map.is_valid == 0)
		exit_with_msg("error : wrong map file\n");
	init_data_var(d);
	init_mini_map(d, &d->map);
	ft_bzero(d->p_screen, sizeof(int) * MAPSIZEY * MAPSIZEX);
	load_bmp_files(d);
	init_sprites_img(d);
	init_rend_img(d);
	load_icons(d, &d->map);
	init_obj_list(d);
	d->jetpack = 0;
	d->run_game = MENU;
}
