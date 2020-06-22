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
    d->screen = SDL_CreateTexture(d->rend, SDL_PIXELFORMAT_ARGB32, SDL_TEXTUREACCESS_STREAMING, WIN_SIZE_X, WIN_SIZE_Y);
    d->mini_map = SDL_CreateTexture(d->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y);
    //SDL_SetRelativeMouseMode(SDL_TRUE);
    //SDL_SetTextureBlendMode(d->screen, SDL_BLENDMODE_BLEND);
    //SDL_SetRenderDrawBlendMode(d->rend, SDL_BLENDMODE_NONE);
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

void init_props(t_data *d)
{
	d->props[0].pos = (t_point){5,5};
	d->props[0].size = 0.2;
	d->props[0].z_pos = 2.2;
	d->props[0].text = d->texture[1];
	d->nb_props = 1;
}



void init_data(t_data *d, int ac, char **av)
{
    init_sdl_ressources_rend(d);
	if (ac > 1)
		d->map = read_map(av[1]);
	else
    	d->map = read_map("maps/editor_map_0");
	if (d->map.is_valid == 0)
		exit_with_msg("error : wrong map file\n");
    init_mini_map(d, &d->map);
    load_bmp_files(d);
    d->player_pos = create_t_point(d->map.player_spawn.x, d->map.player_spawn.y);
    d->rot = -1 * M_PI_2;
    d->screen_height = HALF_WIN_SIZE_Y;
    d->player_height = 0;
    d->z_force = 0;
    d->air_time = 0;
    d->z_ground = 2;
    d->z_pos = 10;
    d->z_offset = PLAYER_HEIGHT;
    d->speed_modifier = 1;
    d->framerate = 0;
    d->time = 0;
    d->quit = 0;
	d->grabbed_wall = NULL;
	d->fov = (float)FOV_ANGLE / 90;
	d->fov_rad = ((float)FOV_ANGLE * M_PI_2) / 90;
    d->p_screen = alloc_image(WIN_SIZE_X, WIN_SIZE_Y);
    ft_bzero(d->p_screen, sizeof(int) * MAP_SIZE_Y * MAP_SIZE_X);
	init_rend_img(d);
	init_props(d);
	init_obj_list(d);
  //  d->p_screen = (unsigned int *)p_malloc(sizeof(int) * MAP_SIZE_X * MAP_SIZE_Y);
}
