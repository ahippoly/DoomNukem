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
	res.scale_len = (diff.y * cos_rot - diff.x * sin_rot + res.dist) / (res.dist * 2);
	res.screen_x = res.scale_len * WIN_SIZE_X;
	if (res.dist >= 0 )
		res.on_screen = 1;
	else
		res.on_screen = 0;
	//printf("scale_len = %f\n", res.scale_len);
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

t_frange	calc_wall_draw_range(t_data *d, float dist, t_frange wall_height)
{
	t_frange	res;

	res.start = d->screen_height - ((wall_height.end - d->player_height) * WIN_SIZE_Y) / dist;
	res.end = d->screen_height + ((d->player_height - wall_height.start)  * WIN_SIZE_Y) / dist;
	return (res);
}

t_frange	calc_prop_draw_range(t_data *d, float dist, float height, float size)
{
	t_frange	res;

	res.start = d->screen_height - ((height - d->player_height + size) * WIN_SIZE_Y) / dist;
	res.end = d->screen_height + ((d->player_height - height + size)  * WIN_SIZE_Y) / dist;
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

unsigned int text_pixel(unsigned int *text, int x, float scale_z, int th)
{
	//printf("t : %i, %i\n", x, (int)(scale_z * th));
	return (text[x + (int)(scale_z * th) * 512]);
}

void	draw_vert_line(t_data *d, t_draw_line line)
{
	int tx;


	tx = (int)(line.scale_x * line.tw);
	line.scale_z = 0;
	if (line.draw_y.start < 0)
	{
		line.scale_z += line.scale_z_step * -line.draw_y.start;
		line.draw_y.start = 0;
	}
	line.draw_y.end = ft_min(line.draw_y.end, WIN_SIZE_Y);
	while (line.draw_y.start < line.draw_y.end)
	{
		// if (line.scale_x > 0.997)
		// 	printf("th = %d\n", (int)(line.scale_z * line.th));
		while (line.scale_z >= 1)
			line.scale_z -= 1;
		put_pixel(d->p_screen, (SDL_Point){line.x, (int)line.draw_y.start}, (t_size){WIN_SIZE_X, WIN_SIZE_Y}, line.text[tx + (int)(line.scale_z * line.th) * line.tw]);
		line.draw_y.start++;
		line.scale_z += line.scale_z_step;
	}
}

void draw_wall_lines(t_data *d, t_proj_wall wall)
{
	t_frange	draw_y;
	t_range		draw_x;
	t_frange	step_y;
	float		step_step_scale_z;
	float		step_wall_height;
	float		scale_x_step;
	int			diff_x;
	float		wall_height;
	SDL_Surface	*text;

	t_draw_line	line;

	text = d->texture[wall.wall.texture_id];
	line.text = (unsigned int*)text->pixels;
	line.tw = text->w;
	line.th = text->h;
	sort_int(&wall.p1.screen_x, &wall.p2.screen_x);
	diff_x = wall.p2.screen_x - wall.p1.screen_x;
	line.x = wall.p1.screen_x;
	line.draw_y = calc_wall_draw_range(d, wall.p1.dist, (t_frange){wall.wall.p1_z_start, wall.wall.p1_z_start + wall.wall.p1_z_size});
	step_y = calc_wall_draw_range(d, wall.p2.dist, (t_frange){wall.wall.p2_z_start, wall.wall.p2_z_start + wall.wall.p2_z_size});
	step_y.start = (step_y.start - line.draw_y.start) / diff_x;
	step_y.end = (step_y.end - line.draw_y.end) / diff_x;
	scale_x_step = wall.wall.length / diff_x;
	step_wall_height = (wall.wall.p2_z_size - wall.wall.p1_z_size) / diff_x;
	wall_height = wall.wall.p1_z_size;
	line.scale_x = 0;
	if (line.x < 0)
	{
		line.draw_y.start += step_y.start * -line.x;
		line.draw_y.end += step_y.end * -line.x;
		line.scale_x += scale_x_step * -line.x;
		line.x = 0;
	}
	wall.p2.screen_x = ft_min(wall.p2.screen_x, WIN_SIZE_X);
	line.scale_z = 0;
	//printf("draw x range : %i,%i\n", line.x, wall.p2.screen_x);
	while (line.x < wall.p2.screen_x)
	{
			//printf("p1.x : %d\n", point1.screen_x);
		line.scale_z_step = wall_height / (line.draw_y.end - line.draw_y.start);
		draw_vert_line(d, line);
		line.draw_y.start += step_y.start;
		line.draw_y.end += step_y.end;
		//printf("scale_x = %f\n", line.scale_x);
		line.scale_x += scale_x_step;
		wall_height += step_wall_height;
		while (line.scale_x >= 1)
			line.scale_x -= 1;
		line.x++;
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
	point1.scale_x = 0;
	point2.scale_x = wall.length;
	if (point1.on_screen && point2.on_screen)
		draw_wall_lines(d, (t_proj_wall){point1, point2, wall});
	//sort_proj_point_x(&point1, &point2);
	// step_dist = (point2.dist - point1.dist) / (point2.screen_x - point1.screen_x);
	// printf("dist : p1 = %f, p2 = %f\n", point1.dist, point2.dist);
		//printf("p1.x : %d, p2.X : %d\n", point1.screen_x, point2.screen_x);
	// draw_y = calc_wall_draw_range(d, point1.dist);
	// step_y = calc_wall_draw_range(d, point2.dist);
	// diff_x = point2.screen_x - point1.screen_x;
	// step_y.start = (step_y.start - draw_y.start) / diff_x;
	// step_y.end = (step_y.end - draw_y.end) / diff_x;
	// if (point1.on_screen && point2.on_screen)
	// {
	// 	while (point1.screen_x < point2.screen_x)
	// 	{
	// 		//printf("p1.x : %d\n", point1.screen_x);
	// 		draw_vert_line(d, point1.screen_x, draw_y);
	// 		point1.screen_x++;
	// 		draw_y.start += step_y.start;
	// 		draw_y.end += step_y.end;
	// 	}
	// }

	// draw_point(d, point_x_on_screen(d, wall.p1_f, d->rot, d->player_pos));
	// draw_point(d, point_x_on_screen(d, wall.p2_f, d->rot, d->player_pos));

}

void print_walls(t_data *d)
{
	int i;

	i = 0;
	while (i < d->map.wall_count)
		print_wall(d, d->map.wall_list[i++]);
}

void print_prop(t_data *d, t_props *prop)
{
	t_proj_point proj;
	t_frange		draw_y;

	proj = point_x_on_screen(d, prop->pos, d->rot, d->player_pos);
	if (proj.on_screen == 1)
	{
		draw_y = calc_prop_draw_range(d, proj.dist, 0, 1);
		while (draw_y.start < draw_y.end)
		{
			put_pixel(d->p_screen, (SDL_Point){proj.screen_x, draw_y.start}, (t_size){WIN_SIZE_X,WIN_SIZE_Y}, 0xAA88BBFF);
		}
	}
}