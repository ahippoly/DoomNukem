#ifndef TEXT_IMG
# include "SDL.h"
# define TEXT_IMG
# define CHAR_NB 36
# define CHAR_LENGTH 31
# define SIZE_X 5
# define SIZE_Y 5
# define PIXEL '#'

typedef struct s_txt_img
{
    unsigned int *pixels;
    SDL_Rect pos_size;
    int color;

}               t_txt_img;

t_txt_img create_text_img(char *str, int size, int color);

#endif