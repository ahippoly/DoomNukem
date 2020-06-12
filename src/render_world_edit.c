#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

int	grab_wall(t_data *d, t_point pos, double look_rot)
{
	t_calced_walls res;
	int success;

	success = 0;
	res = check_intersect_with_all_wall(d, pos, look_rot, look_rot);
	if (res.dist < 9999)
	{
		d->grabbed_wall = &d->map.wall_list[res.wall.id];
		d->grab_z = d->screen_height;
		success = 1;
	}
	return (success);
}

void	move_wall(t_wall *wall, double look_rot, double speed)
{
	move_attempt(&wall->p1_f, speed, look_rot);
	move_attempt(&wall->p2_f, speed, look_rot);
}

void	move_grabbed_wall(t_data *d, double look_rot, double speed)
{
	if (d->grabbed_wall)
		move_wall(d->grabbed_wall, look_rot, speed);
}

void	move_z_grabbed_wall(t_data *d, double z_diff)
{
	if (d->grabbed_wall)
	{
		d->grabbed_wall->p1_z_start += z_diff;
		d->grabbed_wall->p2_z_start += z_diff;
	}
}