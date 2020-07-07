#include "proto_global.h"

unsigned int *alloc_image(int width, int height)
{
    unsigned int *image;

    if (!(image = (unsigned int *)malloc(sizeof(unsigned int) * width * height)))
	{
       ft_putendl("Failed To malloc");
	   return (NULL);
	}
    ft_bzero(image, width * height * sizeof(unsigned int));
    return (image);
}

t_img create_img(unsigned int *pixels, SDL_Rect pos_size)
{
    t_img img;

    img.pixels = pixels;
    img.pos_size = pos_size;
    return (img);
}

SDL_Texture		*bmp_to_texture(char *file, SDL_Renderer *rend)
{
    // SDL_Surface	*readed_file;
    SDL_Texture	*new;
	t_img img;

	if ((access(file, R_OK)) < 0)
		return (NULL);
	new = NULL;
	img.pixels = NULL;
	img = ft_load_bmp2(file, BMP_TYPE_BGRA, 0);
	new = SDL_CreateTexture(rend, SDL_PIXELFORMAT_ARGB32, SDL_TEXTUREACCESS_STREAMING, img.w, img.h);
	SDL_UpdateTexture(new, NULL, img.pixels, img.w * 4);
	SDL_SetTextureBlendMode(new, SDL_BLENDMODE_BLEND);
	free(img.pixels);
    return (new);
}