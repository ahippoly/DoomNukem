#ifndef RENDER_H
# define RENDER_H

# include "global_header.h"
# define FOV_ANGLE 90

typedef struct s_data
{
    SDL_Renderer    *rend;
    SDL_Window      *win;
    SDL_Texture     *screen;
    SDL_Event       e;
    const Uint8     *clavier;
    unsigned int    *p_screen;
    int             quit;
    double          rot;
    t_point         player_pos;

}              t_data;

#endif