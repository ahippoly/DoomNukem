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
    d->mini_map = SDL_CreateTexture(d->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y);
    //SDL_SetTextureBlendMode(d->mini_map, SDL_BLENDMODE_BLEND);
    //env->stones = SDL_CreateTexture(env->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, 512, 512);
}

void init_mini_map(t_data *d, t_map_data *map)
{
    d->p_mini_map_bg = NULL;
    create_mini_map(d, map);
    SDL_UpdateTexture(d->mini_map, NULL, d->p_mini_map_bg, MINI_MAP_SIZE_X * 4);
    d->p_player_pos = alloc_image(MINI_MAP_PLAYER_SIZE, MINI_MAP_PLAYER_SIZE);
    d->p_mini_map = alloc_image(MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y);
    draw_rectangle(d->p_player_pos, set_sdl_rect(0, 0, MINI_MAP_PLAYER_SIZE, MINI_MAP_PLAYER_SIZE), set_size(MINI_MAP_PLAYER_SIZE, MINI_MAP_PLAYER_SIZE), 0xFF0000FF);
    d->mini_map_player_pos = set_sdl_rect(WIN_SIZE_X - MINI_MAP_SIZE_X, 0, MINI_MAP_PLAYER_SIZE, MINI_MAP_PLAYER_SIZE);
}

void init_data(t_data *d, t_map_data *map)
{
    init_mini_map(d, map);
    d->rot = 1;
    d->quit = 0;
  //  d->p_screen = (unsigned int *)p_malloc(sizeof(int) * MAP_SIZE_X * MAP_SIZE_Y);
    d->p_screen = alloc_image(WIN_SIZE_X, WIN_SIZE_Y);
    ft_bzero(d->p_screen, sizeof(int) * MAP_SIZE_Y * MAP_SIZE_X);
}

double check_inter_with_wall(t_wall wall, double rot, t_point pos, double look_rot)
{
    t_point inter;
    double dist;

    dist = 9999;
    inter = inter_with_dir(pos, rot, create_t_point(wall.p1.x, wall.p1.y), create_t_point(wall.p2.x, wall.p2.y));
    if (inter.x != -42)
        dist = ft_frange(cos(look_rot * M_PI_2) * inter.x + sin(look_rot * M_PI_2) * inter.y, 0, dist);
    return (dist);
}

double check_intersect_with_all_wall(t_data *d, t_map_data *map, double rot, double look_rot)
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
        dist = ft_fmin(dist, check_inter_with_wall(wall, rot, d->player_pos, look_rot));
        i++;
    }
    printf("dist of closest wall : %f\n", dist);
    return (dist);
}

void draw_vertical_line(t_data *d, int x, double dist)
{
    int draw_begin;
    int draw_end;
    int i;

    draw_begin = ft_max(WIN_SIZE_Y / 2 - HALF_WIN_SIZE_Y / dist, 0);
    draw_end = ft_min(WIN_SIZE_Y / dist, WIN_SIZE_Y);
    i = 0;
    while (draw_begin < draw_end)
    {
        put_pixel(d->p_screen, create_point(x, draw_begin++), create_t_size(WIN_SIZE_X, WIN_SIZE_Y), 0xFFFFFFFF);
    }
}

void raycast_all_screen(t_data *d, t_map_data *map)
{
    double fov_coef = (double)FOV_ANGLE / 90;
    double start_angle = d->rot - fov_coef / 2;
    double end_angle = d->rot + fov_coef / 2;
    double step = fov_coef / WIN_SIZE_X;
    int x;

    x = 0;
    while (x < WIN_SIZE_X)
    {
        draw_vertical_line(d, x, check_intersect_with_all_wall(d, map, start_angle, d->rot));
        start_angle += step;
        x++;
    }
}

void handle_key_event(t_data *d, t_map_data *map)
{
    d->clavier = SDL_GetKeyboardState(NULL);
    if (d->clavier[SDL_SCANCODE_E])
        d->rot += 0.02;
    if (d->clavier[SDL_SCANCODE_Q])
        d->rot -= 0.02;
    if (d->clavier[SDL_SCANCODE_D])
        d->player_pos.x += 0.02;
    if (d->clavier[SDL_SCANCODE_A])
        d->player_pos.x -= 0.02;
    if (d->clavier[SDL_SCANCODE_W])
        d->player_pos.y -= 0.02;
    if (d->clavier[SDL_SCANCODE_S])
        d->player_pos.y += 0.02;
    if (d->clavier[SDL_SCANCODE_ESCAPE])
        d->quit = 1;
}

void handle_poll_event(t_data *d, t_map_data *map)
{
    while (SDL_PollEvent(&d->e))
    {
        if (d->e.type == SDL_KEYDOWN)
        {
            if (d->e.key.keysym.scancode == SDL_SCANCODE_Z)
                draw_vertical_line(d, 500, 
                check_intersect_with_all_wall(d, map, d->rot, d->rot)
                )
                ;
        }
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

int main(void)
{
    t_map_data  map;
    t_data      d;

    init_sdl_ressources_rend(&d);
    map = read_map("maps/editor_map_0");
    init_data(&d, &map);
    ft_putstr("Main worked");

    d.player_pos = create_t_point(map.player_spawn.x, map.player_spawn.y);
    printf("player pos = %f, %f\n", d.player_pos.x, d.player_pos.y);
    while (!d.quit)
    {
        ft_bzero(d.p_screen, sizeof(int) * WIN_SIZE_X * WIN_SIZE_Y);
        SDL_PumpEvents();
        handle_key_event(&d, &map);
        handle_poll_event(&d, &map);
        //raycast_all_screen(&d, &map);
        //draw_vertical_line(&d, 500, check_intersect_with_all_wall(&d, &map, d.rot));
        update_player_pos_mini_map(&d, &map);
        print_player_look_vector(&d, &map, d.rot);
        print_data2screen(&d, &map);
    }
}