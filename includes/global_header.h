#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include "SDL.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"
# include "img_file.h"

# define WIN_SIZE_X 800
# define WIN_SIZE_Y 800
# define HALF_WIN_SIZE_X WIN_SIZE_X / 2
# define HALF_WIN_SIZE_Y WIN_SIZE_Y / 2
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

# define NB_FRAME 15
# define NB_ANIM 10
# define NB_SPRITE 10

typedef struct s_point
{
    double x;
    double y;
}               t_point;

typedef struct  s_range
{
    int         start;
    int         end;
}               t_range;

typedef struct      s_size
{   
    int             w;
    int             h;
}                   t_size;

typedef struct      s_calced_walls
{
                    double  dist;
                    double  scale;
                    int     text_id;
                    int     wall_id;
                    float   alpha;
}                   t_calced_walls;

typedef struct      s_anim
{
                    SDL_Point   pos[NB_FRAME];
                    int         nb_frame;
                    int         current_frame;
                    double      speed;
}                   t_anim;

typedef struct      s_sprite
{
                    int             index;
                    unsigned int    *pixels;
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

typedef struct      s_mob
{

                    t_sprite sprite;
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
    double          length;
    t_point         rotation;
}                   t_wall;

typedef struct          s_wall_ref
{
    int                 wall_id;
    struct s_wall_ref   *next;
}                       t_wall_ref;

typedef struct          s_room
{
    int                 room_id;
    int                 nb_wall;
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
void	octant(SDL_Point pos1, SDL_Point pos2, unsigned int *pixel, int color, SDL_Rect pos_size);
SDL_Point create_point(int x, int y);
t_point create_t_point(double x, double y);
t_range create_t_range(int start, int end);
t_size create_t_size(int w, int h);
t_img	ft_load_bmp(char *file);
void sort_point_by_x(SDL_Point *p1, SDL_Point *p2);
t_point segment_intersect(SDL_Point p1, SDL_Point p2, SDL_Point p3, SDL_Point p4);
t_point	line_intersect(t_point pos, double rot, t_point p1, t_point p2);
t_point inter_with_dir(t_point pos, double rot, t_point p3, t_point p4);
t_point find_intersect(t_point p1, t_point p2, t_point p3, t_point p4);
void swap_t_point(t_point *p1, t_point *p2);
void sort_t_point_by_x(t_point *p1, t_point *p2);
void put_pixel(unsigned int *pixels, SDL_Point p_pos, t_size img_size, int color);
void put_pixel_attempt(unsigned int *pixels, SDL_Point p_pos, t_size img_size, int color);
void put_pixel_transparency(unsigned int *pixels, SDL_Rect pos_size, unsigned int color, float alpha);
int is_equ_tolerance(double value1, double value2, double tolerance);
double get_float_part(double value);

//editor_map_reader.c
t_map_data  read_map(char *path_file);





#endif