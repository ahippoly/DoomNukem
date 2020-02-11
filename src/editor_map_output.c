#include "global_header.h"
#include "editor.h"

char *join_int_value(int val1, char *separator, int val2)
{
    char *str;

    str = ft_itoa(val1);
    str = ft_strjoinfree(str, separator, 0);
    str = ft_strjoinfree(str, ft_itoa(val2), 0);
    return (str);
}

void write_key(int fd, char *key)
{
    write(fd, " ", 1);
    write(fd, key, ft_strlen(key));
    write(fd, " ", 1);
}

void write_param(int fd, char *key, char *value)
{
    char *str;

    str = ft_strjoin(key, " : ");
    str = ft_strjoinfree(str, value, 0);
    str = ft_strjoinfree(str, " ; ", 0);
    write(fd, str, ft_strlen(str));
    free(value);
    free(str);
}

void write_walls(int fd, t_wall *list, int wall_count)
{
    t_wall wall;
    int i;

    i = 0;
    printf("wall count = %i\n", wall_count);
    write(fd, "WALL LIST\n", 10);
    while (i < wall_count)
    {
        wall = list[i];
        write_param(fd, "id", ft_itoa(wall.id));
        write_param(fd, "p1", join_int_value(wall.p1.x, ",", wall.p1.y));
        write_param(fd, "p2", join_int_value(wall.p2.x, ",", wall.p2.y));
        write(fd, "\n", 1);
        i++;
    }
}

void write_rooms(int fd, t_room *room)
{
    int i;
    char *walls;

    while (room)
    {
        i = 0;
        write_param(fd, "id", ft_itoa(room->room_id));
    }
}

void map_output(t_env *env)
{
    int fd;
    int i;
    char *str;

    i = 0;
    printf("map output fct\n");
    while ((fd = open(str = ft_strjoinfree("maps/editor_map_", ft_itoa(i), 1), O_WRONLY | O_CREAT | O_EXCL)) == -1)
    {
        printf("i = %i fd = %i\n", i, fd);
        free(str);
        i++;
    }
    printf("map output name = %s, fd = %i\n",str, fd);
    write_walls(fd, env->wall_list, env->wall_count);
    free(str);
    close(fd);
}

