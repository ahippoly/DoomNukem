#include "proto_global.h"

char *join_int_value(int val1, char *separator, int val2)
{
    char *str;

    str = ft_itoa(val1);
    str = ft_strjoinfree(str, separator, 0);
    str = ft_strjoinfree(str, ft_itoa(val2), 0);
    return (str);
}

char *join_float_value(float val1, char *separator, float val2)
{
    char *str;

    str = ft_ftoa(val1, p_malloc(3), 3);
    str = ft_strjoinfree(str, separator, 0);
    str = ft_strjoinfree(str, ft_ftoa(val2, p_malloc(3), 3), 0);
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

void write_head_param(int fd, char *key, char *value)
{
    ft_putstr_fd(key, fd);
    ft_putchar_fd(' ',fd);
    ft_putstr_fd(value, fd);
    ft_putchar_fd('\n',fd);
}

void write_walls(int fd, t_wall *list, int wall_count)
{
    t_wall wall;
    int i;

    i = 0;
    printf("wall count = %i\n", wall_count);
    write(fd, "WALL LIST\n", 10);
    write_head_param(fd, "WALL_COUNT", ft_itoa(wall_count));
    while (i < wall_count)
    {
        wall = list[i];
        write_param(fd, "id", ft_itoa(wall.id));
        write_param(fd, "p1", join_float_value(wall.p1.x, ",", wall.p1.y));
        write_param(fd, "p2", join_float_value(wall.p2.x, ",", wall.p2.y));
        write_param(fd, "p1_height", join_int_value(wall.p1_height.start, ",", wall.p1_height.end));
        write_param(fd, "p2_height", join_int_value(wall.p2_height.start, ",", wall.p2_height.end));
        write_param(fd, "texture_id", ft_itoa(wall.texture_id));
        write_param(fd, "room_id_ref", ft_itoa(wall.room_id_ref));
        write_param(fd, "transparency", ft_itoa(wall.transparency));
        write_param(fd, "can_collide", ft_itoa(wall.can_collide));
        write(fd, "\n", 1);
        i++;
    }
    write(fd, "\n", 1);
}

void write_rooms(int fd, t_room *room, int room_count)
{
    int i;
    char *walls;
    t_room display;

    write(fd, "ROOM LIST\n", 10);
    write_head_param(fd, "ROOM_COUNT", ft_itoa(room_count));
    i = 0;
    while (i < room_count)
    {
        display = room[i];
        write_param(fd, "id", ft_itoa(display.room_id));
        write_param(fd, "nb_wall", ft_itoa(display.nb_wall));
        write_param(fd, "wall_ref_range", join_int_value(display.wall_ref.start, ",", display.wall_ref.end));
        write_param(fd, "height", join_int_value(display.height.start, ",", display.height.end));
        write_param(fd, "floor_text", ft_itoa(display.floor_text));
        ft_putchar_fd('\n',fd);
        i++;
    }
    ft_putstr_fd("\n\n", fd);
}

void write_wall_ref(int fd, t_env *env)
{
    ft_putstr_fd("WALL_REF MAP\n", fd);
    write_head_param(fd, "MAP_SIZE", join_int_value(env->map_size.w, ",", env->map_size.h));
    write_head_param(fd, "PLAYER_SPAWN", join_int_value((int)env->player_spawn.x, ",", (int)env->player_spawn.y));
    ft_putchar_fd('\n',fd);
}

void	write_icon_list(int fd, t_icon *icon_list, int nb_icon)
{
	int		i;
	t_icon	*current;

	ft_putstr_fd("ICON LIST\n", fd);
    write_head_param(fd, "ICON_COUNT", ft_itoa(nb_icon));
	i = 0;
    while (i < nb_icon)
    {
        current = &icon_list[i];
        write_param(fd, "id", ft_itoa(current->id_ref));
        write_param(fd, "pos", join_int_value((int)(current->pos.x * 10), ",", (int)(current->pos.y * 10)));
        ft_putchar_fd('\n',fd);
        i++;
    }
    ft_putstr_fd("\n\n", fd);
}

void map_output(t_env *env)
{
    int fd;

    printf("map output fct\n");
	if (env->map_name)
   		fd = open(env->map_name, O_WRONLY | O_TRUNC | O_CREAT, 0600);
	else
   		fd = open("maps/editor_map_0", O_WRONLY | O_TRUNC | O_CREAT, 0600);
    if (fd < 0)
        return;
	printf("env map name = %s\n", env->map_name);
    rearange_wall_lst(env);
    write_walls(fd, env->wall_list, env->wall_count);
    write_rooms(fd, env->room_list, env->room_count);
	write_icon_list(fd, env->icon_list, env->icon_count);
    write_wall_ref(fd, env);
    close(fd);
}

