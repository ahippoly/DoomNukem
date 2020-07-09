/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init_data2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 22:13:57 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/09 14:37:00 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	init_mini_map(t_data *d, t_map_data *map)
{
	d->p_mini_map_bg = NULL;
	create_mini_map(d, map);
	if ((SDL_UpdateTexture(d->mini_map, NULL, d->p_mini_map_bg,
		MINIMAPSIZEX * 4)) < 0)
		exit_game(d, "error : failed to update texture");
	if (!(d->p_player_pos = alloc_image(MINIMAPPLAYERSIZE, MINIMAPPLAYERSIZE)))
		exit_game(d, "error : failed to malloc player positions");
	if (!(d->p_mini_map = alloc_image(MINIMAPSIZEX, MINIMAPSIZEY)))
		exit_game(d, "error : failed to malloc mini map");
	draw_rectangle(d->p_player_pos, set_sdl_rect(0, 0, MINIMAPPLAYERSIZE,
		MINIMAPPLAYERSIZE), set_size(MINIMAPPLAYERSIZE,
		MINIMAPPLAYERSIZE), RED);
	d->mini_map_player_pos = set_sdl_rect(WIN_SIZE_X - MINIMAPSIZEX, 0,
		MINIMAPPLAYERSIZE, MINIMAPPLAYERSIZE);
}

int		init_menu(t_data *d)
{
	d->p_menu = NULL;
	if (!(d->menu_texture = SDL_CreateTexture(d->rend, SDL_PIXELFORMAT_ARGB32,
		SDL_TEXTUREACCESS_STREAMING, WIN_SIZE_X, WIN_SIZE_Y)))
		exit_game(d, "error : failed to create texture");
	if (!(d->p_menu = alloc_image(WIN_SIZE_X, WIN_SIZE_Y)))
		exit_game(d, "error : failed to malloc menu pixels");
	ft_bzero(d->p_menu, sizeof(int) * MINIMAPSIZEY * MINIMAPSIZEX);
	ft_bzero(&d->menu, sizeof(d->menu));
	init_backgroundd(d, &d->menu.menu_bg_t, MENU_BG_PATH);
	return (0);
}

int		init_gameover(t_data *d)
{
	d->p_gameover = NULL;
	if (!(d->gameover_texture = SDL_CreateTexture(d->rend,
		SDL_PIXELFORMAT_ARGB32,
		SDL_TEXTUREACCESS_STREAMING, WIN_SIZE_X, WIN_SIZE_Y)))
		exit_game(d, "error : failed to create texture");
	if (!(d->p_gameover = alloc_image(WIN_SIZE_X, WIN_SIZE_Y)))
		exit_game(d, "error : failed to malloc gameover pixels");
	ft_bzero(d->p_gameover, sizeof(int) * WIN_SIZE_X * WIN_SIZE_Y);
	init_backgroundd(d, &d->menu.gameover_t, GAMEOVER_PATH);
	return (0);
}

int		init_hud(t_data *d)
{
	if (!(d->hud_texture = SDL_CreateTexture(d->rend, SDL_PIXELFORMAT_ARGB32,
		SDL_TEXTUREACCESS_STREAMING, WIN_SIZE_X, WIN_SIZE_Y)))
		exit_game(d, "error : failed to create texture");
	if (!(d->p_hud = alloc_image(WIN_SIZE_X, WIN_SIZE_Y)))
		exit_game(d, "error : failed to malloc hud pixels");
	ft_bzero(d->p_hud, sizeof(int) * MINIMAPSIZEY * MINIMAPSIZEX);
	ft_bzero(&d->hud, sizeof(d->hud));
	init_hud_data(d);
	return (0);
}

int		init_winscreen(t_data *d)
{
	d->p_win = NULL;
	if (!(d->win_texture = SDL_CreateTexture(d->rend, SDL_PIXELFORMAT_ARGB32,
		SDL_TEXTUREACCESS_STREAMING, WIN_SIZE_X, WIN_SIZE_Y)))
		exit_game(d, "error : failed to create texture");
	if (!(d->p_win = alloc_image(WIN_SIZE_X, WIN_SIZE_Y)))
		exit_game(d, "error : failed to malloc gameover pixels");
	ft_bzero(d->p_win, sizeof(int) * MAP_SIZE_Y * MAP_SIZE_X);
	init_backgroundd(d, &d->menu.win_t, WIN_BG_PATH);
	return (0);
}