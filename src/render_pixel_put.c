#include "proto_global.h"

void put_pix(unsigned int *pixels, t_draw p_pos, t_img text, SDL_Point t_cord)
{
	//printf("putpix : screen : %i,%i, t_cord : %i,%i, t_size : %i,%i\n", p_pos.start_x, p_pos.start_y / WIN_SIZE_X, t_cord.x, t_cord.y, text.w, text.h);
	pixels[p_pos.start_x + p_pos.start_y] = text.pixels[t_cord.x + t_cord.y * text.w];
}


void put_pix_alpha(unsigned int* pixels, t_draw p_pos, unsigned int color, float alpha)
{
    int pixel_pos;
    int dst_color;

    pixel_pos = p_pos.start_x + p_pos.start_y;
    dst_color = pixels[pixel_pos];
    calc_transparency(&color, &dst_color, alpha);
    pixels[pixel_pos] = color;
}