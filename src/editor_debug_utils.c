#include "proto_global.h"
#include "proto_global.h"


void print_rooms_content(t_room *room_list, int room_count)
{
    int     i;
    t_room room;

    //rearange_wall_lst(env);
    printf("ROOM_CONTENTS :\n");
    i = 0;
    while (i < room_count)
    {
        room = room_list[i];
        printf("room id %i have wall id from %i to %i\n", room.room_id, room.wall_ref.start, room.wall_ref.end);
        i++;
    }
}

void debug_print(t_env *env, SDL_Scancode key)
{
    if (key == SDL_SCANCODE_Q)
        print_wall_ref(env->map_wall_ref, env->map_size, 1);
    if (key == SDL_SCANCODE_E)
        print_rooms_content(env->room_list, env->room_count);
    if (key == SDL_SCANCODE_Z)
        read_map("maps/editor_map_0");
}

void print_wall_content(t_wall wall)
{
    // printf("id = %3d ; p1 = %3d,%3d ; p2 = %3d,%3d ; p1_height = %3d,%3d ; p2_height = %3d,%3d ; texture_id = %3d, room_id = %3d, transparency = %3d\n",
    // wall.id, wall.p1.x, wall.p1.y, wall.p2.x, wall.p2.y, wall.p1_height.start, wall.p1_height.end, wall.p2_height.start, wall.p2_height.end,
    // wall.texture_id, wall.room_id_ref, wall.transparency);
}

void print_wall_list(t_map_data *map)
{
    int i;

    i = 0;
    while (i < map->wall_count)
        print_wall_content(map->wall_list[i++]);
}