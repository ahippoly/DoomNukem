#ifndef TEXT_IMG
# define TEXT_IMG
# include "SDL.h"
# define CHAR_NB 38
# define CHAR_LENGTH 31
# define SIZE_X 10
# define SIZE_Y 10
# define PIXEL '#'
# define CHART_FILE "src/img_char_charts2"

typedef struct      s_txt_img
{
    unsigned int    *pixels;
    SDL_Rect        pos_size;
    int             color;
}                   t_txt_img;

t_txt_img create_text_img(char *str, int size, int color, SDL_Point pos);

#endif