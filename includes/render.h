#ifndef RENDER_H
# define RENDER_H

# include "global_header.h"
# include "editor.h"
# include "mobs.h"
# include "props.h"

# define FOV_ANGLE 60
# define MINI_MAP_SIZE_X 250
# define MINI_MAP_SIZE_Y 250
# define MINI_MAP_POS_X WIN_SIZE_X - MINI_MAP_SIZE_X
# define MINI_MAP_POS_Y 0
# define MINI_MAP_PLAYER_SIZE 5

# define MOVE_STEP 3
# define ROT_STEP 0.05 * M_PI_2
# define MOUSE_SENS 0.004
# define Y_VIEW_RANGE 1
# define HEIGHT_STEP 0.025
# define SCREEN_HEIGHT_STEP 15
# define WALL_SIZE 0.5
# define GRAVITY_FORCE 0.0000005
# define JUMP_FORCE 0.1
# define DEFAULT_Z_GROUND 2
# define PLAYER_HEIGHT 0.5
# define THREAD_NB 4
# define MOVE_WALL_Z_SPEED 4
# define NB_MAX_PROPS 10
# define NB_MAX_MOBS 10
# define NB_MAX_OBJ 230
# define TYPE_WALL -1
# define TYPE_PROP -2
# define TYPE_MOB -3

typedef struct      s_sound
{
    Uint32 wav_length; // length of our sample
	Uint8 *wav_buffer; // buffer containing our audio file
	SDL_AudioSpec wav_spec; // the specs of our piece of music
}                   t_sound;

typedef struct	s_proj_point
{
	int			screen_x;
	float		dist;
	float		wall_start;
	float		wall_size;
	float		scale_x;
	float		scale_len;
	int			on_screen;
}				t_proj_point;

typedef	struct	s_proj_wall
{
	t_proj_point	p1;
	t_proj_point	p2;
	t_wall			wall;
}				t_proj_wall;

typedef	struct	s_draw_line
{
	t_frange	draw_y;
	int			x;
	float		scale_x;
	float		scale_z;
	float		scale_z_step;
	unsigned int	*text;
	int			tw;
	int			th;
}				t_draw_line;

typedef	struct		s_floor
{
	t_point			floor;
	t_point			floor_step;
}					t_floor;

typedef	struct				s_look_rot
{
	float					angle;
	float					step;
	float					rev;
}							t_look_rot;

typedef	struct				s_props
{
				t_point		pos;
				float		size;
				float		z_pos;
				char		collectable;
				char		can_collide;
				char		id;
				t_img		*text;
				t_obj		*obj_ref;
}							t_props;

typedef struct      s_data
{
    SDL_Renderer    *rend;
    SDL_Window      *win;
    SDL_Texture     *screen;
    SDL_Texture     *mini_map;
    SDL_Texture     *t_player_pos;
    SDL_Event       e;
    SDL_Rect        mini_map_player_pos;
    t_img			texture[NB_TEXTURE];
	t_img			img[NB_IMG];
    t_map_data      map;
    const Uint8     *clavier;
    unsigned int    *p_screen;
    unsigned int    *p_mini_map_bg;
    unsigned int    *p_mini_map;
    unsigned int    *p_player_pos;
    int             quit;
    float			rot;
	t_rot			rot_calc;
	float			fov;
	float			fov_rad;
    t_point         player_pos;
    float			player_height;
    float			z_pos;
    float			z_offset;
    float			z_force;
    float			z_ground;
    int             screen_height;
    float			speed_modifier;
    int             framerate;
    int             time_last_frame;
    int             time;
	float			diff_time;
    int             air_time;
    t_sprite        sprite_lst[NB_SPRITE];
	/* world edit*/
	t_wall			*grabbed_wall;
	t_point			grab_pos;
	float			grab_z;
	/* floor drawing */
	t_floor			fl[NB_WALL_MAX / 2][WIN_SIZE_Y];
	t_props			props[NB_MAX_PROPS];
	int				nb_props;
	t_mob			mobs[NB_MAX_MOBS];
	int				nb_mob;
	t_obj			obj_list[NB_MAX_OBJ];
	int				nb_obj;
	t_obj			*repulsed[15];
	int				nb_repulsed;
	int				bullet;
	t_sprite        sprite[15];
    int             gun_ind;
    int             mob_ind;
    int             mobs_on_screen;
	t_sound			sound[30];
	/* hud data */
    unsigned int    *p_hud; // hud screen
    SDL_Texture     *hud_texture; //hud texture
	t_hud			hud;
	/* ttf data */
	TTF_Font		*font_nb;
	TTF_Font		*font_text;
}                   t_data;

typedef	struct		s_thread
{
	float			start_angle;
	float			step;
	t_range			screen_x;
	t_data			*d;
}					t_thread;

void create_mini_map(t_data *d, t_map_data *map);
void update_player_pos_mini_map(t_data *d, t_map_data *map);
void print_player_look_vector(t_data *d, t_map_data *map, float rot);
void print_mini_map(t_data *d, t_map_data *map);
t_img read_img_surface(char *file);

//render_init_data.c
void init_sdl_ressources_rend(t_data *d);
void init_mini_map(t_data *d, t_map_data *map);
void init_data(t_data *d, int ac, char **av);
int					init_hud_data(t_data *d);
int					init_hud(t_data *d);
int					init_pscreen(t_data *d);

//render_event_gesture.c
void handle_key_event(t_data *d);
void handle_poll_event(t_data *d);

