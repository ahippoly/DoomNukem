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
# define TILE_HITBOX 7
# define WALL_HITBOX 10
# define NB_WALL_MAX 200

# define NB_BUTTONS 5
# define BUTTON_DEL 0
# define BUTTON_CREATE_ROOM 1
# define BUTTON_TEXT_LEFT 2
# define BUTTON_TEXT_RIGHT 3
# define BUTTON_HEIGHT_INC 0.1
# define BUTTON_HEIGHT_DEFAULT 1
# define BUTTON_MAP_OUTPUT 4

#define UNIT 10

#define DEFAULT_HEIGHT_START 10

# define NB_MOUSE_MODE 3
# define MOUSE_MODE_NEUTRAL 0
# define MOUSE_MODE_CREATE_ROOM 1
# define MOUSE_MODE_INPUT 2

# define NB_INPUT 7
# define INPUT_TRANSPARENCY 0
# define INPUT_BEGIN_P1 1
# define INPUT_BEGIN_P2 2
# define INPUT_END_P1 3
# define INPUT_END_P2 4
# define INPUT_PLAYER_X 5
# define INPUT_PLAYER_Y 6

# define NB_TEXTURE 2

# define NB_TXT 12
# define TXT_MAP_EDITOR 0
# define TXT_TEXT_SELECT 1
# define TXT_HEIGHT 2
# define TXT_TRANSPARENCY 3
# define TXT_P1 4
# define TXT_P2 5
# define TXT_BEGIN 6
# define TXT_END 7
# define TXT_PLAYER_SPAWN 8
# define TXT_PLAYER_X 9
# define TXT_PLAYER_Y 10
# define TXT_WALL_COUNT 11
# define TEXT_POS_X 800
# define TEXT_POS_Y 250
# define TEXT_SIZE_X 150
# define TEXT_SIZE_Y 150
# define MOVE_SPEED 5
# define MAP_SIZE_X 30
# define MAP_SIZE_Y 30
# define INTER_TOLERANCE 0.0001


typedef struct      s_size
{   
    int             w;
    int             h;
}                   t_size;

typedef struct      s_wall
{
    int             id;
    SDL_Point       p1;
    SDL_Point       p2;
    t_range         p1_height;
    t_range         p2_height;
    int             texture_id;
    int             room_id_ref;
    int             transparency;
    int             can_collide;
}                   t_wall;

typedef struct      s_sector
{
    t_wall          wall_lst;
    int             size;
}                   t_sector;

typedef struct          s_wall_ref
{
    int                 wall_id;
    struct s_wall_ref   *next;
}                       t_wall_ref;

typedef struct          s_room
{
    int                 room_id;
    int                 nb_wall;
    int                 *wall_ref;
    struct s_room       *next;
}                       t_room;

typedef struct		s_input
{
	SDL_Rect 		pos_size;
	int				value;
	int				max;
	int				is_in_input_mode;
}					t_input;

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
    SDL_Point       start_room_point;
    SDL_Point       map_move;
    t_range         p1_height;
    t_range         p2_height;
    int             tile_size;
    int             quit;
    int             wall_count;
    int             room_count;
    int             first_wall_room_id;
    int             total_wall_created;
    int             hovered_wall_id;
    int             hovered_input_id;
    int             selected_input;
    int             selected_wall_id;
    int             selected_button;
    int             selected_mouse_mode;
    int             selected_texture;
    t_wall          *wall_list;
    t_room          *room_list;
    t_wall_ref      ***map_wall_ref;
    t_size          map_size;
    unsigned int    *p_screen;
    unsigned int    *p_grid;
    t_button        edit;
    t_button        del;
    t_button        create_room;
    t_button        text_select_left;
    t_button        text_select_right;
    t_txt_img       map_editor;
    t_txt_img       text_select;
    t_txt_img       height;
    t_txt_img       transparency;
    t_txt_img       img_p1;
    t_txt_img       img_p2;
    t_img           img_list[NB_TEXTURE];
    t_button        buttons_lst[NB_BUTTONS];
    t_txt_img       txt_lst[NB_TXT];
    t_input			input_lst[NB_INPUT];
    void            (*buttons_fct[NB_BUTTONS])(struct s_env*);
    void            (*mouse_click_fct[NB_MOUSE_MODE])(struct s_env*);
}                   t_env;


void exit_with_msg(char *msg);
SDL_Point add_sdl_point(SDL_Point p, SDL_Point add, int is_sub);
SDL_Point mult_sdl_point(SDL_Point p, double mul);
void draw_rectangle(unsigned int *pixels, SDL_Rect rect, t_size screen_size, int color);
int add_wall(SDL_Point p1, SDL_Point p2, t_env *env);
void del_wall(t_env *env, int wall_id);
void del_room(t_env *env, int room_id);
void print_walls_in_map(t_env *env);
void check_mouse_in_walls(t_env *env);
void print_selected_wall(t_env *env);
void del_wall(t_env *env, int wall_id);
void check_hovered_buttons(t_env *env);
t_button create_button(t_txt_img normal, t_txt_img hovered, int button_id);
void init_wall_ref(t_env *env);

void del_selected_wall(t_env *env);
void select_previous_texture(t_env *env);
void select_next_texture(t_env *env);
void incr_transparency(t_env *env);
void decr_transparency(t_env *env);
void move_map_move_left(t_env *env);
void move_map_move_right(t_env *env);
void move_map_move_up(t_env *env);
void move_map_move_down(t_env *env);
void change_selected_wall_texture(t_env *env, int texture_id);

void add_wall_ref_point(t_wall wall, t_env *env);
void clear_map_ref(t_env *env);
void print_wall_ref(t_env *env, int fd);
void find_sector(t_env *env, t_wall wall);
void input_text_to_img(char *str, int size, int color, t_img to_fill);

void create_room_mode(t_env *env);
void neutral_mouse_mode(t_env *env);
void handle_mouse_event(t_env *env);
void check_click(t_env *env);
void map_output(t_env *env);

void create_room_button(t_env *env);
void create_room(t_env *env, int begin, int end);
t_wall_ref *add_wall_reference(t_wall_ref *chain, int new_wall_id);
void print_rooms_content(t_env *env);
int is_cursor_in_hitbox(t_env *env, SDL_Rect pos_size);

//editor_input.c
void check_hovered_input(t_env *env);
void print_inputs(t_env *env);
t_input create_t_input(SDL_Rect pos_size, int default_value, int max);
void handle_input_mode(t_env *env, SDL_Scancode key_released);
void get_wall_param(t_env *env);
void update_wall_param(t_env *env);

#endif