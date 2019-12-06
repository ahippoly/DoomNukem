/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 08:24:06 by ahippoly          #+#    #+#             */
/*   Updated: 2019/09/21 20:39:49 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include "include/SDL2/SDL.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft/libft.h"

# define WIN_SIZE 800
# define MINI_MAP_X 650
# define MINI_MAP_Y 50
# define MINI_MAP_W 100
# define MINI_MAP_H 100
# define PERSO 5
# define BUFF_SIZE 1000000

typedef struct  s_pos
{
    double         x;
    double         y;
}               t_pos;

typedef struct  s_vox
{
    double         x;
    double         y;
    double         z;
}               t_vox;

typedef struct  s_line
{
	SDL_Point pos1;
	SDL_Point pos2;
}               t_line;

typedef struct  s_var
{
	SDL_Window *win;
    SDL_Renderer *rend;
	SDL_Texture *screen;
	SDL_Texture *mini_map_xy;
	SDL_Texture *mini_map_xz;
	SDL_Texture *mini_map_yz;
	SDL_Texture *character;
	SDL_Texture *t_ray;
	char *p_tab;;
	char *p_ray;
	char *p_clear;
	char p_perso[PERSO*PERSO*4];
	char ***map;
	t_vox perso_pos;
	t_vox map_size;
	double z_pos;
	SDL_Rect map_border;
	SDL_Point win_size;
	double rot;
	double roty;
	double fov;
}               t_var;

typedef struct  s_oct
{
    int         inc[2];
    int         d[2];
    int         e;
    int         bool;
    int         boolxy;
    int         ecart;
}               t_oct;

char *ft_load_bmp(char *file, int *width, int *height);
void errorcase(void);

void    oct_ini(t_oct *oct, SDL_Point pos1, SDL_Point pos2, int pos[2][2]);
void    octant(SDL_Point pos1, SDL_Point pos2, char *pixel, int color);

void put_border(char *p_tab, SDL_Point disp_size);
void put_rect(char *pixel, SDL_Point pos, SDL_Point size, int color, SDL_Point win_size);
void map_ini(char ***map, SDL_Point size, t_var *v);
void print_map(t_var *v);
void load_wall(t_var *v);
SDL_Point load_corner(t_var *v, int i, int j, int h);

void load_triangle1_plane(t_var *v, int x, int y, int z , SDL_Point corner[4]);
void load_triangle_point(t_var *v, int x, int y, int z, int rot);

char ***readfile2(char *file, t_var *v);

#endif
