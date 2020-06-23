#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

// int	is_in_room(int current_room, t_point pos, int i, t_calced_walls sorted[NB_WALL_MAX])
// {
// 	int wall_hits;
// 	int	in_room;

// 	wall_hits = 0;
// 	printf("Enter in room : %i\n", current_room);
// 	while (i-- > 0)
// 	{
// 		if (sorted[i].dist > 9998)
// 			break ;
// 		if (sorted[i].wall.room_id_ref < 0)
// 			continue ;
// 		printf("i = %i, wall_hits = %i, room_id = %i\n", i, wall_hits, current_room);
// 		if (sorted[i].wall.room_id_ref != current_room)
// 		{	
// 			if ((in_room = is_in_room(sorted[i].wall.room_id_ref, pos, i + 1, sorted)) > -1)
// 				return (in_room);
// 		}
// 		else if (sorted[i].inter.y > pos.y)
// 			if (wall_hits % 2 == 1)
// 				return (current_room);
// 			else
// 				return (- 1);
// 		wall_hits++;
// 	}
// 	return (- 1);
// }

void	init_wall_hit(int *wall_hit, int room_count)
{
	int i;

	i = 0;
	while (i < room_count)
	{
		wall_hit[i++] = 0;
	}
}

int	check_obj_room(t_data *d, t_point pos)
{
	int wall_hits[NB_WALL_MAX];
	int i;
	int room_ref;
	t_ray sorted[NB_MAX_OBJ];
	int max;

	sort_ray_by_dist(d, (t_point){pos.x, 0}, (t_rot){M_PI_2, cos(M_PI_2), sin(M_PI_2)}, sorted);
	init_wall_hit(wall_hits, d->map.room_count);
	i = 0;
	max = d->nb_obj;
	while (i < max)
	{
		if (sorted[i].dist > 9998)
			break ;
		if ((room_ref = sorted[i].room_id) > -1)
		{
			printf("room ref = %i\n", room_ref);
			if (sorted[i].inter.y > pos.y)
			{
				if (wall_hits[room_ref] % 2 == 1)
					return (room_ref);
				else
					wall_hits[room_ref] = -NB_WALL_MAX;
			}
			wall_hits[room_ref] += 1;
		}
		i++;
	}
	return (-1);
}

float set_room_ground(t_data *d, t_point pos)
{
	int room_id;

	if ((room_id = check_obj_room(d, pos)) > -1)
		return (d->map.room_list[room_id].z_ground);
	else
		return (DEFAULT_Z_GROUND);
	//printf("z_ground = %f\n", d->z_ground);
}