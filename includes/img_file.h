#ifndef IMG_FILE
# define IMG_FILE
# include "SDL.h"

typedef struct      s_img
{
    unsigned int    *pixels;
    SDL_Rect        pos_size;
}                   t_img;

typedef struct      s_text
{
    t_img           img;
    SDL_Texture     *txt;
}                   t_text;


t_img create_img(unsigned int *pixels, SDL_Rect pos_size);
SDL_Texture *bmp_to_texture(char *file, SDL_Renderer *rend);

#endif