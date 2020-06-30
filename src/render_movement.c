#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"


void move_attempt(t_data *d, t_point *pos, float speed, t_rot look_rot)
{
    pos->y += speed * look_rot.sin_rot * d->diff_time;
    pos->x += speed * look_rot.cos_rot * d->diff_time;
}

float mod_pi(float rot)
{
	if (rot < 0)
		rot = PI_X_2 + rot;
	return(fmod(rot, PI_X_2));
}

int is_angle_in_range(float rot, float min, float max)
{
	// printf("rot = %f, min = %f, max = %f\n", rot, min, max);
	if (min > max && (rot > min || rot < max))
		return (1);
	else if (rot > min && rot < max)
		return (1);
	return (0);
}

// void move_with_collide(t_data *d, t_point *pos, t_rot rot, float speed)
// {
//     t_calced_walls sorted[NB_WALL_MAX];
// 	t_point inter;
// 	float	diff_x;
// 	int		will_collide;
// 	int		i;
// 	t_calced_walls res;

//     sort_perp_walls_dist(d, &d->map, *pos, sorted);
//     // printf("rot = %f, wall rot = %f\n", rot / M_PI_2, res.wall.rotation);
// 	// printf("diff mod pi = %f\n", mod_pi(rot - res.wall.rotation) / M_PI_2);
// 	i = 0;
// 	will_collide = 0;
// 	while (i < d->map.wall_count)
// 	{
// 		if (sorted[i].dist < WALL_SIZE)
// 		{
// 			inter = find_intersect_no_bound(*pos, (t_point){pos->x + (rot.cos_rot), pos->y + (rot.sin_rot)}, (sorted[i].wall.p1_f), (sorted[i].wall.p2_f));
// 			diff_x = inter.x - pos->x;
// 			if ( (diff_x > 0 && (rot.cos_rot) > 0) || (diff_x < 0 && (rot.cos_rot) < 0) )
// 			{
// 				res = sorted[i];
// 				//printf("wall z = %f, z_pos = %f\n", ft_interpolate(res.wall.p1_z_start + res.wall.p1_z_size, res.wall.p2_z_start + res.wall.p2_z_size, res.scale_z), d->z_pos);
// 				if (ft_interpolate(res.wall.p1_z_start + res.wall.p1_z_size, res.wall.p2_z_start + res.wall.p2_z_size, res.scale_z) > d->z_pos
// 				&& ft_interpolate(res.wall.p1_z_start, res.wall.p2_z_start, res.scale_z) - d->z_offset < d->z_pos)
// 					if (++will_collide > 1)
// 						break;
// 			}
// 		}
// 		i++;
// 	}
// 	// printf("inter : %f,%f, diff : %f,%f, dir : %f,%f\n", inter.x, inter.y, inter.x - pos->x, inter.y - pos->y, cos(rot), + sin(rot));
// 	if (will_collide == 1)
// 	{
// 		// printf("recalc needed, wall rot = %f, rot = %f\n", res.wall.rotation / M_PI_2, rot.rot / M_PI_2);
// 		move_attempt(d, pos, cos(rot.rot - res.wall.rotation) * speed, (t_rot){res.wall.rotation, cos(res.wall.rotation), sin(res.wall.rotation)});
// 		move_grabbed_wall(d, (t_rot){res.wall.rotation, cos(res.wall.rotation), sin(res.wall.rotation)}, cos(rot.rot - res.wall.rotation) * speed);
// 	}
// 	else if (will_collide < 1)
// 	{
// 		move_attempt(d, pos, speed, rot);
// 		move_grabbed_wall(d, rot, speed);
// 	}
// 	d->z_ground = set_room_ground(d, *pos);
// }

void move_with_collide(t_data *d, t_obj *obj, t_rot rot, float speed)
{
    t_ray sorted[NB_MAX_OBJ];
	t_point inter;
	float	diff_x;
	int		will_collide;
	int		i;
	t_ray res;
	t_point	*pos;

	pos = &obj->pos;
    sort_perp_ray(d, *pos, sorted);
    // printf("rot = %f, wall rot = %f\n", rot / M_PI_2, res.wall.rotation);
	// printf("diff mod pi = %f\n", mod_pi(rot - res.wall.rotation) / M_PI_2);
	i = 0;
	will_collide = 0;
	while (i < d->nb_obj)
	{
		// printf("dist = %f\n", sorted[i].dist);
		if (sorted[i].dist < WALL_SIZE)
		{
			// printf("close to wall\n");
			inter = find_intersect_no_bound(*pos, (t_point){pos->x + (rot.cos_rot), pos->y + (rot.sin_rot)}, (sorted[i].obj_ref->p1), (sorted[i].obj_ref->p2));
			diff_x = inter.x - pos->x;
			if ( (diff_x > 0 && (rot.cos_rot) > 0) || (diff_x < 0 && (rot.cos_rot) < 0) )
			{
				res = sorted[i];
				//printf("wall z = %f, z_pos = %f\n", ft_interpolate(res.wall.p1_z_start + res.wall.p1_z_size, res.wall.p2_z_start + res.wall.p2_z_size, res.scale_z), d->z_pos);
				if (res.z_height.pos + res.z_height.size > obj->z_height.pos
				&& res.z_height.pos - d->z_offset < obj->z_height.pos)
					if (++will_collide > 1)
						break;
			}
		}
		i++;
	}
	// printf("inter : %f,%f, diff : %f,%f, dir : %f,%f\n", inter.x, inter.y, inter.x - pos->x, inter.y - pos->y, cos(rot), + sin(rot));
	if (will_collide == 1)
		// printf("recalc needed, wall rot = %f, rot = %f\n", res.wall.rotation / M_PI_2, rot.rot / M_PI_2);
		move_attempt(d, pos, cos(rot.rot - res.obj_ref->rotation.rot) * speed, res.obj_ref->rotation);
	else if (will_collide < 1)
		move_attempt(d, pos, speed, rot);
	obj->z_ground = set_room_ground(d, obj->pos);
}

