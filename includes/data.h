#ifndef DATA_H
# define DATA_H

# include "global_header.h"
# include "editor.h"
# include "render.h"
# include "hud.h"
# include "mobs.h"
# include "props.h"
# include "sound.h"
# include "sprite.h"
# include "bmp.h"

typedef struct      s_data
{
    SDL_Renderer    *rend;
    SDL_Window      *win;
    SDL_Texture     *screen;
    SDL_Texture     *mini_map;
    SDL_Texture     *t_player_pos;
    SDL_Event       e;
    SDL_Rect        mini_map_player_pos;
    t_img			texture[NB_TEXTURE];
	t_img			img[NB_IMG];
    t_map_data      map;
    const Uint8     *clavier;
    unsigned int    *p_screen;
    unsigned int    *p_mini_map_bg;
    unsigned int    *p_mini_map;
    unsigned int    *p_player_pos;
    int             quit;
    float			rot;
	t_rot			rot_calc;
	float			fov;
	float			fov_rad;
    t_point         player_pos;
    float			player_height;
    float			z_pos;
    float			z_offset;
    float			z_force;
    float			z_ground;
    int             screen_height;
    float			speed_modifier;
    int             framerate;
    int             time_last_frame;
    int             time;
	float			diff_time;
    int             air_time;
    t_sprite        sprite_lst[NB_SPRITE];
	/* world edit*/
	t_wall			*grabbed_wall;
	t_point			grab_pos;
	float			grab_z;
	/* floor drawing */
	t_floor			fl[NB_WALL_MAX / 2][WIN_SIZE_Y];
	t_props			props[NB_MAX_PROPS];
	int				nb_props;
	t_mob			mobs[NB_MAX_MOBS];
	int				nb_mob;
	t_obj			obj_list[NB_MAX_OBJ];
	int				nb_obj;
	t_obj			*repulsed[NB_MAX_MOBS + NB_MAX_PROPS];
	int				nb_repulsed;
	int				bullet;
	t_sprite        sprite[30];
    int             gun_ind;
    int             mob_ind;
    int             mobs_on_screen;
	FMOD_SOUND		*sound[30];
	FMOD_SYSTEM 	*system;
	SDL_Texture		*displayed_gun;
	SDL_Rect		src_gun;
	SDL_Rect		dst_gun;
	/* hud data */
    unsigned int    *p_hud; // hud screen
    SDL_Texture     *hud_texture; //hud texture
	t_hud			hud;
	/* ttf data */
	TTF_Font		*font_nb;
	TTF_Font		*font_text;
}                   t_data;

typedef	struct		s_thread
{
	float			start_angle;
	float			step;
	t_range			screen_x;
	t_data			*d;
}					t_thread;


#endif