#ifndef IMG_FILE
# define IMG_FILE
# include "SDL.h"

typedef struct      s_img
{
    unsigned int    *pixels;
    SDL_Rect        pos_size;
}                   t_img;


t_img create_img(unsigned int *pixels, SDL_Rect pos_size);

#endif