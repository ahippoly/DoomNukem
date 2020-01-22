#ifndef EDITOR_H
# define EDITOR_H

# include "SDL.h"
# include "libft.h"
# include "global_header.h"

# define GRID_SIZE_X 800
# define GRID_SIZE_Y 600
# define TILE_SIZE 45
# define TILE_HITBOX 10
# define NB_WALL_MAX 200


typedef struct      s_wall
{
    int             id;
    SDL_Point       p1;
    SDL_Point       p2;
}                   t_wall;

typedef struct      s_size
{   
    int             w;
    int             h;
}                   t_size;


typedef struct      s_env
{
    SDL_Renderer    *rend;
    SDL_Event       ev;
    SDL_Window      *win;
    SDL_Texture     *screen;
    SDL_Texture     *editor_grid;
    SDL_Rect        grid_pos;
    const Uint8     *clavier;
    Uint32          mouse_button;
    SDL_Point       mouse;
    SDL_Point       hovered_corner;
    SDL_Point       selected_corner;
    int             quit;
    int             wall_count;
    int             total_wall_created;
    t_wall          *wall_list;
    unsigned int    *p_screen;
    unsigned int    *p_grid;
}                   t_env;



void exit_with_msg(char *msg);
SDL_Point add_sdl_point(SDL_Point p, int add);
SDL_Point mult_sdl_point(SDL_Point p, double mul);
void draw_rectangle(unsigned int *pixels, SDL_Rect rect, t_size screen_size, int color);
int add_wall(SDL_Point p1, SDL_Point p2, t_env *env);
void print_walls_in_map(t_env *env);

#endif