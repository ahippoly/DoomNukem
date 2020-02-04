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
    //env->stones = SDL_CreateTexture(env->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, 512, 512);
}

void init_texture(t_env *env)
{
    int i;
    t_img *tmp;

    env->selected_texture = 0;
    env->img_list[0] = ft_load_bmp("img/tech_skin_1.bmp");
    env->img_list[1] = ft_load_bmp("img/stones.bmp");
    printf("text_size : x = %i, y = %i\n", env->img_list[0].pos_size.w, env->img_list[0].pos_size.h);
    i = 0;
    while (i < NB_TEXTURE)
    {
        tmp = &env->img_list[i];
        tmp->pos_size.x = TEXT_POS_X;
        tmp->pos_size.y = TEXT_POS_Y;
        env->text_list[i++] = SDL_CreateTexture(env->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, tmp->pos_size.w, tmp->pos_size.h);
    }
}

void init_buttons(t_env *env)
{
    env->buttons_fct[0] = del_selected_wall;
    env->buttons_fct[1] = del_selected_wall;
    env->buttons_fct[2] = select_previous_texture;
    env->buttons_fct[3] = select_next_texture;
    env->buttons_fct[4] = del_selected_wall;
    env->edit = create_button(create_text_img("edit", 2, 0xFF55FFFF, create_point(850, 100)), create_text_img("edit", 2, 0xFFFFFFFF, create_point(850, 100)), BUTTON_EDIT);
    env->del = create_button(create_text_img("del", 2, 0xFF8888FF, create_point(850, 20)), create_text_img("del", 2, 0xFFFFFFFF, create_point(850, 20)), BUTTON_DEL);
    env->create_room = create_button(create_text_img("Create_room", 1, 0xFFFF88CC, create_point(795, 430)), create_text_img("Create_room", 1, 0xFFFFFFFF, create_point(795, 430)), BUTTON_CREATE_ROOM);
    env->text_select_left = create_button(create_text_img("<", 3, 0xFFDDDDDD, create_point(762, 295)), create_text_img("<", 3, 0xFF88FF88, create_point(762, 295)), BUTTON_TEXT_LEFT);
    env->text_select_right = create_button(create_text_img(">", 3, 0xFFDDDDDD, create_point(958, 295)), create_text_img(">", 3, 0xFF88FF88, create_point(958, 295)), BUTTON_TEXT_RIGHT);
}

void init_wall_ref(t_env *env)
{
    int i;
    int j;

    env->map_size.w = MAP_SIZE_X;
    env->map_size.h = MAP_SIZE_Y;
    i = 0;
    env->map_wall_ref = (t_wall_ref***)p_malloc(sizeof(t_wall_ref**) * env->map_size.h);
    while (i < env->map_size.h)
    {
        env->map_wall_ref[i] = (t_wall_ref**)p_malloc(sizeof(t_wall_ref*) * env->map_size.w);
        j = 0;
        while (j < env->map_size.w)
            env->map_wall_ref[i][j++] = NULL;
        i++;
    }
}

