#ifndef TEXT_IMG
# define TEXT_IMG
# include "SDL.h"
# define CHAR_NB 40
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

typedef struct      s_button
{
    t_txt_img       *printed;
    t_txt_img       normal;
    t_txt_img       hovered;
    int             button_id;  
}                   t_button;

typedef struct		s_input
{
	SDL_Rect 		pos_size;
	int				value;
	int				max;
	int				is_in_input_mode;
}					t_input;

t_txt_img create_text_img(char *str, int size, int color, SDL_Point pos);

#endif