#include "proto_global.h"

// OKK
static int check_intersect_with_all_wall_point(t_point p1, t_point p2, t_env *env)
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
            inter = find_intersect(p1, p2, checked_wall.p1, checked_wall.p2);
            printf("Intersect between wall created and wall nb %i is x=%f, y=%f\n", checked_wall.id, inter.x, inter.y);
            if (inter.x != -42)
                return (1);
        }
        i++;
    }
    return (0);
}

static t_wall create_wall(t_point p1, t_point p2, int id, t_env *env)
{
    t_wall wall;

    wall.id = id;
    wall.p1 = (p1);
    wall.p2 = (p2);
    wall.texture_id = env->selected_texture;
    wall.transparency = env->input_lst[INPUT_TRANSPARENCY].value;
    wall.can_collide = env->input_lst[INPUT_COLLIDE].value;
    wall.p1_height.start = env->input_lst[INPUT_BEGIN_P1].value;
    wall.p2_height.start = env->input_lst[INPUT_BEGIN_P2].value;
    wall.p1_height.end = env->input_lst[INPUT_END_P1].value;
    wall.p2_height.end = env->input_lst[INPUT_END_P2].value;
    if (env->selected_mouse_mode == MOUSE_MODE_CREATE_ROOM)
        wall.room_id_ref = env->room_count;
    else
        wall.room_id_ref = -1;
    
    //add_wall_ref_point(wall, env);
    //check_intersect_with_all_wall(wall, env);
    return (wall);
}

int add_wall(t_point p1, t_point p2, t_env *env)
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

static void del_room(t_env *env, int room_id)
{
    int i;
    t_wall wall;

    i = 0;
    while (i < env->wall_count)
    {
        if (env->wall_list[i].room_id_ref == room_id)
        {
            env->wall_list[i].room_id_ref = -1;
            del_wall(env, i);
        }
        i++;
    }
	env->room_height[room_id].start = -42;
	env->room_text[room_id] = -42;
    env->room_count--;
}

void del_wall(t_env *env, int wall_id)
{
    t_wall  *wall;

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