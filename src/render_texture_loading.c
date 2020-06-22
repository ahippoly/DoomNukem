#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

t_img read_img_surface(char *file)
{
    SDL_Surface		*readed_file;
    SDL_Surface		*converted;
    SDL_PixelFormat *format;
	t_img			img;

    readed_file = SDL_LoadBMP(file);
    if (readed_file == NULL)
        exit_with_msg("failed to load texture bmp file");
    format = SDL_AllocFormat(SDL_PIXELFORMAT_ARGB32);
    converted = SDL_ConvertSurface(readed_file, format, 0);
    SDL_FreeFormat(format);
    SDL_FreeSurface(readed_file);
	img.pixels = alloc_image(converted->w, converted->h);
	ft_memcpy_int(img.pixels, converted->pixels, converted->w * converted->h);
	//img.pixels = converted->pixels;
	img.w = converted->w;
	img.h = converted->h;
    //SDL_LockSurface(readed_file);
    printf("texture w,h = %i,%i, pith = %i\n",converted->w, converted->h, converted->pitch);
    SDL_FreeSurface(converted);
    return (img);
}

void load_bmp_files(t_data *d)
{
    d->texture[0] = read_img_surface(TEXT_PATH_0);
    d->texture[1] = read_img_surface(TEXT_PATH_1);
    d->texture[2] = read_img_surface(TEXT_PATH_2);
    d->texture[3] = read_img_surface(TEXT_PATH_3);
    d->texture[4] = read_img_surface(TEXT_PATH_4);
    d->texture[5] = read_img_surface(TEXT_PATH_5);
}

void init_rend_img(t_data *d)
{
	d->img[0] = read_img_surface(IMG_PATH_0);
	d->img[1] = read_img_surface(IMG_PATH_1);
	d->img[2] = read_img_surface(IMG_PATH_2);
}