void move_with_collide_player(t_data *d, t_point *pos, t_rot rot, float speed)
{
    t_ray sorted[NB_MAX_OBJ];
	t_point inter;
	float	diff_x;
	int		will_collide;
	int		i;
	t_ray res;

    sort_perp_ray(d, *pos, sorted);
    // printf("rot = %f, wall rot = %f\n", rot / M_PI_2, res.wall.rotation);
	// printf("diff mod pi = %f\n", mod_pi(rot - res.wall.rotation) / M_PI_2);
	i = 0;
	will_collide = 0;
	while (i < d->nb_obj)
	{
		// printf("dist = %f\n", sorted[i].dist);
		if (sorted[i].dist < WALL_SIZE)
		{
			// printf("close to wall\n");
			inter = find_intersect_no_bound(*pos, (t_point){pos->x + (rot.cos_rot), pos->y + (rot.sin_rot)}, (sorted[i].obj_ref->p1), (sorted[i].obj_ref->p2));
			diff_x = inter.x - pos->x;
			if ( (diff_x > 0 && (rot.cos_rot) > 0) || (diff_x < 0 && (rot.cos_rot) < 0) )
			{
				res = sorted[i];
				//printf("wall z = %f, z_pos = %f\n", ft_interpolate(res.wall.p1_z_start + res.wall.p1_z_size, res.wall.p2_z_start + res.wall.p2_z_size, res.scale_z), d->z_pos);
				if (res.z_height.pos + res.z_height.size > d->z_pos
				&& res.z_height.pos - d->z_offset < d->z_pos)
					if (++will_collide > 1)
						break;
			}
		}
		i++;
	}
	// printf("inter : %f,%f, diff : %f,%f, dir : %f,%f\n", inter.x, inter.y, inter.x - pos->x, inter.y - pos->y, cos(rot), + sin(rot));
	if (will_collide == 1)
	{
		// printf("recalc needed, wall rot = %f, rot = %f\n", res.wall.rotation / M_PI_2, rot.rot / M_PI_2);
		move_attempt(d, pos, cos(rot.rot - res.obj_ref->rotation.rot) * speed, res.obj_ref->rotation);
		move_grabbed_wall(d, res.obj_ref->rotation, cos(rot.rot - res.obj_ref->rotation.rot) * speed);
	}
	else if (will_collide < 1)
	{
		move_attempt(d, pos, speed, rot);
		move_grabbed_wall(d, rot, speed);
	}
	d->z_ground = set_room_ground(d, *pos);
}

void gravity_obj(t_data *d, t_obj *objs, int nb_obj)
{
	int i;
	t_obj	*obj;

	i = 0;
	while (i < nb_obj)
	{
		obj = &objs[i];
		if (obj->z_ground > -1)
		{
			obj->z_height.pos += obj->z_force;
			if (obj->z_height.pos > obj->z_ground)
			{
				obj->z_height.pos -=  GRAVITY_FORCE * obj->air_time * obj->air_time ;
				obj->air_time += d->time - d->time_last_frame;
				//printf("air_time = %d\n", obj->air_time);
			}
			obj->z_text_offset = obj->z_height.pos + obj->z_height.size;
			if (obj->z_height.pos < obj->z_ground)
			{
				obj->z_height.pos = obj->z_ground;
				obj->z_force = 0;
				obj->air_time = 0;
			}
		}
		i++;
	}
}

void gravity(t_data *d)
{
    d->z_pos += d->z_force;
    d->player_height = d->z_pos + d->z_offset;
	//if (check_in_room(d, d->player_pos) > -1)
	//	printf("is in room\n");
    if (d->z_pos > d->z_ground)
    {
        d->z_pos -= GRAVITY_FORCE * d->air_time * d->air_time ;
        d->air_time += d->time - d->time_last_frame;
        //printf("air_time = %d\n", d->air_time);
    }
    if (d->z_pos < d->z_ground)
    {
        d->z_pos = d->z_ground;
        d->z_force = 0;
        d->air_time = 0;
    }
	gravity_obj(d, d->obj_list, d->nb_obj);
}

