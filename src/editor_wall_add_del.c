#include "global_header.h"
#include "editor.h"

void check_intersect_with_all_wall(t_wall wall,t_env *env)
{
    int i;
    t_wall checked_wall;
    t_point inter;

    i = 0;
    while (i < env->wall_count)
    {
        checked_wall = env->wall_list[i];
        if (i != wall.id && checked_wall.id != -1)
        {
            inter = segment_intersect(wall.p1, wall.p2, checked_wall.p1, checked_wall.p2);
            printf("Intersect between wall nb %i and %i is x=%f, y=%f\n",wall.id, checked_wall.id, inter.x, inter.y);
            i++;
        }
    }
}

int check_intersect_with_all_wall_point(SDL_Point p1, SDL_Point p2, t_env *env)
{
    int i;
    t_wall checked_wall;
    t_point inter;
    //int found;

    i = 0;
    while (i < env->wall_count)
    {
        checked_wall = env->wall_list[i];
        if (checked_wall.id != -1)
        {
            inter = segment_intersect(p1, p2, checked_wall.p1, checked_wall.p2);
            printf("Intersect between wall created and wall nb %i is x=%f, y=%f\n", checked_wall.id, inter.x, inter.y);
            if (inter.x != -42)
                return (1);
        }
        i++;
    }
    return (0);
}

t_wall create_wall(SDL_Point p1, SDL_Point p2, int id, t_env *env)
{
    t_wall wall;

    wall.id = id;
    wall.p1 = p1;
    wall.p2 = p2;
    wall.texture_id = env->selected_texture;
    wall.transparency = env->actual_transparency;
    wall.p1_height = env->p1_height;
    wall.p2_height = env->p2_height;
    if (env->selected_mouse_mode == MOUSE_MODE_CREATE_ROOM)
        wall.room_id_ref = env->room_count;
    else
        wall.room_id_ref = -1;
    
    add_wall_ref_point(wall, env);
    //check_intersect_with_all_wall(wall, env);
    return(wall);
}

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
            new_lst[new_wall_nb] = create_wall(env->wall_list[i].p1, env->wall_list[i].p2, new_wall_nb, env);
            new_wall_nb++;
        }
        i++;
    }
    free(env->wall_list);
    env->wall_list = new_lst;
    env->wall_count = new_wall_nb;
}

int add_wall(SDL_Point p1, SDL_Point p2, t_env *env)
{
    int success;

    success = 0;
    if (check_intersect_with_all_wall_point(p1, p2, env))
        return (0);
    if (env->wall_count < NB_WALL_MAX)
    {
        success = 1;
        env->wall_list[env->wall_count] = create_wall(p1, p2, env->wall_count, env);
        env->wall_count++;
    }
    else
    {
        rearange_wall_lst(env);
        if (env->wall_count < NB_WALL_MAX)
        {
            env->wall_list[env->wall_count++] = create_wall(p1, p2, env->wall_count, env);
            success = 1;
        }
    }
    return (success);
}

void del_wall(t_env *env, int wall_id)
{
    t_wall *wall;

    if (wall_id >= 0)
    {
        wall = &env->wall_list[wall_id];
        printf("wall_id %i\n", wall->id);
        wall->id = -1;
        wall->p1.x = -1;
        wall->p1.y = -1;
        wall->p2.x = -1;
        wall->p2.y = -1;
        if (wall->room_id_ref != -1)
            del_room(env, wall->room_id_ref);
    }
}

void del_room(t_env *env, int room_id)
{
    t_room *previous;
    t_room *to_remove;
    int i;

    previous = env->room_list;
    if (previous->room_id == room_id)
    {
        to_remove = previous;
        env->room_list = env->room_list->next;
    }
    else
    {   
        while (previous->next && previous->next->room_id != room_id)
            previous = previous->next;
        to_remove = previous->next;
        previous->next = to_remove->next;
    }
    i = 0;
    while (i < to_remove->nb_wall)
    {
        env->wall_list[to_remove->wall_ref[i]].room_id_ref = -1;
        del_wall(env, to_remove->wall_ref[i++]);
    }
    free(to_remove->wall_ref);
    free(to_remove);
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
        {
            if (wall.room_id_ref == -1)
                octant(add_sdl_point(mult_sdl_point(wall.p1, TILE_SIZE), env->map_move, 0), add_sdl_point(mult_sdl_point(wall.p2, TILE_SIZE), env->map_move, 0), env->p_grid, 0xFF00FFFF, set_sdl_rect(0, 0, GRID_SIZE_X, GRID_SIZE_Y));
            else
                octant(add_sdl_point(mult_sdl_point(wall.p1, TILE_SIZE), env->map_move, 0), add_sdl_point(mult_sdl_point(wall.p2, TILE_SIZE), env->map_move, 0), env->p_grid, 0xFFFF88CC, set_sdl_rect(0, 0, GRID_SIZE_X, GRID_SIZE_Y));                
        }
        i++;
    }
}

void print_selected_wall(t_env *env)
{
    t_wall wall;

    if (env->selected_wall_id != -1)
    {
        wall = env->wall_list[env->selected_wall_id];
        octant(add_sdl_point(mult_sdl_point(wall.p1, TILE_SIZE), env->map_move, 0), add_sdl_point(mult_sdl_point(wall.p2, TILE_SIZE), env->map_move, 0), env->p_grid, 0xFF00FF00, set_sdl_rect(0, 0, GRID_SIZE_X, GRID_SIZE_Y));
    }
}