void init_env(t_env *env)
{
    init_sdl_ressources(env);
    init_texture(env);
    init_buttons(env);
    init_wall_ref(env);
    env->p_screen = alloc_image(WIN_SIZE_X, WIN_SIZE_Y);
    env->p_grid = alloc_image(GRID_SIZE_X, GRID_SIZE_Y);
    env->grid_pos = set_sdl_rect(GRID_POS_X, GRID_POS_Y, GRID_SIZE_X, GRID_SIZE_Y);
    env->wall_count = 0;
    env->total_wall_created = 0;
    env->selected_corner.x = -1;
    env->map_move = create_point(0, 0);
    env->map_editor = create_text_img("map_editor", 2, 0xFFDDDDDD, create_point(5, 12));
    env->text_select = create_text_img("Texture", 2, 0xFFDDDDDD, create_point(798, 200));
    env->hovered_wall_id = -1;
    env->selected_wall_id = -1;
    if (!(env->wall_list = (t_wall*)malloc(sizeof(t_wall) * NB_WALL_MAX)))
        exit_with_msg("Failed to malloc");
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
        *length = ft_max(0, max - *pos);
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

void create_grid(unsigned int *pixels, double scale, t_env *env)
{
    int i;
    int total_step;

    i = 0;
    while (i < GRID_SIZE_X)
    {
        draw_rectangle(pixels, set_sdl_rect(i + env->map_move.x % TILE_SIZE, 0, 1, GRID_SIZE_Y), set_size(GRID_SIZE_X, GRID_SIZE_Y), 0xffaabbff);
        i += TILE_SIZE;
    }
    i = 0;
    while (i < GRID_SIZE_Y)
    {
        draw_rectangle(pixels, set_sdl_rect(0, i + env->map_move.y % TILE_SIZE, GRID_SIZE_X, 1), set_size(GRID_SIZE_X, GRID_SIZE_Y), 0xffaabbff);
        i += TILE_SIZE;
    }
}

void txt_img2screen(t_env *env, t_txt_img img)
{
    SDL_UpdateTexture(env->screen, &img.pos_size, img.pixels, img.pos_size.w * 4);
}

void print_env2screen(t_env *env)
{
    SDL_Rect tmp;
    // SDL_UpdateTexture(env->screen, NULL, env->p_screen, WIN_SIZE_X * 4);
    // SDL_RenderCopy(env->rend, env->screen, NULL, NULL);
    // SDL_UpdateTexture(env->editor_grid, NULL, env->p_grid, GRID_SIZE_X * 4);
    // SDL_RenderCopy(env->rend, env->editor_grid, NULL, &env->grid_pos);
    // SDL_RenderPresent(env->rend);

    SDL_UpdateTexture(env->screen, NULL, env->p_screen, WIN_SIZE_X * 4);
    SDL_UpdateTexture(env->screen, &env->grid_pos, env->p_grid, GRID_SIZE_X * 4);
    txt_img2screen(env, *env->edit.printed);
    txt_img2screen(env, *env->del.printed);
    txt_img2screen(env, env->map_editor);
    txt_img2screen(env, *env->text_select_left.printed);
    txt_img2screen(env, *env->text_select_right.printed);
    txt_img2screen(env, *env->create_room.printed);
    txt_img2screen(env, env->text_select);
    SDL_RenderCopy(env->rend, env->screen, NULL, NULL);
    SDL_UpdateTexture(env->text_list[env->selected_texture], NULL, env->img_list[env->selected_texture].pixels, env->img_list[0].pos_size.w * 4);
    tmp = set_sdl_rect(TEXT_POS_X, TEXT_POS_Y, TEXT_SIZE_X, TEXT_SIZE_Y);
    SDL_RenderCopy(env->rend, env->text_list[env->selected_texture], NULL, &tmp);
    SDL_RenderPresent(env->rend);
}

SDL_Point check_tiles_hitbox(SDL_Point mouse, unsigned int *pixels, t_env *env)
{
    SDL_Point   rest;
    SDL_Point   adapted_point;
    SDL_Rect    box_pos;
    SDL_Point   map_pos;

    map_pos.x = -1;
    map_pos.y = -1;
    if (mouse.x < GRID_POS_X || mouse.x > GRID_POS_X + GRID_SIZE_X
        || mouse.y < GRID_POS_Y || mouse.y > GRID_POS_Y+ GRID_SIZE_Y)
        return (map_pos);
    adapted_point.x = (mouse.x + TILE_HITBOX - GRID_POS_X - env->map_move.x);
    adapted_point.y = (mouse.y + TILE_HITBOX - GRID_POS_Y - env->map_move.y);
    rest.x = adapted_point.x % TILE_SIZE;
    rest.y = adapted_point.y % TILE_SIZE;
    if (rest.x <= TILE_HITBOX * 2 && rest.y <= TILE_HITBOX * 2)
    {
        map_pos.x = adapted_point.x / TILE_SIZE;
        map_pos.y = adapted_point.y / TILE_SIZE;
        box_pos.x = map_pos.x * TILE_SIZE - TILE_HITBOX + env->map_move.x;
        box_pos.y = map_pos.y * TILE_SIZE - TILE_HITBOX + env->map_move.y;
        draw_rectangle(pixels, set_sdl_rect(box_pos.x, box_pos.y, TILE_HITBOX * 2, TILE_HITBOX * 2), set_size(GRID_SIZE_X, GRID_SIZE_Y), 0x0000ff00);
    }
    return (map_pos);
}

void reset_textures(t_env *env)
{
    ft_bzero(env->p_screen, WIN_SIZE_X * WIN_SIZE_Y * 4);
    ft_bzero(env->p_grid, GRID_SIZE_X * GRID_SIZE_Y * 4);
}

void check_click(t_env *env)
{
    if (env->ev.type == SDL_MOUSEBUTTONUP && env->ev.button.button == SDL_BUTTON_LEFT)
    {
        if (env->selected_button != -1)
            env->buttons_fct[env->selected_button](env);
        if (env->hovered_corner.x != -1)
        {
            if (env->selected_corner.x == -1)
                env->selected_corner = env->hovered_corner;
            else if (env->selected_corner.x != env->hovered_corner.x
                || env->selected_corner.y != env->hovered_corner.y)
            {
                add_wall(env->selected_corner, env->hovered_corner, env);
                env->selected_corner.x = -1;
            }
        }
        else
            env->selected_corner.x = -1;
        if (env->hovered_wall_id != -1)
            env->selected_wall_id = env->hovered_wall_id;
        else
            env->selected_wall_id = -1;
        printf("selected wall = %i\n", env->selected_wall_id);
    }
}

void display_selected_point(t_env *env)
{
    int hitbox;

    if (env->selected_corner.x != -1)
    {
        hitbox = TILE_HITBOX - 2;
        draw_rectangle(env->p_grid,
            set_sdl_rect(env->selected_corner.x * TILE_SIZE - hitbox / 2 + env->map_move.x, env->selected_corner.y * TILE_SIZE - hitbox / 2 + env->map_move.y, hitbox, hitbox),
            set_size(GRID_SIZE_X, GRID_SIZE_Y),
            0xFF0000FF);
    }
}

void handle_mouse_event(t_env *env)
{
    while (SDL_PollEvent(&env->ev))
    {
        check_click(env);
    }
}



void handle_keyboard_event(t_env *env)
{
    if(env->clavier[SDL_SCANCODE_ESCAPE] || env->clavier[SDL_SCANCODE_RETURN])
        env->quit = 1;
    if(env->clavier[SDL_SCANCODE_D])
        move_map_move_right(env);
    if(env->clavier[SDL_SCANCODE_A])
        move_map_move_left(env);
    if(env->clavier[SDL_SCANCODE_W])
        move_map_move_up(env);
    if(env->clavier[SDL_SCANCODE_S])
        move_map_move_down(env);
    if(env->clavier[SDL_SCANCODE_Q])
        print_wall_ref(env);
}

int main(int argc, char **argv)
{
    t_env       env;
    
    init_env(&env);
    while(!env.quit)
    {
        reset_textures(&env);
        
        
        env.clavier = SDL_GetKeyboardState(NULL);
        env.mouse_button = SDL_GetMouseState(&env.mouse.x, &env.mouse.y);
        handle_keyboard_event(&env);
        env.hovered_corner = check_tiles_hitbox(env.mouse, env.p_grid, &env);
        create_grid(env.p_grid, 1, &env);
        check_hovered_buttons(&env);
        handle_mouse_event(&env);
        print_walls_in_map(&env);
        check_mouse_in_walls(&env);
        print_selected_wall(&env);
        display_selected_point(&env);

        
        print_env2screen(&env);
    }
}