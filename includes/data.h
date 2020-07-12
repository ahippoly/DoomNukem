/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 22:58:42 by robin             #+#    #+#             */
/*   Updated: 2020/07/09 16:36:11 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "global_header.h"
# include "ssprite.h"
# include "render.h"
# include "editor.h"
# include "hud.h"
# include "menu.h"
# include "mobs.h"
# include "props.h"
# include "sound.h"
# include "sprite.h"

typedef struct		s_data
{
	SDL_Renderer	*rend;
	SDL_Window		*win;
	SDL_Texture		*screen;
	SDL_Texture		*mini_map;
	SDL_Event		e;
	SDL_Rect		mini_map_player_pos;
	t_map_data		map;
	const Uint8		*clavier;
	unsigned int	*p_screen;
	unsigned int	*p_mini_map_bg;
	unsigned int	*p_mini_map;
	unsigned int	*p_player_pos;
	int				run_game;
	float			rot;
	t_rot			rot_calc;
	float			fov;
	float			fov_rad;
	t_point			player_pos;
	float			player_height;
	float			z_pos;
	float			z_offset;
	float			z_force;
	float			z_ground;
	int				screen_height;
	float			speed_modifier;
	int				framerate;
	int				time_last_frame;
	int				time;
	float			diff_time;
	int				air_time;
	int				nb_sprite;
	t_wall			*grabbed_wall;
	t_point			grab_pos;
	float			grab_z;
	int				nb_props;
	int				nb_mob;
	int				nb_obj;
	int				nb_repulsed;
	t_weapon		*actual_weapon;
	int				bullet;
	char			shoot_repeat;
	int				gun_ind;
	int				mob_ind;
	int				mobs_on_screen;
	FMOD_SYSTEM		*system;
	SDL_Rect		src_gun;
	SDL_Rect		dst_gun;
	unsigned int	*p_hud;
	SDL_Texture		*hud_texture;
	t_hud			hud;
	TTF_Font		*font_nb;
	TTF_Font		*font_text;
	unsigned int	*p_menu;
	SDL_Texture		*menu_texture;
	t_menu			menu;
	unsigned int	*p_gameover;
	unsigned int	*p_win;
	SDL_Texture		*win_texture;
	SDL_Texture		*gameover_texture;
	t_img			skybox;
	FMOD_SOUND		*sound[MAX_SOUNDS];
	t_floor			**fl;
	t_props			*props;
	t_mob			*mobs;
	t_obj			*obj_list;
	t_obj			**repulsed;
	t_sprite		sprite[MAX_WEAPONS];
	t_img			*texture;
	t_img			*img;
	t_img			*sprite_img;
	int				jetpack;
}					t_data;

typedef	struct		s_thread
{
	float			start_angle;
	float			step;
	t_range			screen_x;
	t_data			*d;
}					t_thread;

typedef	struct		s_data_x
{
	t_data			*d;
	int				x;
}					t_data_x;

#endif
