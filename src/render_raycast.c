/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 00:36:15 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/05 16:43:01 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	draw_floor_slice(t_data_x d, t_ray *queue, int *nb, t_ray checked)
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
				print_floor_slice(d.d, d.d->fl[queue_room],
				calc_floor_draw_range(d.d, queue[*nb], checked.dist, d.x),
				get_room_by_id(d.d, queue[*nb].room_id)->floor_text);
			(*nb)--;
			if (*nb > -1)
				queue[*nb].dist = checked.dist;
			return ;
		}
		else
			draw_same_room(d.d, &queue[*nb], &checked, d.x);
	}
	add_to_queue(nb, queue, &checked);
}

void	draw_each_objs(t_data *d, float start_angle, t_range screen_x)
{
	int		i;
	t_ray	sorted[NB_WALL_MAX];
	t_ray	queue[NB_WALL_MAX];
	int		nb;

	i = 0;
	sort_ray_by_dist_player(d, d->player_pos, (t_rot){start_angle,
		cos(start_angle), sin(start_angle)}, sorted);
	while (i < d->nb_obj && sorted[i].dist < 9999)
		i++;
	nb = -1;
	while (i-- > 0)
	{
		draw_floor_slice((t_data_x){d, screen_x.start}, queue, &nb, sorted[i]);
		if (sorted[i].dist < RENDER_DISTANCE_MAX)
			draw_text_slice(d->p_screen, calc_ray_draw_range(d, sorted[i],
				screen_x.start), *sorted[i].obj_ref, sorted[i]);
	}
	if (nb > -1 && sorted[0].dist < RENDER_DISTANCE_MAX)
		print_floor_slice(d, d->fl[queue[nb].room_id],
		calc_floor_draw_range_end(d, queue[nb].dist,
		get_room_by_id(d, queue[nb].room_id), screen_x.start),
		get_room_by_id(d, queue[nb].room_id)->floor_text);
}

void	raycast_screen2(t_data *d, t_range screen_x,
	float start_angle, float step)
{
	start_angle += step * screen_x.start;
	clear_p_tab(screen_x, d->p_screen);
	while (screen_x.start < screen_x.end)
	{
		draw_each_objs(d, start_angle, screen_x);
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

void	raycast_thread_init(t_data *d)
{
	pthread_t	thread[THREAD_NB];
	t_thread	param[THREAD_NB];
	float		start;
	float		step;
	int			i;

	start = d->rot - d->fov_rad / 2;
	step = d->fov_rad / WIN_SIZE_X;
	i = 0;
	init_floors(d);
	while (i < THREAD_NB)
	{
		param[i].d = d;
		param[i].start_angle = start;
		param[i].step = step;
		param[i].screen_x = (t_range){i * WIN_SIZE_X / THREAD_NB, (i + 1)
			* WIN_SIZE_X / THREAD_NB};
		pthread_create(&thread[i], NULL, raycast_thread, &param[i]);
		i++;
	}
	i = 0;
	while (i < THREAD_NB)
		pthread_join(thread[i++], NULL);
}
