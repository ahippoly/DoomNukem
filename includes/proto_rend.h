#ifndef PROTO_REND_H
# define PROTO_REND_H

#include "data.h"

void			create_mini_map(t_data *d, t_map_data *map);
void			update_player_pos_mini_map(t_data *d);
void			print_player_look_vector(t_data *d, t_map_data *map, float rot);
void			print_mini_map(t_data *d, t_map_data *map);
t_img			read_img_surface(char *file, Uint32 pixel_format);

/* sdl_init.c */
void			init_sdl_ressources_rend(t_data *d);

/* editor_wall_add_del2.c */
t_calced_walls	check_intersect_with_all_wall_rend(t_data *d, t_point pos, t_rot rot, t_rot look_rot);

//render_init_data.c
void init_mini_map(t_data *d, t_map_data *map);
void init_data(t_data *d, int ac, char **av);
int	init_hud_data(t_data *d);
int	init_hud(t_data *d);
int	init_pscreen(t_data *d);

//render_event_gesture.c
void handle_key_event(t_data *d);
void handle_poll_event(t_data *d);

//render_movement.c
float mod_pi(float rot);
void move_attempt(t_data *d, t_point *pos, float speed, t_rot look_rot);
void move_with_collide(t_data *d, t_obj *obj, t_rot rot, float speed);
void move_with_collide_player(t_data *d, t_point *pos, t_rot rot, float speed);
void gravity(t_data *d);
int		check_collide(t_data *d, t_ray *res, float z_pos, int *will_collide);
int		is_angle_in_range(float rot, float min, float max);
t_point check_wall_front(t_point pos, t_rot rot, t_ray *ray);

//render_wall_processing.c
float calc_wall_hit_scale(t_wall wall, t_point inter);
t_calced_walls check_inter_with_wall(t_wall wall, t_rot rot, t_point pos, t_rot look_rot);
void sort_walls_by_dist(t_data *d, t_point pos, t_rot current_angle, t_calced_walls *sorted_walls);
void sort_walls_by_dist_player(t_data *d, t_point pos, t_rot current_angle, t_calced_walls *sorted_walls);
void sort_ray_by_dist_player(t_data *d, t_point pos, t_rot current_angle, t_ray *sorted);
void sort_ray_by_dist(t_data *d, t_point pos, t_rot current_angle, t_ray *sorted);

t_calced_walls check_perp_wall(t_wall wall, t_point pos);
t_calced_walls check_perp_all_wall(t_data *d, t_map_data *map);
void sort_perp_walls_dist(t_map_data *map, t_point pos, t_calced_walls *sorted_walls);
t_ray check_inter_with_obj(t_obj *obj, t_rot rot, t_point pos, t_rot look_rot);
t_ray check_perp_obj(t_obj *obj, t_point pos);
void sort_perp_ray(t_data *d, t_point pos, t_ray *sorted);

//render_ray_utils.c
float	calc_ray_hit_scale(t_point p1, t_point p2, t_point inter);
void	init_ray(t_ray *res, t_obj *obj);
void	init_perp_points(t_point *p1, t_point *p2, t_point pos, t_rot look_rot);
void	define_z_text(t_ray *res);


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
void	raycast_screen2(t_data *d, t_range screen_x, float start_angle, float step);
//render_raycast_utils.c
void	clear_p_tab(t_range screen_x, unsigned int *p_tab);
t_room	*get_room_by_id(t_data *d, int room_id);
void	add_to_queue(int *nb, t_ray *queue, t_ray *checked);
void	draw_same_room(t_data *d, t_ray *ray, t_ray *checked, int x);

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
void	init_floor(t_data *d, t_floor *fl, float pos_z);
void	init_floors(t_data *d);
void print_floor(t_data *d);
void draw_all_floor_slice(t_data *d);
void draw_floor2(t_data *d, t_floor *fl, double height);

//render_props.c
void print_prop(t_data *d, t_props *prop);
t_range	calc_prop_draw_range(t_data *d, float dist, float height, float size);
void create_obj_raybox(t_data *d);
void check_props_collect(t_data *d, t_props *props, t_hud *hud);

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

//render_load_icons.c
void load_icons(t_data *d, t_map_data *map);

void move_mobs_in_range(t_data *d, t_mob *mobs, int nb_mob);
void gravity_obj(t_data *d, t_obj *objs, int nb_obj);
void repulse_obj(t_data *d, t_obj *obj, float z_force);
void load_repulsed_obj(t_data *d, t_obj **repulsed, int nb_pulse);
void shoot_gun(t_data *d, t_weapon *weapon);
void process_mobs_gameplay(t_data *d);

//render_skybox.c
void print_skybox(t_data *d, t_img skybox, float rot, unsigned int *screen);


void    init_sprite(t_data *d);
void handle_key_event_sprite(t_data *d, t_map_data *map);
void handle_mouse_event_gun(t_data *d, t_map_data *map);
/* ttf_init.c */

int					init_ttf(t_data *d);
int					quit_ttf(t_data *d);

int					render_game(t_data *d);

//render_icon2obj_type.c
t_mob	add_mob_demon(t_data *d, SDL_Point pos);
t_mob	add_mob_pyro(t_data *d, SDL_Point pos);
t_props	add_prop_key(t_data *d, SDL_Point pos);
t_props	add_prop_heal_pack(t_data *d, SDL_Point pos);
t_props	add_prop_ship(t_data *d, SDL_Point pos);

//render_init_data2.c
void	init_mini_map(t_data *d, t_map_data *map);
int		init_menu(t_data *d);
int		init_gameover(t_data *d); // doit etre initialisée après init_menu car partage la meme structure t_menu !
int		init_hud(t_data *d);

t_point calc_map_scale(t_map_data *map);



#endif