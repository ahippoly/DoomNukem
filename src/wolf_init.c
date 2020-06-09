/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:58:59 by apons             #+#    #+#             */
/*   Updated: 2020/06/08 12:53:54 by apons            ###   ########.fr       */
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
			== env->map.height ? ft_exit(env, "map height incorrect.", 1, 0) : 0;
		if (!(tab = ft_strsplit(env->linebuff, ' ')))
			ft_exit(env, "map parsing failed.", 1, 1);
		free(env->linebuff);
		len = ft_tablen(tab);
		len != env->map.width ? ft_exit(env, "a line has bad width.", 1, 0) : 0;
		if (!(env->map.walls[env->wl] = (int *)malloc(sizeof(int) * len)))
			ft_exit(env, "map wall section malloc failure.", 1, 0);
		j = -1;
		while (tab[++j])
			env->map.walls[env->wl][j] = ft_atoi(tab[j]);
		ft_tabfree(tab);
		(j < 3) ? ft_exit(env, "incorrect map format.", 1, 0) : 0;
		env->wl += 1;
	}
	ft_checkappval(reader, env->wl, env, env->map);
	return (env->map.walls);
}

static void		prep_init(t_enval *env)
{
	int i;

	//env->user.fog = 3;
	//env->user.paused = -1;
	//env->user.bobbing.x = 0;
	//env->user.bobbing.y = 0;
	//env->user.black_box = sdl_set_rect(50, 50, 300, 200);
	env->map.walls = NULL;
	i = -1;
	while (++i < NBKEY)
		env->sdl.key[i] = 0;
	i = -1;
	while (++i < 5)
		env->game.pc.arsenal[i].name = "Nothing.";
	env->game.pc.equip.delay = 0;
	env->game.pc.equip.reload_cd = 0;
	init_stat(&env->game.pc.equip.off_vert, 100, 0);
	env->game.pc.fist_side = 2;
	init_pc(&env->game.pc);
}

void			init_values(char *file, t_enval *env)
{
	char	**tab;

	prep_init(env);
	env->fd = open(file, O_RDONLY);
	if (get_next_line(env->fd, &env->linebuff) == -1)
		ft_exit(env, "file reading failed.", 1, 0);
	if (!(tab = ft_strsplit(env->linebuff, ' ')))
		ft_exit(env, "first line parsing failed.", 1, 1);
	free(env->linebuff);
	ft_checkinval(tab, env);
	env->map.width = ft_atoi(tab[0]);
	env->map.height = ft_atoi(tab[1]);
	env->player.pos.x = ft_atoi(tab[3]) - 0.5;
	env->player.pos.y = ft_atoi(tab[2]) - 0.5;
	ft_tabfree(tab);
	if (!(env->map.walls = (int **)malloc(sizeof(int *) * env->map.height)))
		ft_exit(env, "map walls malloc failed.", 1, 0);
	env->map.walls = append_val(tab, env);
	close(env->fd);
	env->player.dir.x = 1;
	env->player.dir.y = 0;
	env->player.plane.x = 0;
	env->player.plane.y = -FOV;
	env->ray.wallhit = 0;
}

void			init_wall_texture(t_enval *env)
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
			ft_exit(env, "at least one texture is missing or corrupted.", 1, 0);
		i++;
	}
}

void			init_wptext(t_enval *env)
{
	if (!(env->wptex = (t_sprite **)malloc(sizeof(t_sprite *) * WEAPON_NUMBER)))
		ft_exit(env, "weapon initialization failure.", 1, 0);
	init_melee_texture(env);
	init_pistol_texture(env);
	init_shotgun_texture(env);
	init_smg_texture(env);
	init_bfg_texture(env);
	if (!(env->wptex[5] = (t_sprite *)malloc(sizeof(t_sprite))))
		ft_exit(env, "Temp reload failure.", 1, 0);
	env->wptex[5][0].img = SDL_LoadBMP("img/plante.bmp");
}
