/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init_data2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 22:13:57 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/03 22:27:09 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	init_sdl_ressources_rend(t_data *d)
{
    d->win = NULL;
    if(0 != SDL_Init(SDL_INIT_VIDEO))
        exit_with_msg("Failed to Init SDL");
    if (!(d->win = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_SIZE_X, WIN_SIZE_Y, SDL_WINDOW_SHOWN)))
        exit_with_msg("Failed to create Window");
    if (!(d->rend = SDL_CreateRenderer(d->win, -1, SDL_RENDERER_ACCELERATED)))
        exit_with_msg("Failed to create Renderer");
    d->screen = SDL_CreateTexture(d->rend, SDL_PIXELFORMAT_ARGB32,
	SDL_TEXTUREACCESS_STREAMING, WIN_SIZE_X, WIN_SIZE_Y);
    d->mini_map = SDL_CreateTexture(d->rend, SDL_PIXELFORMAT_RGBA32,
	SDL_TEXTUREACCESS_STREAMING, MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y);
}

void	init_mini_map(t_data *d, t_map_data *map)
{
    d->p_mini_map_bg = NULL;
    create_mini_map(d, map);
    SDL_UpdateTexture(d->mini_map, NULL, d->p_mini_map_bg, MINI_MAP_SIZE_X * 4);
    d->p_player_pos = alloc_image(MINI_MAP_PLAYER_SIZE, MINI_MAP_PLAYER_SIZE);
    d->p_mini_map = alloc_image(MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y);
    draw_rectangle(d->p_player_pos, set_sdl_rect(0, 0, MINI_MAP_PLAYER_SIZE,
	MINI_MAP_PLAYER_SIZE), set_size(MINI_MAP_PLAYER_SIZE,
	MINI_MAP_PLAYER_SIZE), 0xFF0000FF);
    d->mini_map_player_pos = set_sdl_rect(WIN_SIZE_X - MINI_MAP_SIZE_X, 0,
	MINI_MAP_PLAYER_SIZE, MINI_MAP_PLAYER_SIZE);
}

int		init_menu(t_data *d)
{
	d->p_menu = NULL;
    d->menu_texture = SDL_CreateTexture(d->rend, SDL_PIXELFORMAT_ARGB32,
		SDL_TEXTUREACCESS_STREAMING, WIN_SIZE_X, WIN_SIZE_Y);
	d->p_menu = alloc_image(WIN_SIZE_X, WIN_SIZE_Y);
    ft_bzero(d->p_menu, sizeof(int) * MAP_SIZE_Y * MAP_SIZE_X);
	ft_bzero(&d->menu, sizeof(d->menu));
	init_background(d);
	return (0);
}

int		init_gameover(t_data *d, char **av) // doit etre initialisée après init_menu car partage la meme structure t_menu !
{
	d->p_gameover = NULL;
    d->gameover_texture = SDL_CreateTexture(d->rend, SDL_PIXELFORMAT_ARGB32,
		SDL_TEXTUREACCESS_STREAMING, WIN_SIZE_X, WIN_SIZE_Y);
	d->p_gameover = alloc_image(WIN_SIZE_X, WIN_SIZE_Y);
	ft_bzero(d->p_gameover, sizeof(int) * MAP_SIZE_Y * MAP_SIZE_X);
	init_gameover_background(d);
	return (0);
}

int		init_hud(t_data *d)
{
    d->hud_texture = SDL_CreateTexture(d->rend, SDL_PIXELFORMAT_ARGB32,
		SDL_TEXTUREACCESS_STREAMING, WIN_SIZE_X, WIN_SIZE_Y);
    d->p_hud = alloc_image(WIN_SIZE_X, WIN_SIZE_Y);
    ft_bzero(d->p_hud, sizeof(int) * MAP_SIZE_Y * MAP_SIZE_X);
	ft_bzero(&d->hud, sizeof(d->hud));
	init_hud_data(d);
	return (0);
}
