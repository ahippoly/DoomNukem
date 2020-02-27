#include "global_header.h"
#include "render.h"
#include "editor.h"

void create_mini_map(t_data *d, t_map_data *map)
{
    int i;
    t_wall wall;
    t_point scale;

    free(d->p_mini_map);
    d->p_mini_map = alloc_image(MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y);
    scale.x = (double)MINI_MAP_SIZE_X / map->map_size.x;
    scale.y = (double)MINI_MAP_SIZE_Y / map->map_size.y;
    i = 0;
    while (i < map->wall_count)
    {
        wall = map->wall_list[i];
        octant(create_point(scale.x * wall.p1.x, scale.y * wall.p1.y), 
            create_point(scale.x * wall.p2.x, scale.y * wall.p2.y), 
            d->p_mini_map,
            0xFFFF0000,
            set_sdl_rect(0, 0, MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y));
        i++;
    }
}

void update_player_pos_mini_map(t_data *d)
{
    t_point scale;

    scale.x = (double)MINI_MAP_SIZE_X / map->map_size.x;
    scale.y = (double)MINI_MAP_SIZE_Y / map->map_size.y;

    d->mini_map_player_pos.x = scale.x * d->player_pos.x + (WIN_SIZE_X - MINI_MAP_SIZE_X);
    d->mini_map_player_pos.y = scale.y * d->player_pos.y;
}