#ifndef RENDER_H
# define RENDER_H

# include "global_header.h"
# include "editor.h"
# define FOV_ANGLE 60
# define MINI_MAP_SIZE_X 250
# define MINI_MAP_SIZE_Y 250
# define MINI_MAP_POS_X WIN_SIZE_X - MINI_MAP_SIZE_X
# define MINI_MAP_POS_Y 0
# define MINI_MAP_PLAYER_SIZE 5

# define MOVE_STEP 0.08
# define ROT_STEP 0.05 * M_PI_2
# define HEIGHT_STEP 0.025
# define SCREEN_HEIGHT_STEP 15
# define WALL_SIZE 1

typedef struct      s_data
{
    SDL_Renderer    *rend;
    SDL_Window      *win;
    SDL_Texture     *screen;
    SDL_Texture     *mini_map;
    SDL_Texture     *t_player_pos;
    SDL_Event       e;
    SDL_Rect        mini_map_player_pos;
    SDL_Surface     *texture[NB_TEXTURE];
    t_map_data      map;
    const Uint8     *clavier;
    unsigned int    *p_screen;
    unsigned int    *p_mini_map_bg;
    unsigned int    *p_mini_map;
    unsigned int    *p_player_pos;
    int             quit;
    double          rot;
    t_point         player_pos;
    double          player_height;
    int             screen_height;
    t_calced_walls  *sorted_walls;
    double          speed_modifier;
    int             framerate;
    int             timestamp;
    t_sprite        sprite_lst[NB_SPRITE];
}                   t_data;

void create_mini_map(t_data *d, t_map_data *map);
void update_player_pos_mini_map(t_data *d, t_map_data *map);
void print_player_look_vector(t_data *d, t_map_data *map, double rot);
void print_mini_map(t_data *d, t_map_data *map);
SDL_Surface *read_img_surface(char *file);

//render_init_data.c
void init_sdl_ressources_rend(t_data *d);
void init_mini_map(t_data *d, t_map_data *map);
void init_data(t_data *d);

//render_event_gesture.c
void handle_key_event(t_data *d, t_map_data *map);
void handle_poll_event(t_data *d, t_map_data *map);
void move_attempt(t_point *pos, double speed, double look_rot);

//render_wall_processing.c
double calc_wall_hit_scale(t_wall wall, t_point inter);
t_calced_walls check_inter_with_wall(t_wall wall, double rot, t_point pos, double look_rot);
t_calced_walls check_intersect_with_all_wall(t_data *d, t_map_data *map, double rot, double look_rot);
void sort_walls_by_dist(t_data *d, t_map_data *map, double current_angle);
t_calced_walls check_perp_wall(t_wall wall, t_point pos);
t_calced_walls check_perp_all_wall(t_data *d, t_map_data *map, t_point pos);

//render_draw_walls.c
void draw_vertical_line(t_data *d, int x, t_calced_walls dist_scale);
void draw_floor(t_data *d, SDL_Surface *text);

//render_texture_loading.c
void load_bmp_files(t_data *d);

#endif