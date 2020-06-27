#ifndef SSPRITE_H
# define SSPRITE_H

# include "data.h"

# define ANIM_MOB_IDLE 0
# define ANIM_MOB_MOVE_FRONT 1
# define ANIM_MOB_MOVE_BACK 2
# define ANIM_MOB_MOVE_LEFT 3
# define ANIM_MOB_MOVE_RIGHT 4
# define ANIM_MOB_MELEE 5
# define ANIM_MOB_SHOOT 6
# define ANIM_MOB_DEATH 7

# define ANIM_STATE_OPEN 0
# define ANIM_STATE_CLOSE 1
# define ANIM_STATE_TRIGGERED 2

# define ANIM_WEAPON_RELOAD 0
# define ANIM_WEAPON_SHOOT 1

# define NB_SPRITE 1
# define NB_SPRITE_MAX 30

# define NB_FRAME 15
# define NB_ANIM 20

# define SPRITE_WEAPON_GUN 0
# define SPRITE_WEAPON_FIST 1

# define SPRITE_ID_AFRIT 0
# define SPRITE_ID_PYRO 1

# define SPRITE_PATH_PYRO "Sprites/Mobs/pyro.bmp"
# define SPRITE_PATH_AFRIT "Sprites/Mobs/afrit.bmp"

typedef struct      s_anim
{
                    SDL_Point   offset;
                    SDL_Point   pos[NB_FRAME];
                    int         nb_frame;
                    int         current_frame;
                    float		speed;
}                   t_anim;

typedef struct      s_sprite
{  
                    SDL_Point       size;
                    int             aim_on;
                    int             anim_end;
                    Uint32          time;
                    int             on;
                    int             index;
                    unsigned int    *pixels;
                    unsigned int    *pixels_dst;
                    t_size          total_size;
                    t_size          frame_size;
                    SDL_Point       nb_frame;
                    SDL_Point       idle_frame;
                    SDL_Point       displayed_part;
                    t_anim          anim[NB_ANIM];
                    int             nb_anim;
                    int             idle_animation;
                    SDL_Texture     *text;
}                   t_sprite;



typedef struct					s_ssprite
{
								t_img src;
								unsigned int *dst;
								int dst_w;
								int dst_h;
								t_size frame_size;
								t_size frame_disp_size;
								SDL_Point nb_frame;
								SDL_Point	default_frame;
								t_anim		anim[NB_ANIM];
								int			current_anim;
								int			idle_anim;
								int time;
								void	*(*callback)(void*);
								void	*param;
}								t_ssprite;

#endif