#include "global_header.h"
#include "editor.h"


void rearange_wall_lst(t_env *env)
{
    t_wall *new_lst;
    int i;
    int new_wall_nb;

    if (!(new_lst = (t_wall*)malloc(sizeof(t_wall) * NB_WALL_MAX)))
        exit_with_msg("Failed to malloc");
    i = 0;
    new_wall_nb = 0;
    while (i < env->wall_count)
    {
        if (env->wall_list[i].id != -1)
        {
            new_lst[new_wall_nb] = env->wall_list[i];
            new_lst[new_wall_nb].id = new_wall_nb;
            new_wall_nb++;
        }
        i++;
    }
    free(env->wall_list);
    env->wall_list = new_lst;
    env->wall_count = new_wall_nb;
}

t_wall create_wall(SDL_Point p1, SDL_Point p2, t_env *env)
{
    t_wall wall;

    wall.id = env->wall_count;
    wall.p1 = p1;
    wall.p2 = p2;
    return(wall);
}

int add_wall(SDL_Point p1, SDL_Point p2, t_env *env)
{
    int success;

    success = 0;
    if (env->wall_count < NB_WALL_MAX)
    {
        success = 1;
        env->wall_list[env->wall_count] = create_wall(p1,p2, env);
        env->wall_count++;
    }
    else
    {
        rearange_wall_lst(env);
        if (env->wall_count < NB_WALL_MAX)
            env->wall_list[env->wall_count++] = create_wall(p1,p2, env);
    }
    return (success);
}

void del_wall(t_env *env, int wall_id)
{
    t_wall *wall;

    wall = &env->wall_list[wall_id];
    printf("wall_id %i\n", wall->id);
    wall->id = -1;
    wall->p1.x = -1;
    wall->p1.y = -1;
    wall->p2.x = -1;
    wall->p2.y = -1;
}

void print_walls_in_map(t_env *env)
{
    int i;
    t_wall wall;

    i = 0;
    while (i < env->wall_count)
    {
        wall = env->wall_list[i];
        if (wall.id != -1)
            octant(mult_sdl_point(wall.p1, TILE_SIZE), mult_sdl_point(wall.p2, TILE_SIZE), env->p_grid, 0xFF00FFFF, GRID_SIZE_X);
        i++;
    }
}

void print_selected_wall(t_env *env)
{
    t_wall wall;

    wall = env->wall_list[env->selected_wall_id];
    if (wall.id != -1)
        octant(mult_sdl_point(wall.p1, TILE_SIZE), mult_sdl_point(wall.p2, TILE_SIZE), env->p_grid, 0xFF00FF00, GRID_SIZE_X);
}