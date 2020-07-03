#ifndef DATA_H
# define DATA_H

# include "global_header.h"
# include "ssprite.h"
# include "render.h"
# include "editor.h"
# include "hud.h"
# include "menu.h"
# include "mobs.h"
# include "gameplay.h"
# include "props.h"
# include "sound.h"
# include "sprite.h"

typedef struct      s_data
{
    SDL_Renderer    *rend;
    SDL_Window      *win;
    SDL_Texture     *screen;
    SDL_Texture     *mini_map;
    SDL_Texture     *t_player_pos;
    SDL_Event       e;
    SDL_Rect        mini_map_player_pos;
    
    t_map_data      map;
    const Uint8     *clavier;
    unsigned int    *p_screen;
    unsigned int    *p_mini_map_bg;
    unsigned int    *p_mini_map;
    unsigned int    *p_player_pos;
    // int             quit;
	int				run_game; //quit
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
	int				nb_sprite;
	/* world edit*/
	t_wall			*grabbed_wall;
	t_point			grab_pos;
	float			grab_z;
	/* floor drawing */

	int				nb_props;
	int				nb_mob;
	int				nb_obj;
	int				nb_repulsed;
	t_weapon		*actual_weapon;
	int				bullet;
	char			shoot_repeat;
    int             gun_ind;
    int             mob_ind;
    int             mobs_on_screen;
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
	/* menu data */
	unsigned int    *p_menu; // menu screen
    SDL_Texture     *menu_texture; //menu texture
	t_menu			menu;
	/* gameover */
	unsigned int    *p_gameover; // menu screen
    SDL_Texture     *gameover_texture; //menu texture
	char			*argv;
	t_img			skybox;
	FMOD_SOUND		*sound[30];
    t_ssprite       sprite_lst[NB_SPRITE_MAX];
	t_ssprite		weapon_img[WEAPON_NB];
	t_floor			fl[NB_WALL_MAX / 2][WIN_SIZE_Y];
	t_props			props[NB_MAX_PROPS];
	t_mob			mobs[NB_MAX_MOBS];
	t_obj			obj_list[NB_MAX_OBJ];
	t_obj			*repulsed[NB_MAX_MOBS + NB_MAX_PROPS];
	t_sprite        sprite[30];
	t_img			texture[NB_TEXTURE];
	t_img			img[NB_IMG];
	t_img			sprite_img[NB_SPRITE];
	int				jetpack;
}                   t_data;

typedef	struct		s_thread
{
	float			start_angle;
	float			step;
	t_range			screen_x;
	t_data			*d;
}					t_thread;


#endif