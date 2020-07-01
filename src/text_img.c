#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"

/*SDL_Rect precision : x and y are beginning pos of letter. h and w are size of image */
void charts2pixels(char letter[SIZE_Y][SIZE_X], int size, t_txt_img txt)
{
    int i;
    int j;
    int x;
    int y;
    int size2;

    y = 0;
    size2 = size * 2;
    while (y < SIZE_Y)
    {
        x = 0;
        while (x < SIZE_X)
        {
            if (letter[y][x] == 1)
            {
                j = -1;
                while (++j < size2)
                {
                    i = 0;
                    while (i < size)
                        txt.pixels[(txt.pos_size.x + (x * size) + i++) + (txt.pos_size.y + (y * size2) + j) * txt.pos_size.w] = txt.color;
                }
            }
            x++;
        }
        y++;
    }
}

void parse_letter(char charts[SIZE_Y][SIZE_X], char *letter)
{
    int x;
    int y;
    int i;

    y = 0;
    i = 0;
    while (y < SIZE_Y)
    {
        x = 0;
        while (x < SIZE_X)
        {
            if (letter[i++] == PIXEL)
            {
                charts[y][x] = 1;
            }
            else
            {
                charts[y][x] = 0;
            }
            x++;
        }
        i++;
        y++;
    }
}

char (*read_char_table(void))[SIZE_Y][SIZE_X]
{
    char buf[5000];
    int i;
    static int nb;
    int letter_size;
    static char charts[CHAR_NB][SIZE_Y][SIZE_X];

    if (nb == 0)
    {
        read(open(CHART_FILE, O_RDONLY), buf, 5000);
        i = 0;
        letter_size = SIZE_X * (SIZE_Y + 1) + 1;
        while (nb < CHAR_NB)
        {
            parse_letter(charts[nb], &buf[i]);
            nb++;
            i += letter_size;
        }
    }
    return (charts);
}

t_txt_img set_pos_txt(t_txt_img txt, int x, int y)
{
    txt.pos_size.x = x;
    txt.pos_size.y = y;
    return (txt);
}

void read_words(char charts[CHAR_NB][SIZE_Y][SIZE_X], char *str, int size, t_txt_img txt)
{
    int i;
    t_txt_img draw_letter;

    i = 0;
    while (str[i] != '\0')
    {
        draw_letter = set_pos_txt(txt, txt.pos_size.x + (i * SIZE_X + i) * size, txt.pos_size.y);
        if (str[i] >= 'a' && str[i] <= 'z')
            charts2pixels(charts[str[i] - 'a'], size, draw_letter);
        else if (str[i] >= '0' && str[i] <= '9')
            charts2pixels(charts[str[i] - '0' + 26], size, draw_letter);
        else if (str[i] == ' ')
            charts2pixels(charts[36], size, draw_letter);
        else if (str[i] == '_')
            charts2pixels(charts[37], size, draw_letter);
        else if (str[i] == '>')
            charts2pixels(charts[38], size, draw_letter);
        else if (str[i] == '<')
            charts2pixels(charts[39], size, draw_letter);
		else if (str[i] == '-')
            charts2pixels(charts[40], size, draw_letter);
        else
            //exit_with_msg("Wrong chars entered in create_text_img()");
            {
                printf("character attemped to print = %c, the full string is %s\n", str[i], str);
                exit_with_msg("Wow, c'est pas alphanumerique ca ! Tu te fous de ma gueule ?\n");
            }
        i++;
    }
    // printf("end read word\n");
}

void input_text_to_img(char *str, int size, int color, t_img to_fill)
{
    char        (*charts)[SIZE_Y][SIZE_X];
    t_txt_img   txt;

    txt.pixels = to_fill.pixels;
    txt.pos_size = to_fill.pos_size;
    txt.color = color;
    charts = read_char_table();
    //printf("size : x=%i, y=%i, w=%i, h=%i\n", txt.pos_size.x, txt.pos_size.y, txt.pos_size.w, txt.pos_size.h);
    str = ft_strlower(ft_strdup(str));
    read_words(charts, str, size, txt);
    free(str);
}

t_txt_img create_text_img(char *str, int size, int color, SDL_Point pos)
{
    //char charts[CHAR_NB][SIZE_Y][SIZE_X];
    char (*charts)[SIZE_Y][SIZE_X];
    t_txt_img txt;
    int x_length;
    int len;

    charts = read_char_table();
    len = ft_strlen(str);
    txt.pos_size.x = 0;
    txt.pos_size.y = 0;
    txt.pos_size.w = (len * SIZE_X + len - 1) * size;
    txt.pos_size.h = SIZE_Y * size * 2;
    txt.color = color;
    if (!(txt.pixels = (unsigned int*)malloc(sizeof(unsigned int) * txt.pos_size.w * txt.pos_size.h)))
        exit_with_msg("Failed to malloc");
    ft_bzero(txt.pixels, txt.pos_size.w * txt.pos_size.h * sizeof(int));
    str = ft_strlower(ft_strdup(str));    
    read_words(charts, str, size, txt);
    free(str);
    txt.pos_size.x = pos.x;
    txt.pos_size.y = pos.y;
    return (txt);
}