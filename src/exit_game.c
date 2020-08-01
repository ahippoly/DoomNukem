/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 11:08:23 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/17 14:23:57 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

int		free_floor(t_data *d)
{
	int	i;

	i = 0;
	while (d->fl[i])
	{
		if (d->fl[i])
			free(d->fl[i]);
		i++;
	}
	free(d->fl);
	return (0);
}

void	free_data2(t_data *d)
{
	if (d->mobs)
		free(d->mobs);
	if (d->obj_list)
		free(d->obj_list);
	if (d->texture)
		free(d->texture);
	if (d->img)
		free(d->img);
	if (d->sprite_img)
		free(d->sprite_img);
	if (d->p_menu)
		free(d->p_menu);
	if (d->grabbed_wall)
		free(d->grabbed_wall);
	free_floor(d);
}

void	free_data_ptr(t_data *d)
{
	free_img_list(d);
	if (d->p_win)
		free(d->p_win);
	if (d->skybox.pixels)
		free(d->skybox.pixels);
	if (d->map.room_list)
		free(d->map.room_list);
	if (d->map.wall_list)
		free(d->map.wall_list);
	if (d->map.icon_list)
		free(d->map.icon_list);
	if (d->p_screen)
		free(d->p_screen);
	if (d->mini_map)
		free(d->p_mini_map);
	if (d->p_mini_map_bg)
		free(d->p_mini_map_bg);
	if (d->p_player_pos)
		free(d->p_player_pos);
	if (d->p_hud)
		free(d->p_hud);
	if (d->props)
		free(d->props);
	free_data2(d);
}

void	free_sdl_ptr_data(t_data *d)
{
	if (d->screen)
		SDL_DestroyTexture(d->screen);
	if (d->mini_map)
		SDL_DestroyTexture(d->mini_map);
	if (d->hud_texture)
		SDL_DestroyTexture(d->hud_texture);
	if (d->gameover_texture)
		SDL_DestroyTexture(d->gameover_texture);
	if (d->win_texture)
		SDL_DestroyTexture(d->win_texture);
	if (d->rend)
		SDL_DestroyRenderer(d->rend);
	if (d->win)
		SDL_DestroyWindow(d->win);
}

void	exit_game(t_data *d, char *msg)
{
	ft_putendl(msg);
	free_menu(d);
	free_gameover(d);
	free_hud(&d->hud);
	free_mobs_sprite(d);
	free_data_ptr(d);
	clean_sounds(d);
	free_sdl_ptr_data(d);
	read_char_table(1);
	quit_ttf(d);
	SDL_Quit();
	ft_putendl("bye !");
	exit(0);
}
