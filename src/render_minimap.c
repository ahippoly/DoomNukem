#include "global_header.h"
#include "render.h"
#include "editor.h"

t_point calc_map_scale(t_map_data *map)
{
    t_point scale;

    scale.x = (double)MINI_MAP_SIZE_X / map->map_size.w;
    scale.y = (double)MINI_MAP_SIZE_Y / map->map_size.h;
    return (scale);
}

void create_mini_map(t_data *d, t_map_data *map)
{
    int i;
    t_wall wall;
    t_point scale;

    free(d->p_mini_map_bg);
    d->p_mini_map_bg = alloc_image(MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y);
    draw_rectangle(d->p_mini_map_bg, set_sdl_rect(0, 0, MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y), set_size(MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y), 0xFF77AA77);
    draw_rectangle(d->p_mini_map_bg, set_sdl_rect(2, 2, MINI_MAP_SIZE_X - 4, MINI_MAP_SIZE_Y - 4), set_size(MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y), 0xFF000000);
    scale.x = (double)MINI_MAP_SIZE_X / map->map_size.w;
    scale.y = (double)MINI_MAP_SIZE_Y / map->map_size.h;
    i = 0;
    while (i < map->wall_count)
    {
        wall = map->wall_list[i];
        octant(create_point(scale.x * wall.p1.x, scale.y * wall.p1.y), 
            create_point(scale.x * wall.p2.x, scale.y * wall.p2.y), 
            d->p_mini_map_bg,
            0xFFFFBB88,
            set_sdl_rect(0, 0, MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y));
        i++;
    }
}

void update_player_pos_mini_map(t_data *d, t_map_data *map)
{
    t_point scale;

    scale.x = (double)MINI_MAP_SIZE_X / map->map_size.w;
    scale.y = (double)MINI_MAP_SIZE_Y / map->map_size.h;

    d->mini_map_player_pos.x = scale.x * d->player_pos.x;
    d->mini_map_player_pos.y = scale.y * d->player_pos.y;
}

void print_player_look_vector(t_data *d, t_map_data *map, double rot)
{
    t_point scale;
    SDL_Point screen_player_pos;

    scale = calc_map_scale(map);
    screen_player_pos = create_point(scale.x * d->player_pos.x, scale.y * d->player_pos.y);
    octant(screen_player_pos, create_point(screen_player_pos.x + cos(rot * M_PI_2) * 5, screen_player_pos.x + sin(rot * M_PI_2) * 5), d->p_mini_map_add, 0xFF8888FF, set_sdl_rect(0, 0, MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y));
}