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

# define WIN_SIZE_X 1000
# define WIN_SIZE_Y 1000
# define MINI_MAP_X 650
# define MINI_MAP_Y 50
# define MINI_MAP_W 100
# define MINI_MAP_H 100
# define PERSO 5
# define BUFF_SIZE 1000000
# define NAZI "Alerte nazi, Test de nazi detecte, Alerte nazi\n"
# define MOUSE 3

typedef struct s_point
{
    double x;
    double y;
}               t_point;

typedef struct s_range
{
    int      start;
    int      end;
}               t_range;

typedef struct      s_size
{   
    int             w;
    int             h;
}                   t_size;

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
void swap_t_point(t_point *p1, t_point *p2);
void sort_t_point_by_x(t_point *p1, t_point *p2);

//editor_map_reader.c
t_map_data  read_map(char *path_file);





#endif