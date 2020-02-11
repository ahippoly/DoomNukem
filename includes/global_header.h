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
    double      start;
    double      end;
}               t_range;

void exit_with_msg(char *msg);
unsigned int *alloc_image(int width, int height);
SDL_Rect set_sdl_rect(int x, int y, int w, int h);
void swap_point(SDL_Point *p1, SDL_Point *p2);
void	octant(SDL_Point pos1, SDL_Point pos2, unsigned int *pixel, int color, SDL_Rect pos_size);
SDL_Point create_point(int x, int y);
t_point create_t_point(double x, double y);
t_range create_t_range(double start, double end);
t_img	ft_load_bmp(char *file);
void sort_point_by_x(SDL_Point *p1, SDL_Point *p2);
t_point segment_intersect(SDL_Point p1, SDL_Point p2, SDL_Point p3, SDL_Point p4);





#endif