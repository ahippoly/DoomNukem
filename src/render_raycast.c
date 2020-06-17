#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

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

void	find_next_room_wall(t_data *d, int x, int *i, t_calced_walls *sorted)
{
	t_calced_walls origin;
	t_range draw;

	origin = sorted[*i];
	(*i)++;
	// printf("entered find room, wall count = %i, i = %i, origin_room_id = %i, wall_test_room = %i\n", d->map.wall_count, *i, origin.wall.room_id_ref, sorted[*i].wall.room_id_ref);
	//printf("2i = %i, wall_count = %i\n", *i, d->map.wall_count);
	while (*i < d->map.wall_count)
	{
		// printf("wall count = %i, i = %i, origin_room_id = %i, wall_test_room = %i\n", d->map.wall_count, *i, origin.wall.room_id_ref, sorted[*i].wall.room_id_ref);
		if (sorted[*i].wall.room_id_ref == origin.wall.room_id_ref)
			break ;
		if (sorted[*i].wall.room_id_ref != -1)
		{
			draw_floor_line(d, calc_floor_draw_range(d, origin, sorted[*i]), x, origin.wall.room_id_ref);
			find_next_room_wall(d, x, i, sorted);
			origin.dist = sorted[*i].dist;
		}
		(*i)++;
	}
	if (*i < d->map.wall_count)
		draw_floor_line(d, calc_floor_draw_range(d, origin, sorted[*i]), x, origin.wall.room_id_ref);
	if (*i == d->map.wall_count)
	{
		draw = calc_floor_draw_range(d, origin, origin);
		draw.end = WIN_SIZE_Y;
		draw_floor_line(d, draw, x, origin.wall.room_id_ref);
		(*i)++;
	}
}

void	draw_floor_lines(t_data *d, int x, int i, t_calced_walls *sorted)
{
	i--;
	// printf("entered once\n");
	while (++i < d->map.wall_count)
	{
		// printf("i = %i, wall_count = %i\n", i, d->map.wall_count);
		if (sorted[i].wall.room_id_ref == -1)
			continue ;
		// printf("enter find room, i = %i\n", i);
		find_next_room_wall(d, x, &i, sorted);
	}
	
}

t_room	*get_room_by_id(t_data *d, t_wall *wall)
{
	if (wall->room_id_ref > -1)
		return (&d->map.room_list[wall->room_id_ref]);
}

void draw_floor_slice(t_data *d, t_calced_walls *queue, int *nb, t_calced_walls checked, int x)
{
	int room_id;

	if (*nb > -1)
	{
		room_id = queue[*nb].wall.room_id_ref;
		if (checked.wall.room_id_ref == queue[*nb].wall.room_id_ref)
		{
			//draw_floor_line(d, calc_floor_draw_range(d, queue[*nb], checked), x, room_id);
			print_floor_slice(d, d->fl[room_id], x, calc_floor_draw_range(d, queue[*nb], checked),  get_room_by_id(d, &queue[*nb].wall)->floor_text);
			(*nb)--;
			if (*nb > -1)
				queue[*nb].dist = checked.dist;
			return ;
		}
		else
		{
			print_floor_slice(d, d->fl[room_id], x, calc_floor_draw_range(d, queue[*nb], checked),  get_room_by_id(d, &queue[*nb].wall)->floor_text);
			//draw_floor_line(d, calc_floor_draw_range(d, queue[*nb], checked), x, queue[*nb].wall.room_id_ref);
			queue[*nb].dist = checked.dist;
		}
	}
	if (checked.wall.room_id_ref != -1)
	{
		(*nb)++;
		queue[*nb] = checked;
	}
}

void	raycast_screen(t_data *d, t_range screen_x, float start_angle, float step)
{
	int i;
	t_calced_walls sorted_walls[NB_WALL_MAX];
	t_calced_walls queue[NB_WALL_MAX];
	int nb;

	start_angle += step * screen_x.start;
	clear_p_tab(d, screen_x);
	while (screen_x.start < screen_x.end)
    {
        i = 0;
        sort_walls_by_dist_player(d, d->player_pos , (t_rot){start_angle, cos(start_angle), sin(start_angle)}, sorted_walls);
		while (i < d->map.wall_count && sorted_walls[i].dist > 9998)
			i++;
		nb = -1;
        while (i < d->map.wall_count)
		{
			draw_floor_slice(d, queue, &nb, sorted_walls[i], screen_x.start);
            draw_vertical_line(d, screen_x.start, sorted_walls[i++]);
		}
		if (nb > -1)
			print_floor_slice(d, d->fl[queue[nb].wall.room_id_ref], screen_x.start, calc_floor_draw_range_end(d, queue[nb]), get_room_by_id(d, &queue[nb].wall)->floor_text);
			//draw_floor_line(d, calc_floor_draw_range_end(d, queue[nb]), screen_x.start, queue[nb].wall.room_id_ref);
		// i = 0;
		// while (i < d->map.wall_count && sorted_walls[i].dist > 9998)
		// 	i++;
		//draw_floor_lines(d, screen_x.start, i, sorted_walls);
		//printf("segfault, i = %i\n", i);
        //draw_vertical_line(d, x, check_intersect_with_all_wall(d, map, start_angle, d->rot), d->texture[0]);
        start_angle += step;
        screen_x.start++;
    }
}

void	*raycast_thread(void *data)
{
	t_thread	*param;

	param = (t_thread*)data;
	raycast_screen(param->d, param->screen_x, param->start_angle, param->step);
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
	raycast_screen(d, screen_x, current_angle, step);
    // while (x < WIN_SIZE_X)
    // {
    //     i = 0;
    //     sort_walls_by_dist_player(d, d->player_pos, (t_rot){current_angle, cos(current_angle), sin(current_angle)}, sorted_walls);
    //     while (i < map->wall_count)
    //         draw_vertical_line(d, x, sorted_walls[i++]);
    //     //draw_vertical_line(d, x, check_intersect_with_all_wall(d, map, current_angle, d->rot), d->texture[0]);
    //     current_angle += step;
    //     x++;
    // }
}