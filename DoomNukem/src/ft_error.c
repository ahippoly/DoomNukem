/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 08:50:09 by apons             #+#    #+#             */
/*   Updated: 2020/02/04 20:36:33 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** This function checks for errors in append_val.
*/

void		ft_checkappval(int reader, int i, t_enval *env, t_mapinfo map)
{
	int p_x;
	int p_y;

	p_x = (int)env->player.pos.x + i - i;
	p_y = (int)env->player.pos.y;
	if (reader == -1)
		ft_error("file reading failed.", env, 0);
	if (i != map.height)
		ft_error("map height is incorrect.", env, 0);
	if (map.walls[p_x][p_y] == 1)
		ft_error("player is in a wall.", env, 0);
	p_x = -1;
	while (++p_x < map.height)
	{
		p_y = -1;
		while (++p_y < map.width)
		{
			if ((p_x == 0 || p_x == map.height - 1 || p_y == map.width - 1
				|| p_y == 0) && map.walls[p_x][p_y] != 1)
				ft_error("Surrounding numbers are not all 1s.", env, 0);
			else if (map.walls[p_x][p_y] != 1 && map.walls[p_x][p_y] != 0)
				ft_error("All numbers are not 1s or 0s.", env, 0);
		}
	}
}

/*
** This function checks if init_value initiates values properly.
*/

void		ft_checkinval(char **tab, t_enval *env)
{
	int i;
	int j;
	int tlen;
	int err;

	tlen = ft_tablen(tab);
	if ((err = tlen == 4 ? 0 : 1))
		ft_error("first line arguments are incorrect.", env, 0);
	i = -1;
	while (++i < tlen)
	{
		j = -1;
		while (tab[i][++j])
			err = ((ft_isdigit(tab[i][j]) ? err : 1));
		if ((i == 0 || i == 1) && !ft_isbetween(ft_atoi(tab[i]), 3, 200))
			err = 1;
		else if ((i == 2 || i == 3)
			&& !ft_isbetween(ft_atoi(tab[i]), 2, ft_atoi(tab[i - 2]) - 1))
			err = 1;
	}
	if (err)
		ft_error("first line arguments are incorrect.", env, 0);
}

/*
** Checks if any weapon textures' memory allocation went wrong or not
** and stops the program if it did.
*/

void		check_weapon_texture(t_enval *env, int id, int texture_number)
{
	int i;

	i = 0;
	while (i < texture_number)
	{
		if (!env->wptex[id][i].img)
			ft_error("missing or corrupted weapon texture(s)", env, 0);
		i++;
	}
}

/*
** This function protectivelt allocates the SDL's essential parameters.
*/

void		ft_checksdl(t_enval *env)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		ft_error("SDL init failure.", env, 0);
	if (!(env->sdl.win = SDL_CreateWindow("Doom", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, WIN_W, WIN_H, SDL_WINDOW_RESIZABLE)))
		ft_error("SDL window creation failure.", env, 0);
	if (!(env->sdl.rend = SDL_CreateRenderer(env->sdl.win, -1,
		SDL_RENDERER_SOFTWARE)))
		ft_error("SDL renderer creation failure.", env, 0);
}

/*
** The function the program refers to should any error show up.
*/

void		ft_error(char *err, t_enval *env, int i)
{
	ft_putstr("Error : ");
	ft_putendl(err);
	ft_exit(env, "end", 1, i);
}
