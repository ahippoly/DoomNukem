#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

void draw_floor(t_data *d, SDL_Surface *text)
{
    int x;
    int y;
    int p;

    float fov_coef = (float)FOV_ANGLE / 90;
    

    float ray_dir_x0;
    float ray_dir_y0;
    float ray_dir_x1;
    float ray_dir_y1;


    float pos_z;

    float rowDistance;

    float floorStepX;
    float floorStepY;

    float floorX;
    float floorY;

    int tx;
    int ty;

    int text_acces_pos;

    int *pixels;

    ray_dir_x0 = cos(d->rot) + fov_coef * sin(d->rot);
    ray_dir_x1 = cos(d->rot) - fov_coef * sin(d->rot);
    ray_dir_y0 = sin(d->rot) - fov_coef * cos(d->rot);
    ray_dir_y1 = sin(d->rot) + fov_coef * cos(d->rot);
    // printf("raydir: 0 : %f,%f ; 1 : %f,%f\n", ray_dir_x0, ray_dir_y0, ray_dir_x1, ray_dir_y1);
    y = d->screen_height + 1;
    pos_z = (d->player_height - DEFAULT_Z_GROUND ) * WIN_SIZE_Y;

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