#ifndef PROTOT_GLOBAL_H
# define PROTOT_GLOBAL_H

#include "data.h"
#include "proto_hud.h"
#include "proto_rend.h"
#include "proto_sound.h"
#include "proto_sprite.h"
#include "proto_ssprite.h"
#include "proto_menu.h"
#include "proto_gameplay.h"

void exit_with_msg(char *msg);
unsigned int *alloc_image(int width, int height);
SDL_Rect set_sdl_rect(int x, int y, int w, int h);
void swap_point(SDL_Point *p1, SDL_Point *p2);
void	draw_line(SDL_Point pos1, SDL_Point pos2, t_img img, int color);
SDL_Point create_point(int x, int y);
t_point create_t_point(float x, float y);
t_range create_t_range(int start, int end);
t_size create_t_size(int w, int h);
t_img	ft_load_bmp(char *file);
t_img	ft_load_bmp2(char *file);
void sort_point_by_x(SDL_Point *p1, SDL_Point *p2);
t_point segment_intersect(SDL_Point p1, SDL_Point p2, SDL_Point p3, SDL_Point p4);
t_point	line_intersect(t_point pos, float rot, t_point p1, t_point p2);
t_point inter_with_dir(t_point pos, t_rot rot, t_point p3, t_point p4);
t_point find_intersect(t_point p1, t_point p2, t_point p3, t_point p4);
t_point find_intersect_no_bound(t_point p1, t_point p2, t_point p3, t_point p4);
t_point first_segment_vertical_case(t_point p1, t_point p2, t_point p3, t_point p4);
void swap_t_point(t_point *p1, t_point *p2);
void sort_t_point_by_x(t_point *p1, t_point *p2);
void put_pixel(unsigned int *pixels, SDL_Point p_pos, t_size img_size, unsigned int color);
void put_pixel_attempt(unsigned int *pixels, SDL_Point p_pos, t_size img_size, unsigned int color);
void put_pixel_transparency(unsigned int *pixels, SDL_Rect pos_size, unsigned int color, float alpha);
int is_equ_tolerance(float value1, float value2, float tolerance);
float get_float_part(float value);
t_point sdl_p_to_t_p(SDL_Point p);
float ft_interpolate(float val1, float val2, float scale);

void swap_char(char *a, char *b);
void remove_color(unsigned int *pixels, int total_size, unsigned int color);

//editor_map_reader.c
t_map_data  read_map(char *path_file);

// void process_all_idle_anim(t_sprite sprite[NB_SPRITE]); //prend en paramètre un tableau de sprite, et calcul frame par frame leur animation par défaut
// void process_idle_anim(t_sprite *sprite); //calcul l'animation par défaut d'un sprite
// void load_anim(t_sprite *t_sprite, int anim_id); //calcul une animation du sprite puis reviens a l'animation par défaut
// void change_idle_anim(t_sprite *t_sprite, int anim_id); //change l'animation par défaut du sprite

t_rot calc_sin_cos_rot(float rot);
void sort_int(int *a, int *b);
void	*ft_memcpy_int(unsigned int *dst, const unsigned int *src, size_t n);


void print_text_screen(unsigned int *p_tab, t_img *text, SDL_Rect draw);
void calc_transparency(unsigned int *color_dst, unsigned int *color2, float alpha);
unsigned int calc_transparency2(unsigned int color_dst, unsigned int color2, float alpha);

float	get_dist(t_point pos1, t_point pos2);
t_rot	get_angle(t_point pos1, t_point pos2);
void del_from_array(void *list, int *size, void *to_remove, int obj_size);
void	*ft_memmove2(void *dst, const void *src, size_t len);

void print_sprite(t_sprite *sprite);
void    copy_frame(unsigned int *dst, SDL_Rect dst_size, unsigned int *src, SDL_Rect pos_size);
SDL_Texture *t_img2sdl_text(SDL_Renderer *rend , t_img src);
void			calc_n_disp_framerate(t_data *d, unsigned int *pix);
//void print_img_portion(unsigned int *p_tab, t_img *text, SDL_Rect src, SDL_Rect dst); // Works like SDL_RenderCopy, 24bits image not printing FFFFFF
void convert_pixel_format(unsigned int *pixels, int total_size);
t_point add_t_point(t_point p, t_point add, int is_sub);
t_point mult_t_point(t_point p, float mul);
t_point convert_sdlpoint2tpoint(SDL_Point point);
SDL_Point convert_t_point(t_point point);

/* maths.c */

int	ft_short(unsigned char *nb);
int	ft_int(unsigned char *nb);

/* bit_swaps.c */

uint32_t	swap4(uint32_t x);
uint16_t	swap2(uint16_t x);


/* exit.c */

void exit_env(t_data *d);

#endif