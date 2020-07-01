#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"

t_img read_img_surface(char *file, Uint32 pixel_format)
{
    SDL_Surface		*readed_file;
    SDL_Surface		*converted;
    SDL_PixelFormat *format;
	t_img			img;

    readed_file = SDL_LoadBMP(file);
    if (readed_file == NULL)
	{
		printf("file = %s\n", file);
        exit_with_msg("failed to load texture bmp file\n");
	}
    format = SDL_AllocFormat(pixel_format);
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
    d->texture[0] = read_img_surface(TEXT_PATH_0, SDL_PIXELFORMAT_ARGB32);
    d->texture[1] = read_img_surface(TEXT_PATH_1, SDL_PIXELFORMAT_ARGB32);
    d->texture[2] = read_img_surface(TEXT_PATH_2, SDL_PIXELFORMAT_ARGB32);
    d->texture[3] = read_img_surface(TEXT_PATH_3, SDL_PIXELFORMAT_ARGB32);
    d->texture[4] = read_img_surface(TEXT_PATH_4, SDL_PIXELFORMAT_ARGB32);
    d->texture[5] = read_img_surface(TEXT_PATH_5, SDL_PIXELFORMAT_ARGB32);
    d->texture[6] = read_img_surface(TEXT_PATH_6, SDL_PIXELFORMAT_ARGB32);
    d->texture[7] = read_img_surface(TEXT_PATH_7, SDL_PIXELFORMAT_ARGB32);
    d->texture[8] = read_img_surface(TEXT_PATH_8, SDL_PIXELFORMAT_ARGB32);
    d->texture[9] = read_img_surface(TEXT_PATH_9, SDL_PIXELFORMAT_ARGB32);
    d->texture[10] = read_img_surface(TEXT_PATH_10, SDL_PIXELFORMAT_ARGB32);
    d->texture[11] = read_img_surface(TEXT_PATH_11, SDL_PIXELFORMAT_ARGB32);
    d->texture[12] = read_img_surface(TEXT_PATH_12, SDL_PIXELFORMAT_ARGB32);
    d->texture[13] = read_img_surface(TEXT_PATH_13, SDL_PIXELFORMAT_ARGB32);
    d->texture[14] = read_img_surface(TEXT_PATH_14, SDL_PIXELFORMAT_ARGB32);
    d->texture[15] = read_img_surface(TEXT_PATH_15, SDL_PIXELFORMAT_ARGB32);
    d->texture[16] = read_img_surface(TEXT_PATH_16, SDL_PIXELFORMAT_ARGB32);
    d->texture[17] = read_img_surface(TEXT_PATH_17, SDL_PIXELFORMAT_ARGB32);
    d->texture[18] = read_img_surface(TEXT_PATH_18, SDL_PIXELFORMAT_ARGB32);
    d->texture[19] = read_img_surface(TEXT_PATH_19, SDL_PIXELFORMAT_ARGB32);
    d->texture[20] = read_img_surface(TEXT_PATH_20, SDL_PIXELFORMAT_ARGB32);
    d->texture[21] = read_img_surface(TEXT_PATH_21, SDL_PIXELFORMAT_ARGB32);
    d->texture[22] = read_img_surface(TEXT_PATH_22, SDL_PIXELFORMAT_ARGB32);
    d->texture[23] = read_img_surface(TEXT_PATH_23, SDL_PIXELFORMAT_ARGB32);
    d->texture[24] = read_img_surface(TEXT_PATH_24, SDL_PIXELFORMAT_ARGB32);
}

void init_rend_img(t_data *d)
{
	d->img[IMG_PLAYER] = read_img_surface(IMG_PATH_0, SDL_PIXELFORMAT_ARGB32);
	d->img[IMG_AFRIT] = read_img_surface(IMG_PATH_1, SDL_PIXELFORMAT_ARGB32);
	d->img[IMG_ORC] = read_img_surface(IMG_PATH_2, SDL_PIXELFORMAT_ARGB32);
	d->img[IMG_KEY] = read_img_surface(IMG_PATH_3, SDL_PIXELFORMAT_ARGB32);
	d->img[IMG_HEAL_PACK] = read_img_surface(IMG_PATH_4, SDL_PIXELFORMAT_ARGB32);
}