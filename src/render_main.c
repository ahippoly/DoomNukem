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

void init_data(t_data *d, t_map_data *map)
{
    init_mini_map(d, map);
    d->rot = 1;
    d->screen_height = 0;
    d->player_height = 0.5;
    d->quit = 0;
  //  d->p_screen = (unsigned int *)p_malloc(sizeof(int) * MAP_SIZE_X * MAP_SIZE_Y);
    d->p_screen = alloc_image(WIN_SIZE_X, WIN_SIZE_Y);
    d->texture = read_img_surface("img/textures/stones.bmp");
    ft_bzero(d->p_screen, sizeof(int) * MAP_SIZE_Y * MAP_SIZE_X);
}

double calc_wall_hit_scale(t_wall wall, t_point inter)
{
    int     x_min;
    int     x_max;
    double  inter_diff_x;
    double  tmp;

    sort_point_by_x(&wall.p1, &wall.p2);
    return (modf((inter.x - wall.p1.x) / (wall.p2.x - wall.p1.x) * wall.length, &tmp));
}

t_dist_n_scale check_inter_with_wall(t_wall wall, double rot, t_point pos, double look_rot)
{
    t_point inter;
    t_dist_n_scale res;

    res.dist = 9999;
    res.scale = 0;
    inter = inter_with_dir(pos, rot, create_t_point(wall.p1.x, wall.p1.y), create_t_point(wall.p2.x, wall.p2.y));
    if (inter.x != -42)
    {
        res.dist = ft_frange(cos(look_rot * M_PI_2) * (inter.x - pos.x) + sin(look_rot * M_PI_2) * (inter.y - pos.y), 0, res.dist);
        res.scale = calc_wall_hit_scale(wall, inter);
    }
        //dist = hypot(inter.x - pos.x, inter.y - pos.y) * cos((look_rot - rot )* M_PI_2);
    //printf("wall x min = %i, x max = %i, touch x = %f, scale = %f\n", wall.p1.x, wall.p2.x, inter.x, calc_wall_hit_scale(wall, inter));
    return (res);
}

t_dist_n_scale check_intersect_with_all_wall(t_data *d, t_map_data *map, double rot, double look_rot)
{
    int i;
    t_dist_n_scale res ;
    t_dist_n_scale tmp;
    t_point inter;
    t_wall wall;

    i = 0;
    res.dist = 9999;
    while (i < map->wall_count)
    {
        wall = map->wall_list[i];
        tmp = check_inter_with_wall(wall, rot, d->player_pos, look_rot);
        res = tmp.dist < res.dist ? tmp : res ;
        //ft_fmin(dist, check_inter_with_wall(wall, rot, d->player_pos, look_rot));
        i++;
    }
    //printf("dist of closest wall : %f\n", res.dist);
    return (res);
}

void draw_vertical_line(t_data *d, int x, t_dist_n_scale dist_scale, SDL_Surface *text)
{
    int draw_begin;
    int draw_end;
    double y_scale;
    double y_step;
    int text_pixel_color;
    int *pixels;
    void (*pixel_put)();

    if (dist_scale.dist == 9999)
        return ;
    draw_begin = d->screen_height + HALF_WIN_SIZE_Y - ((1 - d->player_height) * WIN_SIZE_Y) / dist_scale.dist;
    draw_end = d->screen_height + (HALF_WIN_SIZE_Y + (d->player_height * WIN_SIZE_Y) / dist_scale.dist);
    y_scale = 0;
    y_step = (double)1 / (draw_end - draw_begin);
    y_scale += y_step * ft_max(- draw_begin, 0);
    draw_begin = ft_max(draw_begin, 0);
    draw_end = ft_min(draw_end, WIN_SIZE_Y);
    pixels = (int*)text->pixels;
    if (dist_scale.dist < d->nearest_dist)
    {
        pixel_put = put_pixel;
        d->nearest_dist = dist_scale.dist;
    }
    else
        pixel_put = put_pixel_attempt;
    while (draw_begin < draw_end)
    {
        y_scale += y_step;
        //printf("text w = %i, h = %i, pitch = %i, scale : x = %f, y = %f\n", text->w, text->h, text->pitch, dist_scale.scale, y_scale);
        text_pixel_color = pixels[(int)(dist_scale.scale * text->w) + (int)(y_scale * text->h) * text->w];
        //printf("colour = %i\n", text_pixel_color);
        pixel_put(d->p_screen, create_point(x, draw_begin++), create_t_size(WIN_SIZE_X, WIN_SIZE_Y), text_pixel_color);
    }
}

void attempt_to_draw_with_wall_wall(t_data *d, t_map_data *map)
{
    
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
        d->nearest_dist = 9999;
        while (i < map->wall_count)
            draw_vertical_line(d, x, check_inter_with_wall(map->wall_list[i++], current_angle, d->player_pos, d->rot), d->texture);
        //draw_vertical_line(d, x, check_intersect_with_all_wall(d, map, current_angle, d->rot), d->texture);
        current_angle += step;
        x++;
    }
}

void move_attempt(t_point *pos, double inc_x, double inc_y, double look_rot)
{
    double cos_rot;
    double sin_rot;

    cos_rot = cos(look_rot * M_PI_2);
    sin_rot = sin(look_rot * M_PI_2);
    pos->y += - inc_y * sin_rot - inc_x * cos_rot;
    pos->x += - inc_y * cos_rot + inc_x * sin_rot;
}

void handle_key_event(t_data *d, t_map_data *map)
{
    d->clavier = SDL_GetKeyboardState(NULL);
    if (d->clavier[SDL_SCANCODE_E])
        d->rot += ROT_STEP;
    if (d->clavier[SDL_SCANCODE_Q])
        d->rot -= ROT_STEP;
    if (d->clavier[SDL_SCANCODE_D])
        move_attempt(&d->player_pos, - MOVE_STEP, 0, d->rot);
    if (d->clavier[SDL_SCANCODE_A])
        move_attempt(&d->player_pos, MOVE_STEP, 0, d->rot);
    if (d->clavier[SDL_SCANCODE_W])
        move_attempt(&d->player_pos, 0, - MOVE_STEP, d->rot);
    if (d->clavier[SDL_SCANCODE_S])
        move_attempt(&d->player_pos, 0, MOVE_STEP, d->rot);
    if (d->clavier[SDL_SCANCODE_SPACE])
        d->player_height += HEIGHT_STEP;
    if (d->clavier[SDL_SCANCODE_LCTRL])
        d->player_height -= HEIGHT_STEP;
    if (d->clavier[SDL_SCANCODE_R])
        d->screen_height += SCREEN_HEIGHT_STEP;
    if (d->clavier[SDL_SCANCODE_F])
        d->screen_height -= SCREEN_HEIGHT_STEP;
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
                check_intersect_with_all_wall(d, map, d->rot, d->rot),
                d->texture
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
        raycast_all_screen(&d, &map);
        //draw_vertical_line(&d, 500, check_intersect_with_all_wall(&d, &map, d.rot));
        update_player_pos_mini_map(&d, &map);
        print_player_look_vector(&d, &map, d.rot);
        print_data2screen(&d, &map);
    }
}