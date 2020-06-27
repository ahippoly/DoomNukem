#ifndef GLOABAL_HEADER_H
# define GLOABAL_HEADER_H

# include <math.h>
# include "SDL.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <pthread.h>
# include "libft.h"
# include "img_file.h"
# include "FMOD/fmod.h"
# include "SDL_ttf.h"

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
# define INTER_TOLERANCE 0.000000001
# define PI_X_2 6.28318530718


typedef struct  s_coord
{
    int x;
    int y;
    int z;
}               t_coord;

typedef struct		s_point
{
    float			x;
    float			y;
}              		t_point;

typedef	struct		s_line
{
	t_point			p1;
	t_point			p2;
}					t_line;

typedef struct		s_draw
{
    int				start_x;
    int				end_x;
	int				start_y;
    int				end_y;
	int				step_y;
}               	t_draw;

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

typedef struct      s_p_size
{   
    float           pos;
    float           size;
}                   t_p_size;

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








#endif