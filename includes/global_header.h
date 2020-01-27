#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include "SDL.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"

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

void exit_with_msg(char *msg);
unsigned int *alloc_image(int width, int height);
SDL_Rect set_sdl_rect(int x, int y, int w, int h);
void swap_point(SDL_Point *p1, SDL_Point *p2);
void octant(SDL_Point pos1, SDL_Point pos2, unsigned int *pixel, int color, int bpp);

#endif