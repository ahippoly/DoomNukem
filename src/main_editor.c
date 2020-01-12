#include "global_header.h"
#include "editor.h"



void init_sdl_ressources(t_env *env)
{
    env->win = NULL;
    if(0 != SDL_Init(SDL_INIT_VIDEO))
        exit_with_msg("Failed to Init SDL");
    if (!(env->win = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              WIN_SIZE_X, WIN_SIZE_Y, SDL_WINDOW_SHOWN)))
        exit_with_msg("Failed to create Window");
    if (!(env->rend = SDL_CreateRenderer(env->win, -1, SDL_RENDERER_ACCELERATED)))
        exit_with_msg("Failed to create Renderer");
    env->screen = SDL_CreateTexture(env->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, WIN_SIZE_X, WIN_SIZE_Y);
    env->editor_grid = SDL_CreateTexture(env->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, GRID_SIZE_X, GRID_SIZE_Y);
}

void init_env(t_env *env)
{
    init_sdl_ressources(env);
    env->p_screen = alloc_image(WIN_SIZE_X, WIN_SIZE_Y);
    env->p_grid = alloc_image(GRID_SIZE_X, GRID_SIZE_Y);
    env->grid_pos = set_sdl_rect(0, 0, GRID_SIZE_X, GRID_SIZE_Y);
    env->quit = 0;
}

SDL_Rect set_sdl_rect(int x, int y, int w, int h)
{
    SDL_Rect rect;

    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    return (rect);
}

t_size set_size(int w, int h)
{
    t_size size;

    size.w = w;
    size.h = h;
    return (size);
}

void adapt_min(int *pos, int *length)
{
    if (*pos < 0)
    {
        *length += *pos;
        *pos = 0;
    }
}

void adapt_max(int *pos, int *length, int max)
{
    if (*pos + *length > max)
        *length = ft_min(0, max - *pos);
}

SDL_Rect adapt_border(SDL_Rect pos_size, t_size max)
{
    adapt_min(&pos_size.x, &pos_size.w);
    adapt_min(&pos_size.y, &pos_size.h);
    adapt_max(&pos_size.x, &pos_size.w, max.w);
    adapt_max(&pos_size.y, &pos_size.h, max.h);
    return (pos_size);
}

void draw_rectangle(unsigned int *pixels, SDL_Rect rect, t_size screen_size, int color)
{
    int x;
    int y;
    SDL_Point end;

    rect = adapt_border(rect, screen_size);
    end.x = rect.x + rect.w;
    end.y = rect.y + rect.h;
    y = rect.y;
    while (y < end.y)
    {
        x = rect.x;
        while (x < end.x)
            pixels[x++ + y * screen_size.w] = color;
        y++;
    }
}

void create_straight_line(unsigned int *pixels, SDL_Rect pos_size, t_size screen_length, int color)
{
    int i;
    int end;

    pos_size = adapt_border(pos_size, screen_length);
    i = pos_size.x;
    end = pos_size.x + pos_size.w;
    while (i < end)
    {
        pixels[i + pos_size.y * screen_length.w] = color;
        i++;
    }
}

void create_straight_column(unsigned int *pixels, SDL_Rect pos_size, t_size screen_length, int color)
{
    int i;
    int end;

    pos_size = adapt_border(pos_size, screen_length);
    i = pos_size.y;
    end = pos_size.x + pos_size.w;
    while (i < end)
    {
        pixels[pos_size.x + i * screen_length.w] = color;
    }
}

void create_grid(unsigned int *pixels, double scale)
{
    int i;
    int total_step;

    i = 0;
    while (i < GRID_SIZE_X)
    {
        draw_rectangle(pixels, set_sdl_rect(i, 0, 1, GRID_SIZE_Y), set_size(GRID_SIZE_X, GRID_SIZE_Y), 0xffaabbff);
        i += TILE_SIZE;
    }
    i = 0;
    while (i < GRID_SIZE_Y)
    {
        draw_rectangle(pixels, set_sdl_rect(0, i, GRID_SIZE_X, 1), set_size(GRID_SIZE_X, GRID_SIZE_Y), 0xffaabbff);
        i += TILE_SIZE;
    }
}

void print_env2screen(t_env *env)
{
    SDL_UpdateTexture(env->screen, NULL, env->p_screen, WIN_SIZE_X * 4);
    SDL_RenderCopy(env->rend, env->screen, NULL, NULL);
    SDL_UpdateTexture(env->editor_grid, NULL, env->p_grid, GRID_SIZE_X * 4);
    SDL_RenderCopy(env->rend, env->editor_grid, NULL, &env->grid_pos);
    SDL_RenderPresent(env->rend);
}

SDL_Point check_tiles_hitbox(SDL_Point mouse, unsigned int *pixels)
{
    SDL_Point   rest;
    SDL_Point   adapted_point;
    SDL_Rect    box_pos;
    SDL_Point   map_pos

    adapted_point.x = (mouse.x + TILE_HITBOX);
    adapted_point.y = (mouse.y + TILE_HITBOX);
    rest.x = adapted_point.x % TILE_SIZE;
    rest.y = adapted_point.y % TILE_SIZE;
    map_pos.x = -1;
    map_pos.y = -1;
    if (rest.x <= TILE_HITBOX * 2 && rest.y <= TILE_HITBOX * 2)
    {
        map_pos.x = adapted_point.x / TILE_SIZE;
        map_pos.y = adapted_point.y / TILE_SIZE;
        box_pos.x = map_pos.x * TILE_SIZE - TILE_HITBOX;
        box_pos.y = map_pos.y * TILE_SIZE - TILE_HITBOX;
        draw_rectangle(pixels, set_sdl_rect(box_pos.x, box_pos.y, TILE_HITBOX * 2, TILE_HITBOX * 2), set_size(GRID_SIZE_X, GRID_SIZE_Y), 0x0000ff00);
    }
    return (map_pos);
}

void reset_textures(t_env *env)
{
    ft_bzero(env->p_screen, WIN_SIZE_X * WIN_SIZE_Y * 4);
    ft_bzero(env->p_grid, GRID_SIZE_X * GRID_SIZE_Y * 4);
}

int main(int argc, char **argv)
{
    t_env       env;
    Uint8       *clavier;
    SDL_Point   mouse;
    init_env(&env);
    


    
    while(!env.quit)
    {
        reset_textures(&env);
        create_grid(env.p_grid, 1);
        SDL_PumpEvents();
        clavier = SDL_GetKeyboardState(NULL);
        SDL_GetMouseState(&mouse.x, &mouse.y);
        if(clavier[SDL_SCANCODE_ESCAPE] || clavier[SDL_SCANCODE_RETURN])
            env.quit = 1;
        check_tiles_hitbox(mouse, env.p_grid);
        
        print_env2screen(&env);
    }
}