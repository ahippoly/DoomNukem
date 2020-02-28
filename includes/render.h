#ifndef RENDER_H
# define RENDER_H

# include "global_header.h"
# define FOV_ANGLE 90
# define MINI_MAP_SIZE_X 250
# define MINI_MAP_SIZE_Y 250
# define MINI_MAP_POS_X WIN_SIZE_X - MINI_MAP_SIZE_X
# define MINI_MAP_POS_Y 0
# define MINI_MAP_PLAYER_SIZE 5

typedef struct s_data
{
    SDL_Renderer    *rend;
    SDL_Window      *win;
    SDL_Texture     *screen;
    SDL_Texture     *mini_map;
    SDL_Event       e;
    SDL_Rect        mini_map_player_pos;
    const Uint8     *clavier;
    unsigned int    *p_screen;
    unsigned int    *p_mini_map_bg;
    unsigned int    *p_mini_map_add;
    unsigned int    *p_player_pos;
    int             quit;
    double          rot;
    t_point         player_pos;

}              t_data;

void create_mini_map(t_data *d, t_map_data *map);
void update_player_pos_mini_map(t_data *d, t_map_data *map);
void print_player_look_vector(t_data *d, t_map_data *map, double rot);

#endif