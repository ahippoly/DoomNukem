#ifndef EDITOR_H
# define EDITOR_H

# include "SDL.h"
# include "libft.h"
# include "global_header.h"
# include "text_img.h"
# include "img_file.h"

# define GRID_POS_X 0
# define GRID_POS_Y 60
# define GRID_SIZE_X 761
# define GRID_SIZE_Y 561
# define TILE_SIZE 40
# define TILE_HITBOX 10
# define WALL_HITBOX 10
# define NB_WALL_MAX 200
# define BUTTON_DEL 0
# define BUTTON_EDIT 1
# define BUTTON_TEXT_LEFT 2
# define BUTTON_TEXT_RIGHT 3
# define NB_BUTTONS 4
# define NB_TEXTURE 2
# define TEXT_POS_X 800
# define TEXT_POS_Y 250
# define TEXT_SIZE_X 150
# define TEXT_SIZE_Y 150



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
    SDL_Texture     *stones;
    SDL_Texture     *text_list[NB_TEXTURE];
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
    int             selected_texture;
    t_wall          *wall_list;
    unsigned int    *p_screen;
    unsigned int    *p_grid;
    t_button        edit;
    t_button        del;
    t_button        text_select_left;
    t_button        text_select_right;
    t_txt_img       map_editor;
    t_txt_img       text_select;
    t_img           img_list[NB_TEXTURE];
    t_txt_img       *edit_selected;
    t_txt_img       *del_selected;
    void            (*buttons_fct[NB_BUTTONS])(struct s_env*);
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
t_button create_button(t_txt_img normal, t_txt_img hovered, int button_id);

void del_selected_wall(t_env *env);
void select_previous_texture(t_env *env);
void select_next_texture(t_env *env);


#endif