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

int	check_player_room(t_data *d, t_point pos)
{
	int wall_hits[NB_WALL_MAX];
	int i;
	int room_ref;
	t_calced_walls sorted[NB_WALL_MAX];

	sort_walls_by_dist(d, (t_point){pos.x, 0}, M_PI_2, sorted);
	i = 0;
	while (i < d->map.room_count)
		wall_hits[i++] = 0;
	i = d->map.wall_count;
	while (i-- > 0)
	{
		if (sorted[i].dist > 9998)
			break ;
		if ((room_ref = sorted[i].wall.room_id_ref) > -1)
		{
			if (sorted[i].inter.y > pos.y)
				if (wall_hits[room_ref] % 2 == 1)
					return (room_ref);
				else
					wall_hits[room_ref] = -NB_WALL_MAX;
			wall_hits[room_ref] += 1;
		}
	}
	return (-1);
}

void set_room_ground(t_data *d, t_point pos)
{
	int room_id;

	if ((room_id = check_player_room(d, pos)) > -1)
		d->z_ground = d->map.room_list[room_id].z_ground;
	else
		d->z_ground = DEFAULT_Z_GROUND;
	//printf("z_ground = %f\n", d->z_ground);
}