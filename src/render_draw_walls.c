#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

void draw_vertical_line(t_data *d, int x, t_calced_walls dist_scale, SDL_Surface *text)
{
    int draw_begin;
    int draw_end;
    double y_scale;
    double y_step;
    int text_pixel_color;
    int *pixels;

    if (dist_scale.dist == 9999)
        return ;
    draw_begin = d->screen_height + HALF_WIN_SIZE_Y - ((1 - d->player_height) * WIN_SIZE_Y) / dist_scale.dist;
    draw_end = d->screen_height + (HALF_WIN_SIZE_Y + (d->player_height * WIN_SIZE_Y) / dist_scale.dist);
    y_scale = 0;
    y_step = (double)1 / (draw_end - draw_begin);
    y_scale += y_step * ft_max(- draw_begin, 0);
    draw_begin = ft_max(draw_begin, 0);
    draw_end = ft_min(draw_end, WIN_SIZE_Y);
    pixels = (int*)text->pixels;
    while (draw_begin < draw_end)
    {
        y_scale += y_step;
        //printf("text w = %i, h = %i, pitch = %i, scale : x = %f, y = %f\n", text->w, text->h, text->pitch, dist_scale.scale, y_scale);
        text_pixel_color = pixels[(int)(dist_scale.scale * text->w) + (int)(y_scale * text->h) * text->w];
        //printf("colour = %i\n", text_pixel_color);
        put_pixel(d->p_screen, create_point(x, draw_begin++), create_t_size(WIN_SIZE_X, WIN_SIZE_Y), text_pixel_color);
    }
}