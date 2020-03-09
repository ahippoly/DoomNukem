/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:58:29 by apons             #+#    #+#             */
/*   Updated: 2020/02/07 22:53:21 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "SDL2/SDL.h"
# include "../libft/includes/libft.h"
# include "gameplay.h"

# define WIN_W 1280
# define WIN_H 960
# define FOV   0.66
# define FORWARD 1
# define BACKWARD -1
# define OFF 0.085
# define TEXT_CEILING 5
# define TEXT_FLOOR 4

# define WEAPON_NUMBER				6
# define WEAPON_TEXTURES_MELEE		5
# define WEAPON_TEXTURES_PISTOL		5
# define WEAPON_TEXTURES_SHOTGUN	5
# define WEAPON_TEXTURES_SMG		3
# define WEAPON_TEXTURES_BFG		15

# define WALL_TEXTURE_NUMBER 6
# define WN "textures/wallnorth.xpm"
# define WS "textures/bonuscrystal.xpm"
# define WW "textures/wallwest.xpm"
# define WE "textures/walleast.xpm"
# define FL "textures/floor.xpm"
# define CL "textures/ceiling.xpm"

# define KEY_Q 12
# define KEY_E 14
# define KEY_R 15
# define KEY_P 35
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_LSHIFT 257

# define NBKEY 15
# define LMOUSE 0
# define Q 1
# define E 2
# define R 3
# define P 4
# define ESC 5
# define LEFT 6
# define RIGHT 7
# define DOWN 8
# define UP 9
# define MOUSE 10
# define LSHIFT 11

/*
** Many little structures to build up a bigger, cleaner one.
** The first two are used in a variety of ways.
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
** The main ray structure, mostly used for the raycasting functions.
*/

typedef struct	s_ray
{
	t_doublexy			sidedist;
	t_doublexy			dir;
	t_doublexy			deltadist;
	t_intxy				mapos;
	t_intxy				step;
	t_doublexy			floorwall;
	t_doublexy			currentfloor;
	double				camera;
	double				perpwalldist;
	double				wallwhere;
	int					wallhit;
	int					wallside;
	int					height;
	int					walltop;
	int					wallbot;
	double				weight;
	double				distcurrent;
	double				distwall;
}				t_ray;

/*
** The mlx structure to handle the window and main image.
*/

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

/*
** The Surface structure for stack the image.
** Use Tab of t_sprite.
*/

typedef struct	s_sprite
{
	SDL_Surface *img;
}				t_sprite;

/*
** The SDL structure to handle window.
*/

typedef struct	s_sdl
{
	int				sdl_token;
	SDL_Window		*win;
	SDL_Texture		*text;
	SDL_Renderer	*rend;
	SDL_Surface		*screen;
	int				winx;
	int				winy;
	int				key[NBKEY];
}				t_sdl;

/*
** Structure for user gamplay varialble
*/

typedef struct	s_user
{
	int			fog;
	int			paused;
	t_intxy		bobbing;
}				t_user;

/*
** The main structure, containing most of the variables that will
** be used throughout the program.
*/

typedef struct	s_enval
{
	t_mlx					mlx;
	t_sdl					sdl;
	t_player				player;
	t_ray					ray;
	t_mapinfo				map;
	t_intxy					wt;
	t_sprite				wtex[WALL_TEXTURE_NUMBER];
	t_sprite				**wptex;
	int						fd;
	int						wl;
	char					*linebuff;
	t_user					user;
	t_game					game;
	SDL_Event				event;
	SDL_MouseMotionEvent	mouse;
}				t_enval;

/*
** Function prototypes specific to this program
*/

void			free_doom(t_enval *env, int i);
void			free_map(t_mapinfo *map, int wl);
void			free_textures(t_sprite *wtex, t_sprite **wptex);
void			free_texture_weapon(t_sprite **wptex, int id, int texture_number);
void			ft_error(char *err, t_enval *env, int i);
void			ft_checkappval(int reader, int i, t_enval *env, t_mapinfo map);
void			ft_checkinval(char **tab, t_enval *val);
void			check_weapon_texture(t_enval *env, int id, int texture_number);
void			ft_checkmlx(t_enval *env);
void			if_keyvert(int **walls, t_doublexy *pos, t_doublexy *cpy);
void			ft_help(void);
void			init_values(char *file, t_enval *env);
void			movement(t_enval*env);
void			ray_calc(t_enval *env, int i);
void			ray_hit(t_enval *env);
void			rotation(t_enval *env, t_player *p);
void			ft_exit(t_enval *env, char *s, int flag, int i);

/*
**	Function Color and Pixel
*/

uint32_t		get_pixel_wall(t_enval *env, int si, float x, float y);
uint32_t		get_pixel_floor(t_enval *env, int si, float x, float y);
uint32_t		get_pixel_weapon(t_enval *env, t_intxy si, float x, float y);
void			put_pixel(SDL_Surface *surface, int x, int y, uint32_t color);
Uint32			light_shade(Uint32 hexa, float distance);
int				white_fog(Uint32 hexa, float distance);
int				fog(t_enval *env, Uint32 hexa, float distance);
int				rgb_to_hsv(int r, int g, int b);
SDL_Color		fill_rgb(int c);

/*
** Graphics functions
*/

void			fc_draw(t_enval *env, int i);
void			ray_draw(t_enval *env);
void			wall_draw(t_enval *env, int i, int texnum);
void			display(t_enval *env);
void			init_wall_texture(t_enval *env);
void			init_wptext(t_enval *env);
void			init_melee_texture(t_enval *env);
void			init_pistol_texture(t_enval *env);
void			init_shotgun_texture(t_enval *env);
void			init_smg_texture(t_enval *env);
void			init_bfg_texture(t_enval *env);
void			weapon_draw(t_enval *env);
int				get_id_weapon_texture(t_enval *env, t_intxy *id);
int				get_id_arsenal_s(int id, double cur, double max, int side);
int				get_id_arsenal_xl(int id, double cur, double max);
int				get_id_bfg_reloading(double cur, double max);
int				get_id_arsenal_bfg(double cur, double max, int state);

/*
** SDL Event Function
*/

void			event(t_enval *env);
void			event_unpaused(t_enval *env);
void			mouse_events(t_enval *env);
void			mouseclick_event(t_enval *env);
void			move_events(t_enval *env);
void			deal_event(t_enval *env);
void			switch_fog(t_enval *env);
void			change_weapon(t_enval *env);
void			handle_bobbing(t_enval *env);
void			handle_weapon_reload(t_enval *env);
void			handle_weapon_fire(t_enval *env);

#endif
