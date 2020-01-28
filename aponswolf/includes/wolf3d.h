/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:58:29 by apons             #+#    #+#             */
/*   Updated: 2019/10/31 12:03:07 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h>

# include "mlx.h"
# include "libft.h"

# define WIN_W 1280
# define WIN_H 960
# define FOV   0.66
# define FORWARD 1
# define BACKWARD -1
# define WN "textures/wallnorth.xpm"
# define WS "textures/bonuscrystal.xpm"
# define WW "textures/wallwest.xpm"
# define WE "textures/walleast.xpm"
# define FL "textures/floor.xpm"
# define CL "textures/ceiling.xpm"

# define NOEVENTMASK 0L
# define KEYPRESSMASK (1L << 0)
# define KEYRELEASEMASK (1L << 1)
# define BUTTONPRESSMASK (1L << 2)
# define POINTERMOTIONMASK (1L << 6)

# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define MOTIONNOTIFY 6
# define DESTROYNOTIFY 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

/*
**deltadist = abs(1/dir)
**sidedist = (pos - map) * deltaDist and step = -1  if dir <  0
**		   = (map + 1.0 - pos) * deltaDist and step = 1	if dir >= 0
*/

typedef struct	s_intxy
{
	int					x;
	int					y;
}				t_intxy;

typedef struct	s_doublexy
{
	double				x;
	double				y;
}				t_doublexy;

typedef struct	s_mapinfo
{
	int					**walls;
	int					width;
	int					height;
}				t_mapinfo;

typedef struct	s_player
{
	struct s_doublexy	pos;
	struct s_doublexy	dir;
	struct s_doublexy	plane;
}				t_player;

/*
**WallSide tells the orientation of the ray when it hits
*/

typedef struct	s_ray
{
	struct s_doublexy	sidedist;
	struct s_doublexy	dir;
	struct s_doublexy	deltadist;
	struct s_intxy		mapos;
	struct s_intxy		step;
	double				camera;
	double				perpwalldist;
	double				wallwhere;
	int					wallhit;
	int					wallside;
	int					height;
	int					walltop;
	int					wallbot;
}				t_ray;

typedef struct	s_mlx
{
	void				*m_p;
	void				*w_p;
	void				*i_p;
	int					*pxl;
	int					bpp;
	int					s_line;
	int					endian;
}				t_mlx;

typedef struct	s_tex
{
	int		width;
	int		height;
	int		*buffer;
	void	*img;
}				t_tex;

typedef struct	s_keys
{
	int up;
	int down;
	int left;
	int right;
}				t_keys;


typedef struct	s_enval
{
	struct s_mlx		mlx;
	struct s_player		player;
	struct s_ray		ray;
	struct s_mapinfo	map;
	struct s_intxy		wt;
	struct s_tex		*wtex[6];
	struct s_doublexy	floorwall;
	struct s_doublexy	currentfloor;
	struct s_keys		keyinf;
	int					fd;
	char				*linebuff;
	double				weight;
	double				distcurrent;
	double				distwall;
}				t_enval;

t_enval			*fc_calc(t_enval *env);
void			fc_draw(t_enval *env, int i);
void			ft_error(char *err);
int				ft_loop_hook(t_enval *env);
void			ft_checkappval(int reader, int i, t_mapinfo map, t_player plr);
t_enval			*init_mlx(t_enval *env);
t_enval			*init_values(char *file, t_enval *env);
int				keypress(int key, t_enval *env);
int				keyrelease(int key, t_enval *env);
void			mlx_handle_hooks(t_enval *env);
t_enval			*ray_calc(t_enval *env, int i);
t_enval			*ray_draw(t_enval *env);
t_enval			*ray_hit(t_enval *env);
void			wall_draw(t_enval *env, int i, int texnum);

#endif