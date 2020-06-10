#include "global_header.h"
#include "img_file.h"

unsigned int *alloc_image(int width, int height)
{
    unsigned int *image;

    if (!(image = (unsigned int *)malloc(sizeof(unsigned int) * width * height)))
       exit_with_msg("Failed To malloc");
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

SDL_Texture *bmp_to_texture(char *file, SDL_Renderer *rend)
{
    SDL_Surface *readed_file;
    SDL_Texture *new;

    readed_file = SDL_LoadBMP(file);
    if (readed_file == NULL)
        exit_with_msg("failed to load texture bmp file");
    new = SDL_CreateTextureFromSurface(rend, readed_file);
    SDL_FreeSurface(readed_file);
    return (new);
}