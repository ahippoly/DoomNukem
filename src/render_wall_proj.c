#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

t_proj_point		point_x_on_screen(t_data *d, t_point point, float rot, t_point pos)
{
	t_point	diff;
	float	cos_rot;
	float	sin_rot;
	t_proj_point res;

	// printf("point :%f,%f ; pos:%f,%f\n", point.x, point.y, pos.x, pos.y);
	diff.x = point.x - pos.x;
	diff.y = point.y - pos.y;
	cos_rot = cos(rot);
	sin_rot = sin(rot);
	res.dist = (diff.x * cos_rot + diff.y * sin_rot) * d->fov;
	res.scale_z = (diff.y * cos_rot - diff.x * sin_rot + res.dist) / (res.dist * 2);
	res.screen_x = res.scale_z * WIN_SIZE_X;
	if (res.screen_x < 0 || res.screen_x >= WIN_SIZE_X )
		res.on_screen = 0;
	else
		res.on_screen = 1;
	printf("scale_z = %f\n", res.scale_z);
	// printf("dist = %f\n", res.dist);
	// printf("screen_x = %i\n", res.screen_x);
	return (res);
}

void draw_point(t_data *d, t_proj_point point)
{
	int i;
	t_range draw;

	draw.start = HALF_WIN_SIZE_Y - (float)HALF_WIN_SIZE_Y / point.dist;
	draw.end = HALF_WIN_SIZE_Y + (float)HALF_WIN_SIZE_Y / point.dist;
	i = 0;
	draw.start = ft_max(draw.start, 0);
	draw.end = ft_min(draw.end, WIN_SIZE_Y);
	while (draw.start < draw.end)
	{
		if (point.screen_x >= WIN_SIZE_X || point.screen_x < 0 || draw.start < 0 || draw.start >= WIN_SIZE_Y)
			printf("draw x = %i, draw y = %i\n", point.screen_x, draw.start);
		put_pixel(d->p_screen, (SDL_Point){point.screen_x, draw.start}, (t_size){WIN_SIZE_X, WIN_SIZE_Y}, 0xFFFFFFFF);
		draw.start++;
	}
}

t_frange	calc_wall_draw_range(t_data *d, float dist)
{
	t_frange	res;

	res.start = HALF_WIN_SIZE_Y - (float)HALF_WIN_SIZE_Y / dist;
	res.end = HALF_WIN_SIZE_Y + (float)HALF_WIN_SIZE_Y / dist;
	return (res);
}

void sort_proj_point_x(t_proj_point *p1, t_proj_point *p2)
{
	t_proj_point *tmp;

	if (p1->screen_x > p2->screen_x)
	{
		tmp = p1;
		p1 = p2;
		p2 = tmp;
	}
}

void	draw_vert_line(t_data *d, int x, t_frange draw_y)
{
	draw_y.start = ft_max(draw_y.start, 0);
	draw_y.end = ft_min(draw_y.end, WIN_SIZE_Y);
	while (draw_y.start < draw_y.end)
	{
		put_pixel(d->p_screen, (SDL_Point){x, (int)draw_y.start}, (t_size){WIN_SIZE_X, WIN_SIZE_Y}, 0xFFFFFFFF);
		draw_y.start++;
	}
}

void print_wall(t_data *d, t_wall wall)
{
	t_proj_point point1;
	t_proj_point point2;
	int i;
	t_frange	draw_y;
	t_frange	step_y;
	int diff_x;


	point1 = point_x_on_screen(d, wall.p1_f, d->rot, d->player_pos);
	point2 = point_x_on_screen(d, wall.p2_f, d->rot, d->player_pos);
	sort_proj_point_x(&point1, &point2);
	// step_dist = (point2.dist - point1.dist) / (point2.screen_x - point1.screen_x);
	// printf("dist : p1 = %f, p2 = %f\n", point1.dist, point2.dist);
		//printf("p1.x : %d, p2.X : %d\n", point1.screen_x, point2.screen_x);
	draw_y = calc_wall_draw_range(d, point1.dist);
	step_y = calc_wall_draw_range(d, point2.dist);
	diff_x = point2.screen_x - point1.screen_x;
	step_y.start = (step_y.start - draw_y.start) / diff_x;
	step_y.end = (step_y.end - draw_y.end) / diff_x;
	if (point1.on_screen && point2.on_screen)
	{
		while (point1.screen_x < point2.screen_x)
		{
			//printf("p1.x : %d\n", point1.screen_x);
			draw_vert_line(d, point1.screen_x, draw_y);
			point1.screen_x++;
			draw_y.start += step_y.start;
			draw_y.end += step_y.end;
		}
	}

	// draw_point(d, point_x_on_screen(d, wall.p1_f, d->rot, d->player_pos));
	// draw_point(d, point_x_on_screen(d, wall.p2_f, d->rot, d->player_pos));

}