#ifndef EDITOR_H
# define EDITOR_H

#include "SDL.h"
#include "libft.h"

# define GRID_SIZE_X 800
# define GRID_SIZE_Y 600
# define TILE_SIZE 45
# define TILE_HITBOX 10


typedef struct      s_env
{
    SDL_Renderer    *rend;
    SDL_Event       ev;
    SDL_Window      *win;
    SDL_Texture     *screen;
    SDL_Texture     *editor_grid;
    SDL_Rect        grid_pos;
    int             quit;
    unsigned int    *p_screen;
    unsigned int    *p_grid;
}                   t_env;

typedef struct      s_size
{   
    int             w;
    int             h;
}                   t_size;



void exit_with_msg(char *msg);

#endif