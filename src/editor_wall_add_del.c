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

    wall.id = env->total_wall_created++;
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
        env->wall_list[env->wall_count++] = create_wall(p1,p2, env);
    }
    else
    {
        rearange_wall_lst(env);
        if (env->wall_count < NB_WALL_MAX)
            env->wall_list[env->wall_count++] = create_wall(p1,p2, env);
    }
    return (success);
}

void print_walls_in_map(t_env *env)
{
    int i;

    i = 0;
    while (i < env->wall_count)
    {
        octant(mult_sdl_point(env->wall_list[i].p1, TILE_SIZE), mult_sdl_point(env->wall_list[i].p2, TILE_SIZE), env->p_grid, 0xFF00FFFF, GRID_SIZE_X);
        i++;
    }


    
}