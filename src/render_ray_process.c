#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

float calc_ray_hit_scale(t_point p1, t_point p2, t_point inter)
{
    sort_t_point_by_x(&p1, &p2);
    if (is_equ_tolerance(p2.x - p1.x, 0, INTER_TOLERANCE))
        return (get_float_part((inter.y - p1.y) / (p2.y - p1.y)));
    return (get_float_part((inter.x - p1.x) / (p2.x - p1.x)));
}

float calc_ray_mod_scale(float scale, float length)
{
    return (get_float_part(scale * length));
}

t_ray check_inter_with_obj(t_obj *obj, t_rot rot, t_point pos, t_rot look_rot)
{
	t_ray res;

    res.dist = 9999;
    res.scale = 0;
	//printf("obj p1 : %f,%f, p2 : %f,%f\n", obj->p1.x, obj->p1.y, obj->p2.x,  obj->p2.y);
    res.inter = inter_with_dir(pos, rot, obj->p1, obj->p2);
	res.obj_ref = obj;
	res.room_id = obj->room_id;
    if (res.inter.x != -42)
    {
		// printf("res.inter : %f,%f\n", res.inter.x, res.inter.y);
		// printf("look_rot = %f, pos : %f,%f\n", look_rot, pos.x, pos.y);
        res.dist = ft_frange((look_rot.cos_rot) * (res.inter.x - pos.x) + (look_rot.sin_rot) * (res.inter.y - pos.y), 0.00000042, res.dist);
        res.scale = calc_ray_hit_scale(obj->p1, obj->p2, res.inter);
		res.mod_scale = calc_ray_mod_scale(res.scale, obj->length);
		res.z_height.pos = obj->z_height.pos + obj->z_step.pos * res.scale;
		res.z_height.size = obj->z_height.size + obj->z_step.size * res.scale;
		if (res.room_id < -1)
			res.z_text = 1;
		else
			res.z_text = res.z_height.size;
    }
	//print_ray(res);
        //dist = hypot(obj->inter.x - pos.x, obj->inter.y - pos.y) * cos((look_rot - rot ));
    //printf("wall x min = %i, x max = %i, touch x = %f, scale = %f, rot = %f, look_rot = %f\n", wall.p1_f.x, wall.p2.x, obj->inter.x, calc_wall_hit_scale(wall, obj->inter), rot, look_rot);
	return (res);
}

void sort_ray_by_dist_player(t_data *d, t_point pos, t_rot current_angle, t_ray *sorted)
{
    int i;
    int j;
    int tmp;
    t_ray ray;
	t_map_data *map;

	map = &d->map;
    sorted[0] = check_inter_with_obj(&d->obj_list[0], current_angle, pos, d->rot_calc);
    i = 1;
    while (i < d->nb_obj)
    {
        ray = check_inter_with_obj(&d->obj_list[i], current_angle, pos, d->rot_calc);
        //printf("wall dist to player = %f\n",  ray.dist);
        j = 0;
        while (ray.dist > sorted[j].dist && j < i)
            j++;
        tmp = j;
        j = i;
        while (j > tmp)
        {
            j--;
            sorted[j + 1] = sorted[j];
        }
        sorted[j] = ray;
        i++;
    }
    // i = 0;
    // while (i < d->nb_obj)
    // {
    //     printf("wall sorted dist = %f, i = %i, obj_count = %i\n", sorted[i].dist, i, d->nb_obj);
    //     i++;
    // }
}