#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

int check_in_room(t_data *d, t_point pos)
{
	int room_id;
	t_calced_walls sorted[NB_WALL_MAX];
	int i;
	int	wall_hits;

	room_id = -1;
	i = -1;
	wall_hits = 0;
	sort_walls_by_dist(d, (t_point){pos.x, d->map.map_size.h}, -M_PI_2, sorted);
	while (++i < d->map.wall_count)
	{
		
		printf("i = %i, wall_hits = %i\n", i, wall_hits);
		printf("posy : %f, inter: %f, %f\n", pos.y, sorted[i].inter.x, sorted[i].inter.y);
		if (sorted[i].inter.y > pos.y)
			break ;
		if (sorted[i].wall.room_id_ref > -1  && sorted[i].dist < 9999)
			wall_hits++;
		else
			continue ;	
	}
	if (wall_hits % 2 == 1) /* in room if walls hits is odd */
	{
		return (sorted[i].wall.room_id_ref);
	}
	
	return (room_id);
}