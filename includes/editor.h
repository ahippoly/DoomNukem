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

# define NB_BUTTONS 9
# define BUTTON_DEL 0
# define BUTTON_CREATE_ROOM 1
# define BUTTON_TEXT_LEFT 2
# define BUTTON_TEXT_RIGHT 3
# define BUTTON_HEIGHT_INC 0.1
# define BUTTON_HEIGHT_DEFAULT 1
# define BUTTON_MAP_OUTPUT 4
# define BUTTON_SET_PLAYER_SPAWN 5
# define BUTTON_MOB_LEFT 6
# define BUTTON_MOB_RIGHT 7
# define BUTTON_MOB_PLACING 8

#define UNIT 10

#define DEFAULT_HEIGHT_START 10

# define NB_MOUSE_MODE 3
# define MOUSE_MODE_NEUTRAL 0
# define MOUSE_MODE_CREATE_ROOM 1
# define MOUSE_MODE_PLACING 2

# define NB_INPUT 5
# define INPUT_TRANSPARENCY 0
# define INPUT_BEGIN_P1 1
# define INPUT_BEGIN_P2 2
# define INPUT_END_P1 3
# define INPUT_END_P2 4

# define NB_TEXTURE 6
# define TEXT_PATH_0 "img/textures/Red_Bricks.bmp"
# define TEXT_PATH_1 "img/textures/stones.bmp"
# define TEXT_PATH_2 "img/textures/Paver300.bmp"
# define TEXT_PATH_3 "img/textures/Floor_Wdn.bmp"
# define TEXT_PATH_4 "img/textures/WoodFine.bmp"
# define TEXT_PATH_5 "img/textures/tech_skin_1.bmp"

# define NB_TXT 11
# define TXT_MAP_EDITOR 0
# define TXT_TEXT_SELECT 1
# define TXT_HEIGHT 2
# define TXT_TRANSPARENCY 3
# define TXT_P1 4
# define TXT_P2 5
# define TXT_BEGIN 6
# define TXT_END 7
# define TXT_WALL_COUNT 8
# define TXT_MOB 9
# define TXT_ROOM_COUNT 10
# define TEXT_POS_X 800
# define TEXT_POS_Y 150
# define TEXT_SIZE_X 150
# define TEXT_SIZE_Y 150
# define MOVE_SPEED 5
# define MAP_SIZE_X 30
# define MAP_SIZE_Y 30

# define NB_IMG 3

# define ICON_ARRAY_SIZE 20
# define ICON_PLAYER_SIZE 30
# define ICON_MOB_RANGE_BEGIN 1
# define ICON_MOB_RANGE_END 3
# define ICON_MOB_POS_X 800
# define ICON_MOB_POS_Y 400
# define ICON_MOB_SIZE_X 150
# define ICON_MOB_SIZE_Y 150

# define HEAD_WALL_LIST "WALL LIST"
# define HEAD_ROOM_LIST "ROOM LIST"
# define HEAD_WALL_REF "WALL_REF MAP"


typedef struct		s_input
{
	SDL_Rect 		pos_size;
	int				value;
	int				max;
	int				is_in_input_mode;
}					t_input;

typedef struct      s_icon
{
    t_point         pos;
    t_size          size;
    int             id_ref;
}                   t_icon;

typedef struct      s_env
{
    SDL_Renderer    *rend;
    SDL_Event       ev;
    SDL_Window      *win;
    SDL_Texture     *screen;
    SDL_Texture     *editor_grid;
    SDL_Texture     *text_list[NB_TEXTURE];
    SDL_Texture     *img_list[NB_IMG];
    SDL_Rect        grid_pos;
    const Uint8     *clavier;
    unsigned int    *p_screen;
    unsigned int    *p_grid;
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
	int				icon_count;
	int				icon_list_size;
    int             first_wall_room_id;
    int             total_wall_created;
    int             hovered_wall_id;
    int             hovered_input_id;
    t_icon          mouse_icon;
    int             selected_input;
    int             selected_wall_id;
    int             selected_button;
    int             selected_mouse_mode;
    int             selected_texture;
    int             selected_mob;
    t_point         player_spawn;
    t_point         *being_placed;
    t_wall          *wall_list;
    t_room          *room_list;
	t_icon			*icon_list;
    t_wall_ref      ***map_wall_ref;
    t_size          map_size;
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
t_wall_ref ***init_wall_ref(t_size map_size);
void recreate_full_map_ref(t_env *env);

void del_selected_wall(t_env *env);
void set_player_spawn_mode(t_env *env);
void select_previous_texture(t_env *env);
void select_next_texture(t_env *env);
void mob_placing_mode(t_env *env);
void incr_transparency(t_env *env);
void decr_transparency(t_env *env);
void move_map_move_left(t_env *env);
void move_map_move_right(t_env *env);
void move_map_move_up(t_env *env);
void move_map_move_down(t_env *env);
void change_selected_wall_texture(t_env *env, int texture_id);

void add_wall_ref_point(t_wall wall, t_env *env);
void clear_map_ref(t_env *env);
void print_wall_ref(t_wall_ref ***map_wall_ref, t_size map_size, int fd);
void find_sector(t_env *env, t_wall wall);
void input_text_to_img(char *str, int size, int color, t_img to_fill);

void create_room_mode(t_env *env);
void neutral_mouse_mode(t_env *env);
void on_screen_place_mode(t_env *env);
void handle_mouse_event(t_env *env);
void check_click(t_env *env);
void map_output(t_env *env);
void rearange_wall_lst(t_env *env);
void recreate_room_list(t_env *env);

void create_room_button(t_env *env);
void create_room(t_env *env, int begin, int end);
t_wall_ref *add_wall_reference(t_wall_ref *chain, int new_wall_id);
void print_rooms_content(t_room *room_list, int room_count);
int is_cursor_in_hitbox(t_env *env, SDL_Rect pos_size);

//editor_input.c
void check_hovered_input(t_env *env);
void print_inputs(t_env *env);
t_input create_t_input(SDL_Rect pos_size, int default_value, int max);
void handle_input_mode(t_env *env, SDL_Scancode key_released);
void get_wall_param(t_env *env);
void update_wall_param(t_env *env);

//editor_debug_utils.c
void debug_print(t_env *env, SDL_Scancode key);
void print_wall_content(t_wall wall);
void print_wall_list(t_map_data *map);

//utils.c
SDL_Rect set_sdl_rect(int x, int y, int w, int h);
t_size set_size(int w, int h);
SDL_Rect adapt_border(SDL_Rect pos_size, t_size max);
void draw_rectangle(unsigned int *pixels, SDL_Rect rect, t_size screen_size, int color);
void create_straight_line(unsigned int *pixels, SDL_Rect pos_size, t_size screen_length, int color);
void create_straight_column(unsigned int *pixels, SDL_Rect pos_size, t_size screen_length, int color);
void adapt_min(int *pos, int *length);
void adapt_max(int *pos, int *length, int max);

//editor_icon.c
t_icon create_icon(t_point pos, t_size size, int id_ref);
void add_icon(t_env *env, t_icon new);
void print_mouse_icon(t_env *env);
void print_player_spawn(t_env *env);
void print_icon_list(t_env *env);

void select_previous_mob(t_env *env);
void select_next_mob(t_env *env);

#endif