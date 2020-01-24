#include "global_header.h"
#include "editor.h"

char *create_text_img(char *str, int size, int color)
{
    static char charts[36][31];
    static int is_init;
    char *p_tab;
    int bpp;
    int len;

    if (is_init == 0)
    {
        read_char_table(charts);
        is_init = 1;
    }
    len = ft_strlen(str);
    bpp = (len * 5 + len - 1) * size;
    if (!(p_tab = (char*)malloc(sizeof(char) * bpp * 10)))
        exit_with_msg("Failed to malloc");
    ft_strlower(str);
}

void charts2pixels(char letter[31], char *p_part, int size, int bpp)
{
    int i;

    i = 0;
    while (i < 31)
    {

    }

}

void read_letter(char charts[36][31], char *p_part, char c)
{
    if (c >= 'a' && c <= 'z')
        charts2pixels(charts[c - 'a'], p_part);
    else if (c >= '0' && c <= '9')
        charts2pixels(charts[c - '0'], p_part);
    else
        exit_with_msg("Wrong chars entered in create_text_img()");
    
    
}

void read_char_table(char charts[36][31])
{
    int fd;
    char buf[5000];
    int i;
    int nb;

    fd = open("img_char_charts", O_RDONLY);
    read(fd, buf, 5000);
    i = 0;
    nb = 0;
    while (nb < 36)
    {
        ft_strncpy(charts[nb], buf[i], 30);
        nb++;
        i += 31;
    }
}