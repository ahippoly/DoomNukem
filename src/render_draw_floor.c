/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:10:29 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/13 02:44:37 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

t_draw	calc_floor_draw_range(t_data *d, t_ray ray1, float dist2, int x)
{
	t_draw	draw;
	t_room	*room;

	room = get_room_by_id(d, ray1.room_id);
	draw.start_y = d->screen_height
	+ ((d->player_height - room->z_ground) * WIN_SIZE_Y) / ray1.dist;
	draw.end_y = d->screen_height
	+ ((d->player_height - room->z_ground) * WIN_SIZE_Y) / dist2;
	draw.start_x = x;
	return (draw);
}

void	draw_floor_line(t_data *d, t_range draw, int x, int room_id)
{
	int		color;

	if (room_id == 0)
		color = RED;
	if (room_id == 1)
		color = 0xFFF00FFF;
	if (room_id == 2)
		color = 0x00FFFFFF;
	if (room_id == 3)
		color = BLUE;
	draw.start *= WIN_SIZE_X;
	draw.end *= WIN_SIZE_X;
	while (draw.start < draw.end)
	{
		d->p_screen[x + draw.start] = color;
		draw.start += WIN_SIZE_X;
	}
}

void	init_floor(t_data *d, t_floor *fl, float pos_z)
{
	int		y;
	float	row_dist;
	t_point	ray_dir0;
	t_point	ray_dir1;
	t_point	ray_diff;

	ray_dir0.x = cos(d->rot) + d->fov * sin(d->rot);
	ray_dir1.x = cos(d->rot) - d->fov * sin(d->rot);
	ray_dir0.y = sin(d->rot) - d->fov * cos(d->rot);
	ray_dir1.y = sin(d->rot) + d->fov * cos(d->rot);
	ray_diff.x = ray_dir1.x - ray_dir0.x;
	ray_diff.y = ray_dir1.y - ray_dir0.y;
	y = d->screen_height + 1;
	while (y < WIN_SIZE_Y)
	{
		row_dist = pos_z / (y - d->screen_height);
		fl[y].floor_step.x = row_dist * ray_diff.x / WIN_SIZE_X;
		fl[y].floor_step.y = row_dist * ray_diff.y / WIN_SIZE_X;
		fl[y].floor.x = (d->player_pos.x + row_dist * ray_dir0.x);
		fl[y].floor.y = (d->player_pos.y + row_dist * ray_dir0.y);
		y++;
	}
}

void	init_floors(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->map.room_count)
	{
		init_floor(d, d->fl[i],
		(d->player_height - d->map.room_list[i].z_ground) * WIN_SIZE_Y);
		i++;
	}
}

void	print_floor_slice(t_data *d, t_floor *fl, t_draw draw, int text_id)
{
	t_size			t_max;
	t_range			y;
	t_floor			current;
	t_img			*text;
	unsigned int	*pixels;

	text = &d->texture[text_id];
	t_max.w = text->w - 1;
	t_max.h = text->h - 1;
	pixels = (unsigned int*)text->pixels;
	y.start = ft_range(draw.start_y, 0, WIN_SIZE_Y - 1);
	draw.end_y = ft_min(draw.end_y * WIN_SIZE_X, TOTAL_PIX);
	draw.start_y = y.start * WIN_SIZE_X;
	while (draw.start_y < draw.end_y)
	{
		current = fl[y.start];
		d->p_screen[draw.start_x + draw.start_y] = pixels[((int)
		(get_float_part(current.floor.x + current.floor_step.x * draw.start_x)
		* text->w) & t_max.w) + ((int)(get_float_part(current.floor.y
		+ current.floor_step.y * draw.start_x) * text->h) & t_max.h) * text->w];
		draw.start_y += WIN_SIZE_X;
		y.start++;
	}
}
