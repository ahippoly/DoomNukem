#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include "SDL.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <pthread.h>
# include "libft.h"
# include "img_file.h"

# define WIN_SIZE_X 800
# define WIN_SIZE_Y 800
# define HALF_WIN_SIZE_X 400
# define HALF_WIN_SIZE_Y 400
# define MINI_MAP_X 650
# define MINI_MAP_Y 50
# define MINI_MAP_W 100
# define MINI_MAP_H 100
# define PERSO 5
# define BUFF_SIZE 1000000
# define NAZI "Alerte nazi, Test de nazi detecte, Alerte nazi\n"
# define MOUSE 3
# define NB_WALL_MAX 200
# define INTER_TOLERANCE 0.00001
# define PI_X_2 6.28318530718

# define NB_FRAME 15
# define NB_ANIM 20
# define NB_SPRITE 3
# define SPRITE_WEAPON_GUN 0
# define SPRITE_WEAPON_FIST 1

# define ANIM_MOB_MOVE_FRONT 0;
# define ANIM_MOB_MOVE_BACK 1;
# define ANIM_MOB_MOVE_LEFT 2;
# define ANIM_MOB_MOVE_RIGHT 3;
# define ANIM_MOB_MELEE 4;
# define ANIM_MOB_SHOOT 5;
# define ANIM_MOB_DEATH 6;

# define ANIM_STATE_OPEN 0;
# define ANIM_STATE_CLOSE 1;
# define ANIM_STATE_TRIGGERED 2;

# define ANIM_WEAPON_RELOAD 0;
# define ANIM_WEAPON_SHOOT 1;


typedef struct		s_point
{
    float			x;
    float			y;
}              		t_point;

typedef struct		s_range
{
    int				start;
    int				end;
}               	t_range;

typedef struct		s_frange
{
    float			start;
    float			end;
}               	t_frange;

typedef struct      s_size
{   
    int             w;
    int             h;
}                   t_size;

typedef	struct 		s_rot
{
	float			rot;
	float			cos_rot;
	float			sin_rot;
}					t_rot;


typedef struct      s_anim
{
                    SDL_Point   pos[NB_FRAME];
                    SDL_Point   offset[NB_FRAME];
                    int         nb_frame;
                    int         current_frame;
                    float      speed;
}                   t_anim;

typedef struct      s_sprite
{
                    unsigned int    *pixels;
                    t_size          total_size;
                    t_size          frame_size;
                    SDL_Rect        displayed_frame;
                    SDL_Point       nb_frame;
                    SDL_Point       idle_frame;
                    t_anim          anim[NB_ANIM];
                    int             nb_anim;
                    int             idle_animation;
}                   t_sprite;

typedef struct      s_mob
{
                    t_sprite sprite;
                    t_point pos;
                    float  agro_range;
}                   t_mob;

typedef struct      s_wall
{
    int             id;
    SDL_Point       p1;
    SDL_Point       p2;
    t_range         p1_height;
    t_range         p2_height;
    int             texture_id;
    int             room_id_ref;
    int             transparency;
    int             can_collide;
    float			length;
    float			rotation;
	float			alpha;
	t_point			p1_f;
    t_point			p2_f;
	float			p1_z_start;
	float			p1_z_size;
	float			p2_z_start;
	float			p2_z_size;
	float			z_text_offset;
}                   t_wall;

typedef struct      s_calced_walls
{
	float  			dist;
	float  			scale;
	float			scale_z;
	t_point			inter;
	t_wall			wall;
}                   t_calced_walls;

typedef struct			s_move_wall
{
    t_point 			p1;
    t_point 			p2;
	int					travel_time;
}						t_move_wall;


typedef struct          s_wall_ref
{
    int                 wall_id;
    struct s_wall_ref   *next;
}                       t_wall_ref;

typedef struct          s_room
{
    int                 room_id;
    int                 nb_wall;
	t_range				height;
	int					floor_text;
	float				z_ground;
	float				z_ceil;
    t_range             wall_ref;
}                       t_room;

typedef struct      s_map_data
{
    int             is_valid;
    t_size          map_size;
    int             wall_count;
    int             room_count;
    SDL_Point       player_spawn;
    t_wall          *wall_list;
    t_room          *room_list;
    t_wall_ref      ***map_wall_ref;
}                   t_map_data;

void exit_with_msg(char *msg);
unsigned int *alloc_image(int width, int height);
SDL_Rect set_sdl_rect(int x, int y, int w, int h);
void swap_point(SDL_Point *p1, SDL_Point *p2);
void	draw_line(SDL_Point pos1, SDL_Point pos2, t_img img, int color);
SDL_Point create_point(int x, int y);
t_point create_t_point(float x, float y);
t_range create_t_range(int start, int end);
t_size create_t_size(int w, int h);
t_img	ft_load_bmp(char *file);
void sort_point_by_x(SDL_Point *p1, SDL_Point *p2);
t_point segment_intersect(SDL_Point p1, SDL_Point p2, SDL_Point p3, SDL_Point p4);
t_point	line_intersect(t_point pos, float rot, t_point p1, t_point p2);
t_point inter_with_dir(t_point pos, t_rot rot, t_point p3, t_point p4);
t_point find_intersect(t_point p1, t_point p2, t_point p3, t_point p4);
t_point find_intersect_no_bound(t_point p1, t_point p2, t_point p3, t_point p4);
void swap_t_point(t_point *p1, t_point *p2);
void sort_t_point_by_x(t_point *p1, t_point *p2);
void put_pixel(unsigned int *pixels, SDL_Point p_pos, t_size img_size, unsigned int color);
void put_pixel_attempt(unsigned int *pixels, SDL_Point p_pos, t_size img_size, unsigned int color);
void put_pixel_transparency(unsigned int *pixels, SDL_Rect pos_size, unsigned int color, float alpha);
int is_equ_tolerance(float value1, float value2, float tolerance);
float get_float_part(float value);
t_point sdl_p_to_t_p(SDL_Point p);
float ft_interpolate(float val1, float val2, float scale);


//editor_map_reader.c
t_map_data  read_map(char *path_file);

void process_all_idle_anim(t_sprite sprite[NB_SPRITE]); //prend en paramètre un tableau de sprite, et calcul frame par frame leur animation par défaut
void process_idle_anim(t_sprite *sprite); //calcul l'animation par défaut d'un sprite
void load_anim(t_sprite *t_sprite, int anim_id); //calcul une animation du sprite puis reviens a l'animation par défaut
void change_idle_anim(t_sprite *t_sprite, int anim_id); //change l'animation par défaut du sprite

t_rot calc_sin_cos_rot(float rot);
void sort_int(int *a, int *b);
void	*ft_memcpy_int(unsigned int *dst, const unsigned int *src, size_t n);




#endif