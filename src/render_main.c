#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

SDL_Surface *read_img_surface(char *file)
{
    SDL_Surface *readed_file;
    SDL_Surface *final;
    SDL_PixelFormat *format;

    readed_file = SDL_LoadBMP(file);
    if (readed_file == NULL)
        exit_with_msg("failed to load texture bmp file");
    format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA32);
    final = SDL_ConvertSurface(readed_file, format, 0);
    SDL_FreeFormat(format);
    SDL_FreeSurface(readed_file);
    //SDL_LockSurface(readed_file);
    return (final);
}

void raycast_all_screen(t_data *d, t_map_data *map)
{
    double fov_coef = (double)FOV_ANGLE / 90;
    double current_angle = d->rot - fov_coef / 2;
    double step = fov_coef / WIN_SIZE_X;
    int x;
    int i;

    x = 0;
    while (x < WIN_SIZE_X)
    {
        i = 0;
        sort_walls_by_dist(d, map, current_angle);
        while (i < map->wall_count)
            draw_vertical_line(d, x, d->sorted_walls[i++], d->texture);
        //draw_vertical_line(d, x, check_intersect_with_all_wall(d, map, current_angle, d->rot), d->texture);
        current_angle += step;
        x++;
    }
}

void print_data2screen(t_data *d, t_map_data *map)
{
    SDL_Rect tmp;
    //printf("before print\n");
    SDL_RenderClear(d->rend);
    SDL_UpdateTexture(d->screen, NULL, d->p_screen, WIN_SIZE_X * 4);
    print_mini_map(d, map);
    SDL_RenderCopy(d->rend, d->screen, NULL, NULL);
    tmp = set_sdl_rect(MINI_MAP_POS_X, MINI_MAP_POS_Y, MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y);
    SDL_RenderCopy(d->rend, d->mini_map, NULL, &tmp);
    SDL_RenderPresent(d->rend);
}

void free_render_env(t_data *d)
{
    free(d->sorted_walls);
}

int main(void)
{
    t_map_data  map;
    t_data      d;

    init_sdl_ressources_rend(&d);
    map = read_map("maps/editor_map_0");
    init_data(&d, &map);
    ft_putstr("Main worked");

    d.player_pos = create_t_point(map.player_spawn.x, map.player_spawn.y);
    printf("player pos = %f, %f, wall count = %i\n", d.player_pos.x, d.player_pos.y, map.wall_count);
    while (!d.quit)
    {
        ft_bzero(d.p_screen, sizeof(int) * WIN_SIZE_X * WIN_SIZE_Y);
        SDL_PumpEvents();
        handle_key_event(&d, &map);
        handle_poll_event(&d, &map);
        draw_floor(&d, d.texture);
        raycast_all_screen(&d, &map);
        //draw_vertical_line(&d, 500, check_intersect_with_all_wall(&d, &map, d.rot));
        update_player_pos_mini_map(&d, &map);
        print_player_look_vector(&d, &map, d.rot);
        print_data2screen(&d, &map);
    }
    free_render_env(&d);
}