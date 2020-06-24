#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"


float calc_wall_hit_scale(t_wall wall, t_point inter)
{
    sort_t_point_by_x(&wall.p1_f, &wall.p2_f);
    if (is_equ_tolerance(wall.p2_f.x - wall.p1_f.x, 0, INTER_TOLERANCE))
        return (get_float_part((inter.y - wall.p1_f.y) / (wall.p2_f.y - wall.p1_f.y) * wall.length));
    return (get_float_part((inter.x - wall.p1_f.x) / (wall.p2_f.x - wall.p1_f.x) * wall.length));
}



float calc_wall_hit_scale_z(t_wall wall, t_point inter)
{
    sort_t_point_by_x(&wall.p1_f, &wall.p2_f);
    if (is_equ_tolerance(wall.p2_f.x - wall.p1_f.x, 0, INTER_TOLERANCE))
        return ( (inter.y - wall.p1_f.y) / (wall.p2_f.y - wall.p1_f.y) );
    return ( (inter.x - wall.p1_f.x) / (wall.p2_f.x - wall.p1_f.x) );
}

float calc_wall_hit_scale_x(t_wall wall, float scale_z)
{
    return (get_float_part(scale_z * wall.length));
}



t_calced_walls check_inter_with_wall(t_wall wall, t_rot rot, t_point pos, t_rot look_rot)
{
    t_point inter;
    t_calced_walls res;

    res.dist = 9999;
    res.scale = 0;
	res.wall = wall;
    res.inter = inter_with_dir(pos, rot, wall.p1_f, wall.p2_f);
    if (res.inter.x != -42)
    {
		// printf("res.inter : %f,%f\n", res.inter.x, res.inter.y);
		// printf("look_rot = %f, pos : %f,%f\n", look_rot, pos.x, pos.y);
        res.dist = ft_frange((look_rot.cos_rot) * (res.inter.x - pos.x) + (look_rot.sin_rot) * (res.inter.y - pos.y), 0.0042, res.dist);
		res.scale_z = calc_wall_hit_scale_z(wall, res.inter);
        res.scale = calc_wall_hit_scale_x(wall, res.scale_z);
    }
        //dist = hypot(res.inter.x - pos.x, res.inter.y - pos.y) * cos((look_rot - rot ));
    //printf("wall x min = %i, x max = %i, touch x = %f, scale = %f, rot = %f, look_rot = %f\n", wall.p1_f.x, wall.p2.x, res.inter.x, calc_wall_hit_scale(wall, res.inter), rot, look_rot);
    return (res);
}


t_calced_walls check_intersect_with_all_wall_rend(t_data *d, t_point pos, t_rot rot, t_rot look_rot)
{
    int i;
    t_calced_walls res ;
    t_calced_walls tmp;
    t_point inter;
    t_wall wall;

    i = 0;
    res.dist = 9999;
    while (i < d->map.wall_count)
    {
        wall = d->map.wall_list[i];
        tmp = check_inter_with_wall(wall, rot, pos, look_rot);
        res = tmp.dist < res.dist ? tmp : res ;
        //ft_fmin(dist, check_inter_with_wall(wall, rot, d->player_pos, look_rot));
        i++;
    }
    //printf("dist of closest wall : %f\n", res.dist);
    return (res);
}

t_calced_walls check_perp_wall(t_wall wall, t_point pos)
{
    t_point p1;
    t_point p2;
    t_calced_walls res;
	t_rot			wall_rot;

    res.dist = 9999;
    res.scale = 0;
	res.wall = wall;
	wall_rot.cos_rot = cos(wall.rotation + M_PI_2);
	wall_rot.sin_rot = sin(wall.rotation + M_PI_2);
    p1.x = pos.x + cos(wall.rotation - M_PI_2) * 30;
    p1.y = pos.y + sin(wall.rotation - M_PI_2) * 30;
    p2.x = pos.x + wall_rot.cos_rot * 30; 
	p2.y = pos.y + wall_rot.sin_rot * 30;
    printf("p1: %.8f,%.8f, p2 = %.8f,%.8f\n",p1.x, p1.y, p2.x, p2.y);
    //printf("cos = %f, sin = %f\n", cos(wall.rotation + M_PI_2), sin(wall.rotation + M_PI_2));
    res.inter = find_intersect(p1, p2, wall.p1_f, wall.p2_f);
    //printf("res.inter = %f,%f\n", res.inter.x, res.inter.y);
    if (res.inter.x != -42)
    {
        //res.dist = ft_frange(cos(wall.rotation + M_PI_2) * (res.inter.x - pos.x) + sin(wall.rotation + M_PI_2) * (res.inter.y - pos.y), 0, res.dist);
        res.dist = fabs(wall_rot.cos_rot * (res.inter.x - pos.x) + wall_rot.sin_rot * (res.inter.y - pos.y));
		res.scale_z = calc_wall_hit_scale_z(wall, res.inter);
        res.scale = calc_wall_hit_scale_x(wall, res.scale_z);
    }
        //dist = hypot(res.inter.x - pos.x, res.inter.y - pos.y) * cos((look_rot - rot ));
    //printf("wall x min = %i, x max = %i, touch x = %f, scale = %f, rot = %f, look_rot = %f\n", wall.p1.x, wall.p2.x, res.inter.x, calc_wall_hit_scale(wall, res.inter), rot, look_rot);
    return (res);
}

