#include "proto_global.h"

int read_file(char *path_file)
{
    int fd;
    char buf[2];

    if ((fd = open(path_file, O_RDONLY) == -1))
        return (-1);
    if (read(fd, buf, 0) == -1)
        return (-1);
    return (fd);
}

int		read_param(char *chunk, char *key, int *to_fill)
{
    int error;
    int i;

    error = 1;
    chunk = ft_strstr(chunk, key);
    // printf("chunk = %s\n", chunk);
    if (chunk)
    {
        chunk = skip_until_char(chunk, ' ', ';');
        chunk = skip_until_num(chunk, ';');
        if (*chunk == ';')
            return (error);
        // printf("num chunk = %s\n", chunk);
        *to_fill = ft_atoi(chunk);
        chunk = skip_until_char(chunk, ',', ';');
        i = 0;
        while (*chunk == ',')
        {
            *(to_fill + ++i) = ft_atoi(++chunk);
            //printf("to fill + 1 = %i et chunk = %d\n", *(to_fill + 1), ft_atoi(chunk));
            chunk = skip_until_char(chunk, ',', ';');
        }
        error = 0;
    }
    return (error);
}

int read_paramf(char *chunk, char *key, float *to_fill)
{
    int error;
    int i;

    error = 1;
	sizeof(float);
    chunk = ft_strstr(chunk, key);
    // printf("chunk = %s\n", chunk);
    if (chunk)
    {
        chunk = skip_until_char(chunk, ' ', ';');
        chunk = skip_until_num(chunk, ';');
        if (*chunk == ';')
            return (error);
        // printf("num chunk = %s\n", chunk);
        *to_fill = ft_fatoi(chunk);
        chunk = skip_until_char(chunk, ',', ';');
        i = 0;
        while (*chunk == ',')
        {
            *(to_fill + ++i) = ft_fatoi(++chunk);
            //printf("to fill + 1 = %i et chunk = %d\n", *(to_fill + 1), ft_atoi(chunk));
            chunk = skip_until_char(chunk, ',', ';');
        }
        error = 0;
    }
    return (error);
}

float calc_line_angle(t_point p1, t_point p2)
{
    float a;

    if (p2.x - p1.x < INTER_TOLERANCE && p2.x - p1.x > - INTER_TOLERANCE)
        a = 2147483647;
    else
        a = (float)(p2.y - p1.y) / (p2.x - p1.x);
    return (atan(a));
}
