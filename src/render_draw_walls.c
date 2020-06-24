#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"



// void draw_vertical_line(t_data *d, int x, t_calced_walls dist_scale)
// {
//     int draw_begin;
//     int draw_end;
//     float ty_step;
//     unsigned int text_pixel_color;
//     unsigned int *pixels;
//     int tx;
//     float ty;
// 	float	wall_size;
// 	float	wall_start;
// 	float	wall_begin;
// 	int		draw_length;
//     SDL_Surface *text;

//     if (dist_scale.dist == 9999)
//         return ;
//     text = d->texture[dist_scale.wall.texture_id];
//     // draw_begin = d->screen_height - ((1 - d->player_height + 0.5) * WIN_SIZE_Y) / dist_scale.dist;
//     // draw_end = d->screen_height + ((d->player_height + 0.5) * WIN_SIZE_Y) / dist_scale.dist;
// 	wall_begin = ft_interpolate(dist_scale.wall.p1_z_start, dist_scale.wall.p2_z_start, dist_scale.scale_z);
// 	wall_size = ft_interpolate(dist_scale.wall.p1_z_size, dist_scale.wall.p2_z_size, dist_scale.scale_z);
// 	wall_start = ft_interpolate(dist_scale.wall.p1_z_start + dist_scale.wall.p1_z_size, dist_scale.wall.p2_z_start + dist_scale.wall.p2_z_size, dist_scale.scale_z);
// 	draw_begin = d->screen_height - ((wall_start - d->player_height) * WIN_SIZE_Y) / dist_scale.dist;
//     draw_end = d->screen_height + ((d->player_height - wall_begin) * WIN_SIZE_Y) / dist_scale.dist;
// 	draw_length = draw_end - draw_begin;
//     ty_step = ((float)text->h * wall_size) / (draw_length);
//     draw_end = ft_min(draw_end, WIN_SIZE_Y);
//     pixels = (unsigned int*)text->pixels;
//     tx = (int)(dist_scale.scale * text->w);
// 	// printf("wall begin = %f, wall start = %f, draw_length = %i\n", wall_begin, wall_start, draw_length);
//     ty =  get_float_part(1 - wall_start + dist_scale.wall.z_text_offset) * (float)text->h
// 		+ ty_step * ft_max(- draw_begin, 0);
// 	while (ty < 0)
// 			ty = text->h + ty;
//     draw_begin = ft_max(draw_begin, 0);
// 	//printf("ty = %f\n", ty);
//     while (draw_begin < draw_end)
//     {
//         //printf("text w = %i, h = %i, pitch = %i, scale : x = %f, y = %f\n", text->w, text->h, text->pitch, dist_scale.scale, ty);
// 		while (ty >= text->h)
// 			ty -= text->h;
// 		// if (text->w * (int)ty + tx >= text->w * text->h)
// 		// 	printf("ty = %f\n", ty);
//         text_pixel_color = pixels[text->w * (int)ty + tx];
//         ty += ty_step;
//         //printf("colour = %i\n", text_pixel_color);
//         put_pixel_transparency(d->p_screen, (SDL_Rect){x, draw_begin++, WIN_SIZE_X, WIN_SIZE_Y}, text_pixel_color, dist_scale.wall.alpha);
//     }
// }

