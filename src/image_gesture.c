#include "global_header.h"
#include "img_file.h"


void put_pixel(unsigned int *pixels, SDL_Point p_pos, t_size img_size, unsigned int color)
{
    pixels[p_pos.x + p_pos.y * img_size.w] = color;
}

void calc_transparency(unsigned int *color_dst, unsigned int *color2, float alpha)
{
    int i;
    unsigned char *nb;
    unsigned char *nb2;
	float rev_alp;

    i = 0;
    nb = (unsigned char*)color_dst;
    nb2 = (unsigned char*)color2;
	rev_alp = 1 - alpha;
    while (i++ < 4)
        nb[i] = rev_alp * nb[i] + alpha * nb2[i];
}

unsigned int calc_transparency2(unsigned int color_dst, unsigned int color2, float alpha)
{
    int i;
    unsigned char *nb;
    unsigned char *nb2;
	float rev_alp;

    i = 0;
    nb = (unsigned char*)&color_dst;
    nb2 = (unsigned char*)&color2;
	rev_alp = 1 - alpha;
    while (i++ < 3)
        nb[i] = rev_alp * nb[i] + alpha * nb2[i];
	return (color_dst);
}

void put_pixel_transparency(unsigned int *pixels, SDL_Rect pos_size, unsigned int color, float alpha)
{
    int pixel_pos;
    int dst_color;

    pixel_pos = pos_size.x + pos_size.y * pos_size.w;
    dst_color = pixels[pixel_pos];
    calc_transparency(&color, &dst_color, alpha);
    pixels[pixel_pos] = color;
}

void put_pixel_attempt(unsigned int *pixels, SDL_Point p_pos, t_size img_size, unsigned int color)
{
    int pixel_pos;

    pixel_pos = p_pos.x + p_pos.y * img_size.w;
    if (!pixels[pixel_pos])
        pixels[pixel_pos] = color;
}



// void copy_frame(t_sprite sprite, unsigned int* dst)
// {
// 	SDL_Point pos;
// 	SDL_Point pos2;
// 	SDL_Point frame_max;

// 	frame_max.x = sprite.displayed_part.x + sprite.frame_size.x;
// 	frame_max.y = sprite.displayed_part.y + sprite.frame_size.y;

// 	pos.y = sprite.displayed_part.y;
// 	while (pos.y < frame_max.y)
// 	{
// 		pos.x = sprite.displayed_part.x;
// 		pos2.x = 0;
// 		while (pos.x < frame_max.x)
// 		{
// 			dst[pos2.x + pos2.y] = sprite.pixels[pos.x + pos.y];
// 			pos.x++;
// 		}
// 		pos2.y += sprite.frame_size.x;
// 		pos.y += sprite.total_size.w;
// 	}
// }