#ifndef EDITOR_H
# define EDITOR_H

# include "SDL.h"
# include "libft.h"
# include "global_header.h"
# include "text_img.h"

# define GRID_SIZE_X 800
# define GRID_SIZE_Y 600
# define TILE_SIZE 45
# define TILE_HITBOX 10
# define WALL_HITBOX 10
# define NB_WALL_MAX 200
# define BUTTON_DEL 0
# define BUTTON_EDIT 1


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
    int             hovered_wall_id;
    int             selected_wall_id;
    int             selected_button;
    t_wall          *wall_list;
    unsigned int    *p_screen;
    unsigned int    *p_grid;
    t_txt_img       edit;
    t_txt_img       del;
    t_txt_img       edit_white;
    t_txt_img       del_white;
    unsigned int    *edit_selected;
    unsigned int    *del_selected;
}                   t_env;



void exit_with_msg(char *msg);
SDL_Point add_sdl_point(SDL_Point p, int add);
SDL_Point mult_sdl_point(SDL_Point p, double mul);
void draw_rectangle(unsigned int *pixels, SDL_Rect rect, t_size screen_size, int color);
int add_wall(SDL_Point p1, SDL_Point p2, t_env *env);
void del_wall(t_env *env, int wall_id);
void print_walls_in_map(t_env *env);
void check_mouse_in_walls(t_env *env);
void print_selected_wall(t_env *env);
void del_wall(t_env *env, int wall_id);
void check_hovered_buttons(t_env *env);


#endif