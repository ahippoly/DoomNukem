#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"
#include "proto_global.h"

void	clear_p_tab(t_data *d, t_range screen_x)
{
	int i;
	unsigned int *pixels;
	int end_y;

	pixels = d->p_screen;
	end_y = WIN_SIZE_Y * WIN_SIZE_X;
	while (screen_x.start < screen_x.end)
	{
		i = 0;
		while (i < end_y)
		{
			pixels[screen_x.start + i] = 0x00000000;
			i += WIN_SIZE_X;
		}
		screen_x.start++;
	}
}

t_room	*get_room_by_id(t_data *d, int room_id)
{
	if (room_id > -1)
		return (&d->map.room_list[room_id]);
}

void draw_floor_slice(t_data *d, t_ray *queue, int *nb, t_ray checked, int x)
{
	int queue_room;
	int check_room;

	if (*nb > -1)
	{
		queue_room = queue[*nb].room_id;
		check_room = checked.room_id;
		if (check_room == queue_room)
		{
			if (queue[*nb].dist < RENDER_DISTANCE_MAX)
				print_floor_slice(d, d->fl[queue_room], calc_floor_draw_range(d, queue[*nb], checked.dist, x),  get_room_by_id(d, queue[*nb].room_id)->floor_text);
			(*nb)--;
			if (*nb > -1)
				queue[*nb].dist = checked.dist;
			return ;
		}
		else
		{
			if (queue[*nb].dist < RENDER_DISTANCE_MAX)
				print_floor_slice(d, d->fl[queue_room], calc_floor_draw_range(d, queue[*nb], checked.dist, x),  get_room_by_id(d, queue[*nb].room_id)->floor_text);
			queue[*nb].dist = checked.dist;
		}
	}
	if (checked.room_id > -1)
	{
		(*nb)++;
		queue[*nb] = checked;
	}
}

void	raycast_screen2(t_data *d, t_range screen_x, float start_angle, float step)
{
	int i;
	t_ray sorted[NB_WALL_MAX];
	t_ray queue[NB_WALL_MAX];
	int nb;

	start_angle += step * screen_x.start;
	clear_p_tab(d, screen_x);
	while (screen_x.start < screen_x.end)
    {
        i = 0;
        sort_ray_by_dist_player(d, d->player_pos , (t_rot){start_angle, cos(start_angle), sin(start_angle)}, sorted);
		while (i < d->nb_obj && sorted[i].dist < 9999)
			i++;
		nb = -1;
        while (i-- > 0)
		{
			draw_floor_slice(d, queue, &nb, sorted[i], screen_x.start);
			if (sorted[i].dist < RENDER_DISTANCE_MAX)
				draw_text_slice(d->p_screen, calc_ray_draw_range(d, sorted[i], screen_x.start), *sorted[i].obj_ref, sorted[i]);
		}
		if (nb > -1)
			print_floor_slice(d, d->fl[queue[nb].room_id], calc_floor_draw_range_end(d, queue[nb].dist, get_room_by_id(d, queue[nb].room_id), screen_x.start), get_room_by_id(d, queue[nb].room_id)->floor_text);
        start_angle += step;
        screen_x.start++;
    }
}

void	*raycast_thread(void *data)
{
	t_thread	*param;

	param = (t_thread*)data;
	raycast_screen2(param->d, param->screen_x, param->start_angle, param->step);
	return (NULL);
}

void raycast_thread_init(t_data *d)
{
	pthread_t thread[THREAD_NB];
	t_thread	param[THREAD_NB];
    float start = d->rot - d->fov_rad / 2;
    float step = d->fov_rad / WIN_SIZE_X;
    int i;

    i = 0;
	init_floors(d);
	while (i < THREAD_NB)
	{
		param[i].d = d;
		param[i].start_angle = start;
		param[i].step = step;
		param[i].screen_x = (t_range){i * WIN_SIZE_X / THREAD_NB, (i + 1) * WIN_SIZE_X / THREAD_NB};
		// prlintf("start = %i, end = %i\n", i * WIN_SIZE_X / THREAD_NB, (i + 1) * WIN_SIZE_X / THREAD_NB);
		pthread_create(&thread[i], NULL, raycast_thread, &param[i]);
		i++;
	}
	i = 0;
	while (i < THREAD_NB)
		pthread_join(thread[i++], NULL);
}

void raycast_all_screen(t_data *d, t_map_data *map)
{
    float current_angle = d->rot - d->fov_rad / 2;
    float step = d->fov_rad / WIN_SIZE_X;
    int x;
    int i;
	t_calced_walls sorted_walls[NB_WALL_MAX];
	t_range screen_x;

    x = 0;
	screen_x.start = 0;
	screen_x.end = WIN_SIZE_Y;
	init_floors(d);
	create_obj_raybox(d);
	raycast_screen2(d, screen_x, current_angle, step);
    // while (x < WIN_SIZE_X)
    // {
    //     i = 0;
    //     sort_walls_by_dist_player(d, d->player_pos, (t_rot){current_angle, cos(current_angle), sin(current_angle)}, sorted_walls);
    //     while (i < map->wall_count)
    //         draw_vertical_line(d, x, sorted_walls[i++]);
    //     //draw_vertical_line(d, x, check_intersect_with_all_wall_rend(d, map, current_angle, d->rot), d->texture[0]);
    //     current_angle += step;
    //     x++;
    // }
}