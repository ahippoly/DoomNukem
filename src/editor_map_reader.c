#include "global_header.h"
#include "editor.h"

char *skip_space(char *str)
{
    while (*str == ' ')
        str++;
    return (str);
}

char *skip_until_num(char *str, char limit)
{
    while (*str < '0' && *str > '9' && *str != '\0' && *str != limit)
        str++;
    return (str);
}

char *skip_until_char(char *str, char searched, char limit)
{
    while (*str != '\0' && *str != searched && *str != limit)
        str++;
    return (str);
}

int read_file(char *path_file)
{
    int fd;

    if ((fd = open(path_file, O_RDONLY) == -1))
        return (-1);
    if (read(fd, NULL, 0) == -1)
        return (-1);
}

char *read_param(char *chunk, char *key, int *to_fill)
{
    chunk = skip_space(chunk);
    if (ft_strnequ(chunk, key, ft_strlen(key)))
    {
        chunk = skip_until_num(chunk, ';');
        if (*chunk == ';')
            return;
        *to_fill = ft_atoi(chunk);
        chunk = skip_until_char(chunk, ',', ';');
        while (*chunk == ',')
        {
            *++to_fill = ft_atoi(chunk + 1);
            chunk = skip_until_char(chunk, ',', ';');
        }
    }
}

void read_wall(char *line)
{

}

void read_wall_list(int fd)
{
    
}

t_map_data  read_map(char *path_file)
{
    int         fd;
    char        buf[BUFF_SIZE];
    t_map_data  map;

    map.is_valid = 0;
    if (read_file(path_file) == -1)
        return;



    close(fd);
}