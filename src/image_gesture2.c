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
    SDL_Surface *readed_file;
    SDL_Texture *new;

	if ((access(file, R_OK)) < 0)
		return (NULL);
    if (!(readed_file = SDL_LoadBMP(file)))
		return (NULL);
	if (readed_file == NULL)
	{
		// printf("readed file = %s\n", file);
        ft_putendl("failed to load texture bmp file");
		return (NULL);
	}
	if ((new = SDL_CreateTextureFromSurface(rend, readed_file)) < 0)
		return (NULL);
    SDL_FreeSurface(readed_file);
    return (new);
}