//render_movement.c
void move_attempt(t_data *d, t_point *pos, float speed, t_rot look_rot);
void move_with_collide(t_data *d, t_obj *obj, t_rot rot, float speed);
void move_with_collide_player(t_data *d, t_point *pos, t_rot rot, float speed);
void gravity(t_data *d);

//render_wall_processing.c
float calc_wall_hit_scale(t_wall wall, t_point inter);
t_calced_walls check_inter_with_wall(t_wall wall, t_rot rot, t_point pos, t_rot look_rot);
t_calced_walls check_intersect_with_all_wall(t_data *d, t_point pos, t_rot rot, t_rot look_rot);
void sort_walls_by_dist(t_data *d, t_point pos, t_rot current_angle, t_calced_walls *sorted_walls);
void sort_walls_by_dist_player(t_data *d, t_point pos, t_rot current_angle, t_calced_walls *sorted_walls);
void sort_ray_by_dist_player(t_data *d, t_point pos, t_rot current_angle, t_ray *sorted);
void sort_ray_by_dist(t_data *d, t_point pos, t_rot current_angle, t_ray *sorted);

t_calced_walls check_perp_wall(t_wall wall, t_point pos);
t_calced_walls check_perp_all_wall(t_data *d, t_map_data *map, t_point pos);
void sort_perp_walls_dist(t_data *d, t_map_data *map, t_point pos, t_calced_walls *sorted_walls);
t_ray check_inter_with_obj(t_obj *obj, t_rot rot, t_point pos, t_rot look_rot);
t_ray check_perp_obj(t_obj *obj, t_point pos);
void sort_perp_ray(t_data *d, t_point pos, t_ray *sorted);


//render_draw_walls.c
void draw_vertical_line(t_data *d, int x, t_calced_walls dist_scale);
void draw_floor(t_data *d, SDL_Surface *text);

//render_texture_loading.c
void load_bmp_files(t_data *d);
void init_rend_img(t_data *d);

//render_raycast.C
void	raycast_screen(t_data *d, t_range screen_x, float start_angle, float step);
void	*raycast_thread(void *data);
void	raycast_thread_init(t_data *d);
void	raycast_all_screen(t_data *d, t_map_data *map);

//render_world_edit.c
int		grab_wall(t_data *d, t_point pos, t_rot look_rot);
void	move_wall(t_data *d, t_wall *wall, t_rot look_rot, float speed);
void	move_grabbed_wall(t_data *d, t_rot look_rot, float speed);
void	move_z_grabbed_wall(t_data *d, float z_diff);
void	rot_wall(t_wall *wall, float rot, int pivot_point);
void	rot_grabbed_wall(t_data *d, float rot, int pivot_point);

int	check_obj_room(t_data *d, t_point pos);
float set_room_ground(t_data *d, t_point pos);

//render_wall_proj.c
void print_wall(t_data *d, t_wall wall);
void print_walls(t_data *d);
t_proj_point		point_x_on_screen(t_data *d, t_point point, float rot, t_point pos);

//render_draw_floor.c
void draw_floor(t_data *d, SDL_Surface *text);
t_draw calc_floor_draw_range(t_data *d, t_ray ray1, float dist2, int x);
t_draw calc_floor_draw_range_end(t_data *d, float dist1, t_room *room, int x);



void draw_floor_line(t_data *d, t_range draw, int x, int room_id);
// void	print_floor_slice(t_data *d, t_floor *fl, int x, t_range y, int text_id);
void	print_floor_slice(t_data *d, t_floor *fl, t_draw draw, int text_id);
void init_floor(t_data *d, t_floor *fl, double height);
void	init_floors(t_data *d);
void print_floor(t_data *d);
void draw_all_floor_slice(t_data *d);
void draw_floor2(t_data *d, t_floor *fl, double height);

//render_props.c
void print_prop(t_data *d, t_props *prop);
t_range	calc_prop_draw_range(t_data *d, float dist, float height, float size);
void create_obj_raybox(t_data *d);

//render_obj.c
void init_obj_list(t_data *d);
void sort_ray_by_dist_player(t_data *d, t_point pos, t_rot current_angle, t_ray *sorted);
void del_obj(t_obj *obj_list, int *nb_obj, t_obj *obj);

//render_draw_slice.c
void draw_ray_obj(t_data *d, t_ray ray, t_obj *obj, int x);
t_draw	calc_ray_draw_range(t_data *d, t_ray ray, int x);
void draw_text_slice(unsigned int *pixels, t_draw range, t_obj obj, t_ray ray);
void draw_ray_simple(t_data *d, t_ray ray, t_draw draw, t_obj *obj);

//render_debug_print.c
void print_ray(t_ray ray);

//render_pixel_put.c
void put_pix_alpha(unsigned int *pixels, t_draw p_pos, unsigned int color, float alpha);
void put_pix(unsigned int *pixels, t_draw p_pos, t_img text, SDL_Point t_cord);

t_room	*get_room_by_id(t_data *d, int room_id);

//render_load_icons.c
void load_icons(t_data *d, t_map_data *map);

void move_mobs_in_range(t_data *d, t_mob *mobs, int nb_mob);
void gravity_obj(t_data *d, t_obj *objs, int nb_obj);
void repulse_obj(t_data *d, t_obj *obj, float z_force, float speed);
void load_repulsed_obj(t_data *d, t_obj **repulsed, int nb_pulse);

/* ttf_init.c */

int					init_ttf(t_data *d);
int					quit_ttf(t_data *d);

#endif