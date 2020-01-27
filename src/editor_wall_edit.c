#include "editor.h"
#include "global_header.h"

double calc_coef_dir(SDL_Point p1, SDL_Point p2)
{
    int delta_x;
    int delta_y;

    delta_x = p2.x - p1.x;
    delta_y = p2.y - p1.y;
    return ((double)delta_y / delta_x);
}

int is_cursor_in_wall(SDL_Point cursor, SDL_Point p1, SDL_Point p2)
{
    double wall_pos_ratio;
    int wall_pos_y;
    int delta_y;

    p1 = mult_sdl_point(p1, TILE_SIZE);
    p2 = mult_sdl_point(p2, TILE_SIZE);
    if (p1.x == p2.x)
    {
        if (p2.y < p1.y)
            swap_point(&p1, &p2);
        if (cursor.y < p2.y && cursor.y > p1.y && cursor.x > p1.x - WALL_HITBOX && cursor.x < p1.x + WALL_HITBOX)
            return(1);
        return(0);
    }
    if (p2.x < p1.x)
        swap_point(&p1, &p2);
    wall_pos_ratio = (double)(cursor.x - p1.x) / (p2.x - p1.x);
    delta_y = p2.y - p1.y;
    if (wall_pos_ratio < 0 || wall_pos_ratio > 1)
        return (0);
    wall_pos_y = p1.y + wall_pos_ratio * delta_y;
    if (cursor.y < wall_pos_y + WALL_HITBOX && cursor.y > wall_pos_y - WALL_HITBOX)
        return (1);
    return (0);
}

void check_mouse_in_walls(t_env *env)
{
    int i;
    t_wall wall;

    i = 0;
    env->hovered_wall_id = -1;
    while (i < env->wall_count)
    {
        wall = env->wall_list[i];
        if (is_cursor_in_wall(env->mouse, wall.p1, wall.p2))
        {
            env->hovered_wall_id = wall.id;
            octant(mult_sdl_point(wall.p1, TILE_SIZE), mult_sdl_point(wall.p2, TILE_SIZE), env->p_grid, 0xFF0000FF, GRID_SIZE_X);
        }
        i++;
    }
}