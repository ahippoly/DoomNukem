#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

void draw_vertical_line(t_data *d, int x, t_calced_walls dist_scale)
{
    int draw_begin;
    int draw_end;
    float ty_step;
    int text_pixel_color;
    int *pixels;
    int tx;
    float ty;
    SDL_Surface *text;

    if (dist_scale.dist == 9999)
        return ;
    text = d->texture[dist_scale.text_id];
    draw_begin = d->screen_height - ((1 - d->player_height) * WIN_SIZE_Y) / dist_scale.dist;
    draw_end = d->screen_height + (d->player_height * WIN_SIZE_Y) / dist_scale.dist;
    ty_step = (float)text->h / (draw_end - draw_begin);
    draw_end = ft_min(draw_end, WIN_SIZE_Y);
    pixels = (int*)text->pixels;
    tx = (int)(dist_scale.scale * text->w);
    ty = ty_step * ft_max(- draw_begin, 0);
    draw_begin = ft_max(draw_begin, 0);
    while (draw_begin < draw_end)
    {
        ty += ty_step;
        //printf("text w = %i, h = %i, pitch = %i, scale : x = %f, y = %f\n", text->w, text->h, text->pitch, dist_scale.scale, y_scale);
        text_pixel_color = pixels[text->w * (int)ty + tx];
        //printf("colour = %i\n", text_pixel_color);
        put_pixel_transparency(d->p_screen, (SDL_Rect){x, draw_begin++, WIN_SIZE_X, WIN_SIZE_Y}, text_pixel_color, dist_scale.alpha);
    }
}

void draw_floor(t_data *d, SDL_Surface *text)
{
    int x;
    int y;
    int p;

    double fov_coef = (double)FOV_ANGLE / 90;
    

    double ray_dir_x0;
    double ray_dir_y0;
    double ray_dir_x1;
    double ray_dir_y1;

    double rot_pi_2;

    double pos_z;

    double rowDistance;

    double floorStepX;
    double floorStepY;

    double floorX;
    double floorY;

    int tx;
    int ty;

    int text_acces_pos;

    int *pixels;

    rot_pi_2 = d->rot * M_PI_2;
    ray_dir_x0 = cos(rot_pi_2) + fov_coef * sin(rot_pi_2);
    ray_dir_x1 = cos(rot_pi_2) - fov_coef * sin(rot_pi_2);
    ray_dir_y0 = sin(rot_pi_2) - fov_coef * cos(rot_pi_2);
    ray_dir_y1 = sin(rot_pi_2) + fov_coef * cos(rot_pi_2);
    // printf("raydir: 0 : %f,%f ; 1 : %f,%f\n", ray_dir_x0, ray_dir_y0, ray_dir_x1, ray_dir_y1);
    y = d->screen_height + 1;
    pos_z = d->player_height * WIN_SIZE_Y;

    pixels = (int*)text->pixels;
    

    // real world coordinates of the leftmost column. This will be updated as we step to the right.
    
    while (y < WIN_SIZE_Y)
    {
        p = y - d->screen_height;
        rowDistance = pos_z / p;
        // printf("Pos_z = %f, p = %d, rowDistance = %f\n", pos_z, p, rowDistance);

        floorStepX = rowDistance * (ray_dir_x1 - ray_dir_x0) / WIN_SIZE_X;
        floorStepY = rowDistance * (ray_dir_y1 - ray_dir_y0) / WIN_SIZE_X;

        floorX = (d->player_pos.x + rowDistance * ray_dir_x0);
        floorY = (d->player_pos.y + rowDistance * ray_dir_y0);

        x = 0;
        // printf("floor: %f,%f\n", floorX, floorY);
        // printf("floorSTEP : %f,%f\n", floorStepX, floorStepY);

        while (x < WIN_SIZE_X)
        {


      
        // get the texture coordinate from the fractional part
        // floorX = fabs(floorX);
        // floorY = fabs(floorY);
        
        

        text_acces_pos = ((int)(get_float_part(floorX) * text->w) & (text->w - 1)) + ((int)(get_float_part(floorY) * text->h) & (text->h - 1)) * text->w;
        floorX += floorStepX;
        floorY += floorStepY;

     
        // printf("tx = %d, ty = %d, ty2 = %d\n", (int)(get_float_part(floorX) * text->w), (int)(get_float_part(floorY) * text->h) * text->w, (int)(get_float_part(floorY) * text->h * text->w));
        // printf("x scale = %f, y scale = %f\n", get_float_part(floorX), get_float_part(floorY));
        put_pixel(d->p_screen, create_point(x, y), create_t_size(WIN_SIZE_X, WIN_SIZE_Y), pixels[text_acces_pos]);
        x++;
      }
      y++;
    }
}