#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"

t_point calc_map_scale(t_map_data *map)
{
    t_point scale;

    scale.x = (float)MINI_MAP_SIZE_X / map->map_size.w;
    scale.y = (float)MINI_MAP_SIZE_Y / map->map_size.h;
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
    scale.x = (float)MINI_MAP_SIZE_X / map->map_size.w;
    scale.y = (float)MINI_MAP_SIZE_Y / map->map_size.h;
    i = 0;
    while (i < map->wall_count)
    {
        wall = map->wall_list[i];
        draw_line(create_point(scale.x * (wall.p1.x - d->player_pos.x + map->map_size.w * 0.5), scale.y * (wall.p1.y - d->player_pos.y + map->map_size.h * 0.5)), 
            create_point(scale.x * (wall.p2.x - d->player_pos.x + map->map_size.w * 0.5), scale.y * (wall.p2.y - d->player_pos.y + map->map_size.h * 0.5)), 
            (t_img){d->p_mini_map_bg, (SDL_Rect){0, 0, MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y}},
            0xFFFFBB88);
        i++;
    }
}

void update_player_pos_mini_map(t_data *d, t_map_data *map)
{
    t_point scale;

    // scale.x = (float)MINI_MAP_SIZE_X / map->map_size.w;
    // scale.y = (float)MINI_MAP_SIZE_Y / map->map_size.h;

    // d->mini_map_player_pos.x = ft_range(scale.x * d->player_pos.x, 0, MINI_MAP_SIZE_X);
    // d->mini_map_player_pos.y = ft_range(scale.y * d->player_pos.y, 0, MINI_MAP_SIZE_Y);
	d->mini_map_player_pos.x = ft_range(MINI_MAP_SIZE_X * 0.5, 0, MINI_MAP_SIZE_X);
	d->mini_map_player_pos.y = ft_range(MINI_MAP_SIZE_Y * 0.5, 0, MINI_MAP_SIZE_Y);
}

void print_player_look_vector(t_data *d, t_map_data *map, float rot)
{
    t_point scale;
    SDL_Point screen_player_pos;
    float      fov;

    fov =  d->fov_rad / 2;
    scale = calc_map_scale(map);
    screen_player_pos = create_point(d->mini_map_player_pos.x + MINI_MAP_PLAYER_SIZE / 2, d->mini_map_player_pos.y + MINI_MAP_PLAYER_SIZE / 2);
    //look vector // draw_line(screen_player_pos, create_point(screen_player_pos.x + cos(rot) * 25, screen_player_pos.y + sin(rot) * 25), d->p_mini_map, 0xFF8888FF, set_sdl_rect(0, 0, MINI_MAP_SIZE_X, MINI_MAP_SIZE_X));
    draw_line(screen_player_pos, create_point(screen_player_pos.x + cos(rot + fov) * 45, screen_player_pos.y + sin(rot + fov) * 45), (t_img){d->p_mini_map, (SDL_Rect){0, 0, MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y}}, 0xFF00DDDD);
    draw_line(screen_player_pos, create_point(screen_player_pos.x + cos(rot - fov) * 45, screen_player_pos.y + sin(rot - fov) * 45), (t_img){d->p_mini_map, (SDL_Rect){0, 0, MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y}}, 0xFF00DDDD);
}

void print_mini_map(t_data *d, t_map_data *map)
{
    SDL_Rect tmp;
    tmp = set_sdl_rect(0, 0, MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y);
    //ft_bzero(d->p_mini_map, MINI_MAP_SIZE_X * MINI_MAP_SIZE_Y * 4);
    ft_memcpy_int(d->p_mini_map, d->p_mini_map_bg, MINI_MAP_SIZE_X * MINI_MAP_SIZE_Y);
    print_player_look_vector(d, map, d->rot);
    SDL_UpdateTexture(d->mini_map, &tmp, d->p_mini_map, MINI_MAP_SIZE_X * 4);
    SDL_UpdateTexture(d->mini_map, &d->mini_map_player_pos, d->p_player_pos, MINI_MAP_PLAYER_SIZE * 4);
    //SDL_UpdateTexture(d->mini_map, &tmp, d->p_mini_map, MINI_MAP_SIZE_X * 4);


}