t_calced_walls check_perp_all_wall(t_data *d, t_map_data *map, t_point pos)
{
    int i;
    t_calced_walls res ;
    t_calced_walls tmp;
    t_point inter;
    t_wall wall;

    i = 0;
    res.dist = 9999;
    while (i < map->wall_count)
    {
        wall = map->wall_list[i];
        tmp = check_perp_wall(wall, d->player_pos);
        res = tmp.dist < res.dist ? tmp : res ;
        //ft_fmin(dist, check_inter_with_wall(wall, rot, d->player_pos, look_rot));
        i++;
    }
    //printf("dist of closest wall : %f\n", res.dist);
    return (res);
}

void sort_walls_by_dist(t_data *d, t_point pos, t_rot current_angle, t_calced_walls *sorted_walls)
{
    int i;
    int j;
    int tmp;
    t_calced_walls dist_scale;
	t_map_data *map;

	map = &d->map;
    sorted_walls[0] = check_inter_with_wall(map->wall_list[0], current_angle, pos, current_angle);
    i = 1;
    while (i < map->wall_count)
    {
        dist_scale = check_inter_with_wall(map->wall_list[i], current_angle, pos, current_angle);
        //printf("wall dist to player = %f\n",  dist_scale.dist);
        j = 0;
        while (dist_scale.dist < sorted_walls[j].dist && j < i)
            j++;
        tmp = j;
        j = i;
        while (j > tmp)
        {
            j--;
            sorted_walls[j + 1] = sorted_walls[j];
        }
        sorted_walls[j] = dist_scale;
        i++;
    }
    // i = 0;
    // while (i < map->wall_count)
    // {
    //     printf("wall sorted dist = %f, inter : %f,%f, i = %i, map_count = %i\n", sorted_walls[i].dist, sorted_walls[i].inter.x, sorted_walls[i].inter.y, i, map->wall_count);
    //     i++;
    // }
}

void sort_walls_by_dist_player(t_data *d, t_point pos, t_rot current_angle, t_calced_walls *sorted_walls)
{
    int i;
    int j;
    int tmp;
    t_calced_walls dist_scale;
	t_map_data *map;

	map = &d->map;
    sorted_walls[0] = check_inter_with_wall(map->wall_list[0], current_angle, pos, d->rot_calc);
    i = 1;
    while (i < map->wall_count)
    {
        dist_scale = check_inter_with_wall(map->wall_list[i], current_angle, pos, d->rot_calc);
        //printf("wall dist to player = %f\n",  dist_scale.dist);
        j = 0;
        while (dist_scale.dist < sorted_walls[j].dist && j < i)
            j++;
        tmp = j;
        j = i;
        while (j > tmp)
        {
            j--;
            sorted_walls[j + 1] = sorted_walls[j];
        }
        sorted_walls[j] = dist_scale;
        i++;
    }
    // i = 0;
    // while (i < map->wall_count)
    // {
    //     printf("wall sorted dist = %f, i = %i, map_count = %i, room_id = %i\n", sorted_walls[i].dist, i, map->wall_count, sorted_walls[i].wall.room_id_ref);
    //     i++;
    // }
}

void sort_props_by_dist_player(t_data *d, t_point pos, t_rot current_angle, t_calced_walls *sorted_walls)
{
    int i;
    int j;
    int tmp;
    t_calced_walls dist_scale;
	t_map_data *map;

	map = &d->map;
    sorted_walls[0] = check_inter_with_wall(map->wall_list[0], current_angle, pos, d->rot_calc);
    i = 1;
    while (i < map->wall_count)
    {
        dist_scale = check_inter_with_wall(map->wall_list[i], current_angle, pos, d->rot_calc);
        //printf("wall dist to player = %f\n",  dist_scale.dist);
        j = 0;
        while (dist_scale.dist < sorted_walls[j].dist && j < i)
            j++;
        tmp = j;
        j = i;
        while (j > tmp)
        {
            j--;
            sorted_walls[j + 1] = sorted_walls[j];
        }
        sorted_walls[j] = dist_scale;
        i++;
    }
    // i = 0;
    // while (i < map->wall_count)
    // {
    //     printf("wall sorted dist = %f, i = %i, map_count = %i, room_id = %i\n", sorted_walls[i].dist, i, map->wall_count, sorted_walls[i].wall.room_id_ref);
    //     i++;
    // }
}

void sort_perp_walls_dist(t_data *d, t_map_data *map, t_point pos, t_calced_walls *sorted_walls)
{
    int i;
    int j;
    int tmp;
    t_calced_walls dist_scale;

    sorted_walls[0] = check_perp_wall(map->wall_list[0], pos);
    i = 1;
    while (i < map->wall_count)
    {
        dist_scale = check_perp_wall(map->wall_list[i], pos);
        //printf("wall dist to player = %f\n",  dist_scale.dist);
        j = 0;
        while (dist_scale.dist < sorted_walls[j].dist && j < i)
            j++;
        tmp = j;
        j = i;
        while (j > tmp)
        {
            j--;
            sorted_walls[j + 1] = sorted_walls[j];
        }
        sorted_walls[j] = dist_scale;
        i++;
    }
    // i = 0;
    // while (i < map->wall_count)
    // {
    //     printf("wall sorted dist = %f, i = %i, map_count = %i\n", sorted_walls[i].dist, i, map->wall_count);
    //     i++;
    // }
}