/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:58:59 by apons             #+#    #+#             */
/*   Updated: 2020/02/07 23:11:17 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/wolf3d.h"

/*
** These functions initialize the program's values and parse the map.
*/

static int		**append_val(char **tab, t_enval *env)
{
	int reader;
	int len;
	int j;

	env->wl = 0;
	while ((reader = get_next_line(env->fd, &env->linebuff)) >= 1)
	{
		env->wl
			== env->map.height ? ft_error("map height incorrect.", env, 0) : 0;
		if (!(tab = ft_strsplit(env->linebuff, ' ')))
			ft_error("map parsing failed.", env, 1);
		free(env->linebuff);
		len = ft_tablen(tab);
		len != env->map.width ? ft_error("a line has bad width.", env, 0) : 0;
		if (!(env->map.walls[env->wl] = (int *)malloc(sizeof(int) * len)))
			ft_error("map wall section malloc failure.", env, 0);
		j = -1;
		while (tab[++j])
			env->map.walls[env->wl][j] = ft_atoi(tab[j]);
		ft_tabfree(tab);
		(j < 3) ? ft_error("incorrect map format.", env, 0) : 0;
		env->wl += 1;
	}
	ft_checkappval(reader, env->wl, env, env->map);
	return (env->map.walls);
}

static void		prep_init(t_enval *env)
{	
	int i;

	env->user.fog = 3;
	env->map.walls = NULL;
	i = -1;
	while (++i < NBKEY)
		env->sdl.key[i] = 0;
	i = -1;
	while (++i < 5)
		env->game.pc.arsenal[i].name = "Nothing.";
	env->game.pc.equip.delay = 0;
	init_pc(&env->game.pc);
	env->user.bobbing.x = 0;
	env->user.bobbing.y = 0;
	env->game.pc.equip.delay = 0;
}

void			init_values(char *file, t_enval *env)
{
	char	**tab;

	prep_init(env);
	env->fd = open(file, O_RDONLY);
	if (get_next_line(env->fd, &env->linebuff) == -1)
		ft_error("file reading failed.", env, 0);
	if (!(tab = ft_strsplit(env->linebuff, ' ')))
		ft_error("first line parsing failed.", env, 1);
	free(env->linebuff);
	ft_checkinval(tab, env);
	env->map.width = ft_atoi(tab[0]);
	env->map.height = ft_atoi(tab[1]);
	env->player.pos.x = ft_atoi(tab[3]) - 0.5;
	env->player.pos.y = ft_atoi(tab[2]) - 0.5;
	ft_tabfree(tab);
	if (!(env->map.walls = (int **)malloc(sizeof(int *) * env->map.height)))
		ft_error("map walls malloc failed.", env, 0);
	env->map.walls = append_val(tab, env);
	close(env->fd);
	env->player.dir.x = 1;
	env->player.dir.y = 0;
	env->player.plane.x = 0;
	env->player.plane.y = -FOV;
	env->ray.wallhit = 0;
}

void			init_texture(t_enval *env)
{
	int i;

	env->wtex[0].img = SDL_LoadBMP("img/textures/wall.bmp");
	env->wtex[1].img = SDL_LoadBMP("img/textures/wall.bmp");
	env->wtex[2].img = SDL_LoadBMP("img/textures/wall.bmp");
	env->wtex[3].img = SDL_LoadBMP("img/textures/wall.bmp");
	env->wtex[4].img = SDL_LoadBMP("img/textures/sand.bmp");
	env->wtex[5].img = SDL_LoadBMP("img/textures/stone.bmp");
	i = 0;
	while (i <= 5)
	{
		if (!(env->wtex[i].img))
			ft_error("at least one texture is missing or corrupted.", env, 0);
		i++;
	}
}

void			init_wptext(t_enval *env)
{
	int i;

	env->weapontex[0].img = SDL_LoadBMP("img/weapons/hand.bmp");
	env->weapontex[1].img = SDL_LoadBMP("img/weapons/hand2.bmp");
	env->weapontex[2].img = SDL_LoadBMP("img/weapons/gun1.bmp");
	env->weapontex[3].img = SDL_LoadBMP("img/weapons/gun2.bmp");
	env->weapontex[4].img = SDL_LoadBMP("img/weapons/shotgun.bmp");
	env->weapontex[5].img = SDL_LoadBMP("img/weapons/shotgunfire.bmp");
	env->weapontex[6].img = SDL_LoadBMP("img/weapons/rafle.bmp");
	env->weapontex[7].img = SDL_LoadBMP("img/weapons/rafle2.bmp");
	env->weapontex[8].img = SDL_LoadBMP("img/weapons/autogun1.bmp");
	env->weapontex[9].img = SDL_LoadBMP("img/weapons/autogun2.bmp");
	env->weapontex[10].img = SDL_LoadBMP("img/weapons/gunfire.bmp");
	i = 0;
	while (i < 11)
	{
		if (!(env->weapontex[i].img))
			ft_error("at least one weapon texture is missing or corrupted.", env, 0);
		i++;
	}
}