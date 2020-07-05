#include "proto_global.h"

//OKK
static void rearange_room_id(t_env *env)
{
    t_wall wall;
    int new_nb_room;
    int i;

    i = 0;
    new_nb_room = 0;
    while (i < env->wall_count)
    {
        wall = env->wall_list[i];
        if (wall.room_id_ref != -1)
        {
            while (env->wall_list[i].room_id_ref == wall.room_id_ref && i < env->wall_count)
            {
                env->wall_list[i].room_id_ref = new_nb_room;
                i++;
            }
            i--;
            new_nb_room++;
        }
        i++;
    }
}

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
            inter = find_intersect(wall.p1, wall.p2, checked_wall.p1, checked_wall.p2);
            printf("Intersect between wall nb %i and %i is x=%f, y=%f\n",wall.id, checked_wall.id, inter.x, inter.y);
            i++;
        }
    }
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
                draw_line(add_sdl_point(convert_t_point(mult_t_point(wall.p1, TILE_SIZE)), env->map_move, 0), add_sdl_point(convert_t_point(mult_t_point(wall.p2, TILE_SIZE)), (env->map_move), 0), (t_img){env->p_grid, (SDL_Rect){0, 0, GRID_SIZE_X, GRID_SIZE_Y}}, 0xFF00FFFF);
            else
                draw_line(add_sdl_point(convert_t_point(mult_t_point(wall.p1, TILE_SIZE)), env->map_move, 0), add_sdl_point(convert_t_point(mult_t_point(wall.p2, TILE_SIZE)), (env->map_move), 0), (t_img){env->p_grid, (SDL_Rect){0, 0, GRID_SIZE_X, GRID_SIZE_Y}}, 0xFFFF88CC);                
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
        draw_line(add_sdl_point(convert_t_point(mult_t_point(wall.p1, TILE_SIZE)), env->map_move, 0), add_sdl_point(convert_t_point(mult_t_point(wall.p2, TILE_SIZE)), env->map_move, 0), (t_img){env->p_grid, (SDL_Rect){0, 0, GRID_SIZE_X, GRID_SIZE_Y}}, 0xFF00FF00);
    }
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
            new_lst[new_wall_nb] = env->wall_list[i];
            new_lst[new_wall_nb].id = new_wall_nb;
            new_wall_nb++;
        }
        i++;
    }
    free(env->wall_list);
    env->wall_list = new_lst;
    env->wall_count = new_wall_nb;
    rearange_room_id(env);
    recreate_room_list(env);
}