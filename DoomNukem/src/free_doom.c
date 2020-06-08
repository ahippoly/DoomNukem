/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_doom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 09:51:35 by apons             #+#    #+#             */
/*   Updated: 2020/02/04 20:27:31 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** This function frees everything that is necessary to free.
*/

void	free_map(t_mapinfo *map, int wl)
{
	int i;

	i = -1;
	while (++i < wl)
	{
		if (map->walls[i])
		{
			free(map->walls[i]);
			map->walls[i] = NULL;
		}
	}
	free(map->walls);
	map->walls = NULL;
}

void	free_texture_weapon(t_sprite **wptex, int id, int texture_number)
{
	int j;

	j = -1;
	if (wptex[id])
	{
		while (++j < texture_number)
			SDL_FreeSurface(wptex[id][j].img);
		free(wptex[id]);
	}
}

void	free_textures(t_sprite *wtex, t_sprite **wptex)
{
	int i;

	i = -1;
	ft_putendl("Faulty one's walls !");
	while (++i < WALL_TEXTURE_NUMBER)
	{
		if (wtex && wtex[i].img)
			SDL_FreeSurface(wtex[i].img);
	}
	i = -1;
	ft_putendl("Faulty one's weapons !");
	if (wptex)
	{
		free_texture_weapon(wptex, 0, WEAPON_TEXTURES_MELEE);
		free_texture_weapon(wptex, 1, WEAPON_TEXTURES_PISTOL);
		free_texture_weapon(wptex, 2, WEAPON_TEXTURES_SHOTGUN);
		free_texture_weapon(wptex, 3, WEAPON_TEXTURES_SMG);
		free_texture_weapon(wptex, 4, WEAPON_TEXTURES_BFG);
		free_texture_weapon(wptex, 5, 1);
	}
	free(wptex);
	wptex = NULL;
}

/*
** Make sure to add "free_textures(env->wtex, env->wptex);" before "free(env);"
*/

void	free_doom(t_enval *env, int i)
{
	if (i == 1)
		free(env->linebuff);
	env->map.walls ? free_map(&env->map, env->wl) : 0;
	free(env);
	env = NULL;
}
