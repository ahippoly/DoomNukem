/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 22:58:42 by robin             #+#    #+#             */
/*   Updated: 2020/07/06 02:20:59 by alebui           ###   ########.fr       */
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
	SDL_Texture		*t_player_pos;
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
	SDL_Texture		*displayed_gun;
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
	SDL_Texture		*gameover_texture;
	char			*argv;
	t_img			skybox;
	FMOD_SOUND		*sound[MAX_SOUNDS]; //WTF
	// FMOD_SOUND		sound[MAX_SOUNDS];
    // t_ssprite       sprite_lst[NB_SPRITE_MAX];
	// t_ssprite		weapon_img[WEAPON_NB];
	// t_floor			fl[NB_WALL_MAX / 2][WIN_SIZE_Y];
	// t_props			props[NB_MAX_PROPS];
	// t_mob			mobs[NB_MAX_MOBS];
	// t_obj			obj_list[NB_MAX_OBJ];
	// t_obj			*repulsed[NB_MAX_MOBS + NB_MAX_PROPS];
	// t_img			texture[NB_TEXTURE];
	// t_img			img[NB_IMG];
	// t_img			sprite_img[NB_SPRITE];
	t_floor			**fl; //OK
	t_props			*props; //OK
	t_mob			*mobs; //OK
	t_obj			*obj_list; //ok
	t_obj			**repulsed; //OK
	t_sprite        sprite[MAX_WEAPONS]; //------SG
	// t_sprite        *sprite;
	t_img			*texture; //OK
	t_img			*img; //OK
	t_img			*sprite_img; //OK
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
