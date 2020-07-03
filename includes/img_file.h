#ifndef IMG_FILE
# define IMG_FILE
# include "SDL.h"

# define BMP_HEADER_READ 32
# define BMP_TYPE_BGRA 0
# define BMP_TYPE_ABGR 1

typedef struct      s_img
{
    unsigned int    *pixels;
    SDL_Rect        pos_size;
	int				w;
	int				h;
}                   t_img;

typedef struct      s_text
{
    t_img           img;
    SDL_Texture     *txt;
}                   t_text;


t_img create_img(unsigned int *pixels, SDL_Rect pos_size);
SDL_Texture *bmp_to_texture(char *file, SDL_Renderer *rend);


#endif