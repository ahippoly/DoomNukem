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
    while ((*str < '0' || *str > '9') && *str != '\0' && *str != limit)
        str++;
    return (str);
}

char *skip_until_char(char *str, char searched, char limit)
{
    while (*str != '\0' && *str != searched && *str != limit)
        str++;
    return (str);
}

int is_white_space(char c)
{
    if ((c < 14 && c > 8) || c == 32)
        return (1);
    return (0);
}

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

int read_param(char *chunk, char *key, int *to_fill)
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
            printf("to fill + 1 = %i et chunk = %d\n", *(to_fill + 1), ft_atoi(chunk));
            chunk = skip_until_char(chunk, ',', ';');
        }
        error = 0;
    }
    return (error);
}

void read_wall(char *line, t_wall *wall)
{
    int error;

    error = 0;
    error += read_param(line, "id", &wall->id);
    error += read_param(line, "p1", &wall->p1.x);
    error += read_param(line, "p2", &wall->p2.x);
    error += read_param(line, "p1_height", &wall->p1_height.start);
    error += read_param(line, "p2_height", &wall->p2_height.start);
    error += read_param(line, "texture_id", &wall->texture_id);
    error += read_param(line, "room_id_ref", &wall->room_id_ref);
    error += read_param(line, "transparency", &wall->transparency);
    //printf("WALL ID READED\n");
    //printf("p1.x = %i, p1.y = %i\n", wall->p1.x, wall->p1.y);
    if (error > 0)
        exit_with_msg("error while assigning value to wall on map reader\n");
}

void read_room(char *line, t_room *room)
{
    int error;

    error = 0;
    error += read_param(line, "id", &room->room_id);
    error += read_param(line, "nb_wall", &room->nb_wall);
    error += read_param(line, "wall_ref_range", &room->wall_ref.start);
    if (error > 0)
        exit_with_msg("error while assigning value to room on map reader\n");
}

t_wall_ref *read_wall_ref(char *chunk)
{
    t_wall_ref *wall_ref;
    int i;

    wall_ref = NULL;
    i = 0;
    wall_ref = add_wall_reference(wall_ref, ft_atoi(chunk));
    //printf("%i ", ft_atoi(chunk));
    chunk = skip_until_char(chunk, ',', ' ');
    while (*chunk == ',')
    {
        chunk++;
        wall_ref = add_wall_reference(wall_ref, ft_atoi(chunk));
        //printf("%i ", ft_atoi(chunk));
        chunk = skip_until_char(chunk, ',', ' ');
    }
    return (wall_ref);
}

void read_wall_ref_list(int fd, t_map_data *map)
{
    char *line;
    int i;
    int j;

    if (get_next_line(fd, &line) == 1)
        read_param(line, "MAP_SIZE", &map->map_size.w);
    else
        exit_with_msg("error while reading map");
    if (get_next_line(fd, &line) == 1)
        read_param(line, "PLAYER_SPAWN", &map->player_spawn.x);
    else
        exit_with_msg("error while reading map");
    map->map_wall_ref = init_wall_ref(map->map_size);
    printf("WALL REF DEBUG \n");
    i = 0;
    while (i < map->map_size.h)
    {
        j = 0;
        if (get_next_line(fd, &line) != 1)
            exit_with_msg("error while reading wall ref map");
        while (j < map->map_size.w)
        {
            line = skip_space(line);
            map->map_wall_ref[i][j] = read_wall_ref(line);
            //printf("i %i, j %i ", i, j);
            line = skip_until_char(line, ' ', '\0');
            printf("line = %s\n", line);
            j++;
        }
        printf("\n");
        i++;
    }
}

void read_wall_list(int fd, t_map_data *map)
{
    char    *line;
    int     i;

    if (get_next_line(fd, &line) == 1)
        read_param(line, "WALL_COUNT", &map->wall_count);
    else
        exit_with_msg("error while reading map");
    printf("WALL COUNT READED, value = %i\n", map->wall_count);
    if (!(map->wall_list = (t_wall*)malloc(sizeof(t_wall) * map->wall_count)))
        exit_with_msg("Failed to malloc");
    i = 0;
    while (get_next_line(fd, &line) == 1 && *line != '\0' && i < map->wall_count)
        read_wall(line, &map->wall_list[i++]);
}

void read_room_list(int fd, t_map_data *map)
{
    char *line;
    int i;

    if (get_next_line(fd, &line) == 1)
        read_param(line, "ROOM_COUNT", &map->room_count);
    else
        exit_with_msg("error while reading map");
    if (!(map->room_list = (t_room*)malloc(sizeof(t_room) * map->room_count)))
        exit_with_msg("Failed to malloc");
    i = 0;
    while (get_next_line(fd, &line) == 1 && *line != '\0' && i < map->room_count)
        read_room(line, &map->room_list[i++]);
}

void read_head(int fd, char *line, t_map_data *map)
{
    printf("line = %s\n", line);
    if (ft_strequ(line, "WALL LIST"))
    {
        printf("wALL LIST READED\n");
        read_wall_list(fd, map);
    }
    if (ft_strequ(line, "ROOM LIST"))
    {
        read_room_list(fd, map);
    }
    if (ft_strequ(line, "WALL_REF MAP"))
    {
        read_wall_ref_list(fd, map);
    }
}

t_map_data  read_map(char *path_file)
{
    int         fd;
    char        buf[BUFF_SIZE];
    t_map_data  map;
    char *line;

    map.is_valid = 0;
    fd = 500;
    line = NULL;
    printf("started map read\n");
    if ((fd = open(path_file, O_RDONLY)) == -1)
        return (map);
    printf("ca merde, fd = %i\n", fd);
    // get_next_line(fd, &line);
    // printf("line 1 = %s\n", line);
    while (get_next_line(fd, &line) == 1)
        read_head(fd, line, &map);
    map.is_valid = 1;
    // print_wall_list(&map);
    // print_rooms_content(map.room_list, map.room_count);
    // print_wall_ref(map.map_wall_ref, map.map_size, 1);
    close(fd);
    return (map);
}