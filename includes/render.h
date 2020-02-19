#ifndef RENDER_H
# define RENDER_H

#include "global_header.h"

typedef struct s_data
{
    SDL_Renderer    *rend;
    SDL_Window      *win;
    SDL_Texture     *screen;
    double          rot;

}              t_data; 

#endif