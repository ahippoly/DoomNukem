#include "global_header.h"
#include "img_file.h"

unsigned int *alloc_image(int width, int height)
{
    unsigned int *image;

    if (!(image = (unsigned int *)malloc(sizeof(unsigned int) * width * height)))
       exit_with_msg("Failed To malloc");
    return (image);
}

t_img create_img(unsigned int *pixels, SDL_Rect pos_size)
{
    t_img img;

    img.pixels = pixels;
    img.pos_size = pos_size;
    return (img);
}

void put_pixel(unsigned int *pixels, SDL_Point p_pos, t_size img_size, int color)
{
    pixels[p_pos.x + p_pos.y * img_size.w] = color;
}