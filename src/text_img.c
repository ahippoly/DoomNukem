#include "global_header.h"
#include "editor.h"
#include "text_img.h"

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

void read_char_table(char charts[CHAR_NB][SIZE_Y][SIZE_X])
{
    int fd;
    char buf[5000];
    int i;
    int nb;
    int letter_size;

    fd = open(CHART_FILE, O_RDONLY);
    read(fd, buf, 5000);
    i = 0;
    nb = 0;
    letter_size = SIZE_X * (SIZE_Y + 1) + 1;
    while (nb < CHAR_NB)
    {
        parse_letter(charts[nb], &buf[i]);
        nb++;
        i += letter_size;
    }
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

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            charts2pixels(charts[str[i] - 'a'], size, set_pos_txt(txt, (i * SIZE_X + i) * size, 0));
        else if (str[i] >= '0' && str[i] <= '9')
            charts2pixels(charts[str[i] - '0' + 26], size, set_pos_txt(txt, (i * SIZE_X + i) * size, 0));
        else if (str[i] == ' ')
            charts2pixels(charts[36], size, set_pos_txt(txt, (i * SIZE_X + i) * size, 0));
        else if (str[i] == '_')
            charts2pixels(charts[37], size, set_pos_txt(txt, (i * SIZE_X + i) * size, 0));
        else if (str[i] == '>')
            charts2pixels(charts[38], size, set_pos_txt(txt, (i * SIZE_X + i) * size, 0));
        else if (str[i] == '<')
            charts2pixels(charts[39], size, set_pos_txt(txt, (i * SIZE_X + i) * size, 0));
        else
            //exit_with_msg("Wrong chars entered in create_text_img()");
            exit_with_msg("Wow, c'est pas alphanumerique ca ! Tu te fous de ma gueule ?");
        i++;
    }
    // printf("end read word\n");
}

t_txt_img create_text_img(char *str, int size, int color, SDL_Point pos)
{
    static char charts[CHAR_NB][SIZE_Y][SIZE_X];
    static int is_init;
    t_txt_img txt;
    int x_length;
    int len;

    if (is_init == 0)
    {
        read_char_table(charts);
        is_init = 1;
    }
    len = ft_strlen(str);
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