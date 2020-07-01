#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"

int	grab_wall(t_data *d, t_point pos, t_rot look_rot)
{
	t_calced_walls res;
	int success;

	success = 0;
	res = check_intersect_with_all_wall_rend(d, pos, look_rot, look_rot);
	if (res.dist < 9999)
	{
		d->grabbed_wall = &d->map.wall_list[res.wall.id];
		d->grab_z = d->screen_height;
		success = 1;
	}
	return (success);
}

void	move_wall(t_data *d, t_wall *wall, t_rot look_rot, float speed)
{
	move_attempt(d, &wall->p1, speed, look_rot);
	move_attempt(d, &wall->p2, speed, look_rot);
}

void	move_grabbed_wall(t_data *d, t_rot look_rot, float speed)
{
	if (d->grabbed_wall)
		move_wall(d, d->grabbed_wall, look_rot, speed);
}

void	move_z_grabbed_wall(t_data *d, float z_diff)
{
	if (d->grabbed_wall)
	{
		d->grabbed_wall->p1_z_start += z_diff;
		d->grabbed_wall->p2_z_start += z_diff;
		d->grabbed_wall->z_text_offset += z_diff;
	}
}

void	rot_wall(t_wall *wall, float rot, int pivot_point)
{
	wall->rotation += rot;
	if (pivot_point == 0)
		wall->p2 = (t_point){wall->p1.x + wall->length * cos(wall->rotation), wall->p1.y + wall->length * sin(wall->rotation)};
}

void	rot_grabbed_wall(t_data *d, float rot, int pivot_point)
{
	if (d->grabbed_wall)
		rot_wall(d->grabbed_wall, rot, pivot_point);
}