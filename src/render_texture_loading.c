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
    // printf("texture w,h = %i,%i, pith = %i\n",converted->w, converted->h, converted->pitch);
    SDL_FreeSurface(converted);
    return (img);
}

void	load_bmp_files(t_data *d)
{
	char	*path;
	int	i;

	path = ft_strnew(36);
	i = 0;
    while (i < NB_TEXTURE)
	{
		ft_strcpy(path, "asset/img/textures/TEXT_PATH_");
		ft_strcat(path, ft_itoa(i));
		ft_strcat(path, ".bmp");
		d->texture[i] = read_img_surface(path, SDL_PIXELFORMAT_ARGB32);
		ft_bzero(path, sizeof(char *));
		i++;
	}
	free(path);
}

void init_rend_img(t_data *d)
{
	d->img[IMG_PLAYER] = read_img_surface(IMG_PATH_0, SDL_PIXELFORMAT_ARGB32);
	d->img[IMG_AFRIT] = read_img_surface(IMG_PATH_1, SDL_PIXELFORMAT_ARGB32);
	d->img[IMG_ORC] = read_img_surface(IMG_PATH_2, SDL_PIXELFORMAT_ARGB32);
	d->img[IMG_KEY] = read_img_surface(IMG_PATH_3, SDL_PIXELFORMAT_ARGB32);
	d->img[IMG_HEAL_PACK] = read_img_surface(IMG_PATH_4, SDL_PIXELFORMAT_ARGB32);
	d->img[IMG_SHIP] = read_img_surface(IMG_PATH_5, SDL_PIXELFORMAT_ARGB32);
	d->img[IMG_JETPACK] = read_img_surface(IMG_PATH_6, SDL_PIXELFORMAT_ARGB32);
}