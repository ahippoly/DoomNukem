#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

void init_sdl_ressources_rend(t_data *d)
{
    d->win = NULL;
    if(0 != SDL_Init(SDL_INIT_VIDEO))
        exit_with_msg("Failed to Init SDL");
    if (!(d->win = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              WIN_SIZE_X, WIN_SIZE_Y, SDL_WINDOW_SHOWN)))
        exit_with_msg("Failed to create Window");
    if (!(d->rend = SDL_CreateRenderer(d->win, -1, SDL_RENDERER_ACCELERATED)))
        exit_with_msg("Failed to create Renderer");
    d->screen = SDL_CreateTexture(d->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, WIN_SIZE_X, WIN_SIZE_Y);
    //env->stones = SDL_CreateTexture(env->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, 512, 512);
}

void init_data(t_data *d)
{
    d->rot = 1;
    d->p_screen = (unsigned int *)p_malloc(sizeof(int) * MAP_SIZE_X * MAP_SIZE_Y);
    ft_bzero(d->p_screen, sizeof(int) * MAP_SIZE_Y * MAP_SIZE_X);
}

double check_inter_with_wall(t_wall wall, double rot, t_point pos)
{
    t_point inter;
    double dist;

    dist = 0;
    inter = line_intersect(pos, rot, create_t_point(wall.p1.x, wall.p1.y), create_t_point(wall.p2.x, wall.p2.y));
    if (inter.x != -42)
        dist = ft_min(dist, cos(rot * M_PI_2) * inter.x + sin(rot * M_PI_2) * inter.y);
    return (dist);
}

double check_intersect_with_all_wall(t_data *d, t_map_data *map, double rot)
{
    int i;
    double dist;
    t_point inter;
    t_wall wall;

    i = 0;
    dist = 9999;
    while (i < map->wall_count)
    {
        wall = map->wall_list[i];
        dist = ft_fmin(dist, check_inter_with_wall(wall, rot, d->player_pos));
        i++;
    }
    return (dist);
}

void draw_vertical_line(t_data *d, int x, double dist)
{
    int draw_begin;
    int draw_end;
    int i;

    draw_begin = WIN_SIZE_Y / 2 - HALF_WIN_SIZE_Y / dist;
    draw_end = WIN_SIZE_Y / dist;
    i = 0;
    while (draw_begin < draw_end)
    {
        put_pixel(d->p_screen, create_point(x, draw_begin++), create_t_size(WIN_SIZE_X, WIN_SIZE_Y), 0xFFFFFFFF);
    }
}

void raycast_all_screen(t_data *d)
{
    double fov_coef = (double)FOV_ANGLE / 90;
    double start_angle = d->rot - fov_coef / 2;
    double end_angle = d->rot + fov_coef / 2;
    double step = fov_coef / WIN_SIZE_X;
    while (start_angle < end_angle)
    {
        start_angle += step;
    }
}

void handle_key_event(t_data *d, t_map_data *map)
{
    d->clavier = SDL_GetKeyboardState(NULL);
    if (d->clavier[SDL_SCANCODE_E])
        d->rot += 0.05;
    if (d->clavier[SDL_SCANCODE_Q])
        d->rot -= 0.05;
    if (d->clavier[SDL_SCANCODE_Z])
        check_intersect_with_all_wall(d, map, d->rot);
}

int main(void)
{
    t_map_data  map;
    t_data      d;

    init_sdl_ressources_rend(&d);
    ft_putstr("Main worked");

    map = read_map("maps/editor_map_0");
}