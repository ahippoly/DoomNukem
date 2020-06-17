#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

t_range calc_floor_draw_range(t_data *d, t_calced_walls origin, t_calced_walls next)
{
	t_range	draw;

	draw.start = ft_max(d->screen_height + ((d->player_height - d->map.room_list[origin.wall.room_id_ref].z_ground) * WIN_SIZE_Y) / origin.dist, 0);
	draw.end = ft_min(d->screen_height + ((d->player_height - d->map.room_list[origin.wall.room_id_ref].z_ground) * WIN_SIZE_Y) / next.dist, WIN_SIZE_Y);
	return (draw);
}

t_range calc_floor_draw_range_end(t_data *d, t_calced_walls origin)
{
	t_range	draw;

	draw.start = ft_max(d->screen_height + ((d->player_height - d->map.room_list[origin.wall.room_id_ref].z_ground) * WIN_SIZE_Y) / origin.dist, 0);
	draw.end = WIN_SIZE_Y;
	return (draw);
}

void draw_floor_line(t_data *d, t_range draw, int x, int room_id)
{
	int color;

	if (room_id == 0)
		color = 0xFF0000FF;
	if (room_id == 1)
		color = 0xFFF00FFF;
	if (room_id == 2)
		color = 0x00FFFFFF;
	if (room_id == 3)
		color = 0x0000FFFF;
	draw.start *= WIN_SIZE_X;
	draw.end *= WIN_SIZE_X;
	while (draw.start < draw.end)
	{
		d->p_screen[x + draw.start] = color;
		draw.start += WIN_SIZE_X;
	}
}

void draw_floor(t_data *d, SDL_Surface *text)
{
    int x;
    int y;
    int p;

    float fov_coef = (float)FOV_ANGLE / 90;
    

    float ray_dir_x0;
    float ray_dir_y0;
    float ray_dir_x1;
    float ray_dir_y1;


    float pos_z;

    float rowDistance;

    float floorStepX;
    float floorStepY;

    float floorX;
    float floorY;
	t_point floor;

    int tx;
    int ty;

    int text_acces_pos;

    int *pixels;

    ray_dir_x0 = cos(d->rot) + d->fov * sin(d->rot);
    ray_dir_x1 = cos(d->rot) - d->fov * sin(d->rot);
    ray_dir_y0 = sin(d->rot) - d->fov * cos(d->rot);
    ray_dir_y1 = sin(d->rot) + d->fov * cos(d->rot);
    // printf("raydir: 0 : %f,%f ; 1 : %f,%f\n", ray_dir_x0, ray_dir_y0, ray_dir_x1, ray_dir_y1);
    y = d->screen_height + 1;
    pos_z = (d->player_height - DEFAULT_Z_GROUND ) * WIN_SIZE_Y;

    pixels = (int*)text->pixels;
    

    // real world coordinates of the leftmost column. This will be updated as we step to the right.
    
    while (y < WIN_SIZE_Y)
    {
        p = y - d->screen_height;
        rowDistance = pos_z / p;
        // printf("Pos_z = %f, p = %d, rowDistance = %f\n", pos_z, p, rowDistance);

        floorStepX = rowDistance * (ray_dir_x1 - ray_dir_x0) / WIN_SIZE_X;
        floorStepY = rowDistance * (ray_dir_y1 - ray_dir_y0) / WIN_SIZE_X;

        floorX = (d->player_pos.x + rowDistance * ray_dir_x0);
        floorY = (d->player_pos.y + rowDistance * ray_dir_y0);
		floor.x = (d->player_pos.x + rowDistance * ray_dir_x0);
        floor.y = (d->player_pos.y + rowDistance * ray_dir_y0);
        x = 0;
        // printf("floor: %f,%f\n", floorX, floorY);
        // printf("floorSTEP : %f,%f\n", floorStepX, floorStepY);

        while (x < WIN_SIZE_X)
        {


      
        // get the texture coordinate from the fractional part
        // floorX = fabs(floorX);
        // floorY = fabs(floorY);
        

        floorX = floor.x + floorStepX * x;
        floorY = floor.y + floorStepY * x;

        text_acces_pos = ((int)(get_float_part(floorX) * text->w) & (text->w - 1)) + ((int)(get_float_part(floorY) * text->h) & (text->h - 1)) * text->w;
        // floorX += floorStepX;
        // floorY += floorStepY;

     
        // printf("tx = %d, ty = %d, ty2 = %d\n", (int)(get_float_part(floorX) * text->w), (int)(get_float_part(floorY) * text->h) * text->w, (int)(get_float_part(floorY) * text->h * text->w));
        // printf("x scale = %f, y scale = %f\n", get_float_part(floorX), get_float_part(floorY));
        put_pixel(d->p_screen, create_point(x, y), create_t_size(WIN_SIZE_X, WIN_SIZE_Y), pixels[text_acces_pos]);
        x++;
      }
      y++;
    }
}

void draw_floor2(t_data *d, t_floor *fl, double height)
{
    int y;
    float pos_z;
    float row_dist;
	t_point ray_dir0;
	t_point ray_dir1;
	t_point ray_diff;

    ray_dir0.x = cos(d->rot) + d->fov * sin(d->rot);
    ray_dir1.x = cos(d->rot) - d->fov * sin(d->rot);
    ray_dir0.y = sin(d->rot) - d->fov * cos(d->rot);
    ray_dir1.y = sin(d->rot) + d->fov * cos(d->rot);
    pos_z = (d->player_height - height) * WIN_SIZE_Y;
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

void print_floor_slice2(t_data *d, int x, t_range y, float current_angle)
{
	t_point ray_dir;
	float	row_dist;
	float	pos_z;

	pos_z = d->z_pos;
	ray_dir.x = cos(d->rot) + current_angle * sin(d->rot);
    ray_dir.y = sin(d->rot) - current_angle * cos(d->rot);
	while (y.start < WIN_SIZE_Y)
    {
        row_dist = pos_z / (y.start - d->screen_height);
        // printf("Pos_z = %f, p = %d, rowDistance = %f\n", pos_z, p, rowDistance);

		// floor.x = (d->player_pos.x + rowDistance * ray_dir_x0);
        // floor.y = (d->player_pos.y + rowDistance * ray_dir_y0);
        x = 0;
        // printf("floor: %f,%f\n", floorX, floorY);
        // printf("floorSTEP : %f,%f\n", floorStepX, floorStepY);
	}
}

void init_floor(t_data *d, t_floor *fl)
{
    int y;
    float pos_z;
    float row_dist;
	t_point ray_dir0;
	t_point ray_dir1;
	t_point ray_diff;

    ray_dir0.x = cos(d->rot) + d->fov * sin(d->rot);
    ray_dir1.x = cos(d->rot) - d->fov * sin(d->rot);
    ray_dir0.y = sin(d->rot) - d->fov * cos(d->rot);
    ray_dir1.y = sin(d->rot) + d->fov * cos(d->rot);
    pos_z = (d->player_height - DEFAULT_Z_GROUND) * WIN_SIZE_Y;
	ray_diff.x = ray_dir1.x - ray_dir0.x;
	ray_diff.y = ray_dir1.y - ray_dir0.y;
    y = d->screen_height + 1;
    while (y < WIN_SIZE_Y)
    {
		row_dist = pos_z / (y - d->screen_height);

		fl[y].floor_step.x = row_dist * ray_diff.x / WIN_SIZE_X;
		fl[y].floor_step.x = row_dist * ray_diff.y / WIN_SIZE_X;

        fl[y].floor.x = (d->player_pos.x + row_dist * ray_dir0.x);
        fl[y].floor.y = (d->player_pos.y + row_dist * ray_dir0.y);
    	y++;
    }
}

void	init_floors(t_data *d)
{
	int i;

	i = 0;
	while (i < d->map.room_count)
	{
		draw_floor2(d, d->fl[i], d->map.room_list[i].z_ground);
		//init_floor(d, d->fl[i]);
		i++;
	}
}

void print_floor(t_data *d)
{
	int i;

	i = 0;
	while (i < WIN_SIZE_Y)
	{
		printf("floor : %f,%f, fl_step : %f,%f\n", d->fl[0][i].floor.x, d->fl[0][i].floor.y, d->fl[0][i].floor_step.x, d->fl[0][i].floor_step.y);
		i++;
	}
}

void	print_floor_slice(t_data *d, t_floor *fl, int x, t_range y, int text_id)
{
	t_size t_max;
	t_range draw_y;
	t_floor current;
	SDL_Surface *text;
	unsigned int	*pixels;

	text = d->texture[1];
	t_max.w = text->w - 1;
	t_max.h = text->h - 1;
	draw_y.start = y.start * WIN_SIZE_X;
	draw_y.end = y.end * WIN_SIZE_X;
	pixels = (unsigned int*)text->pixels;
	//printf("y = %i, floor_step : %f,%f, floor : %f,%f\n", y.start, fl[y.start].floor_step.x, fl[y.start].floor_step.y, fl[y.start].floor.x, fl[y.start].floor.y);
	while (draw_y.start < draw_y.end)
	{
		current = fl[y.start];
		d->p_screen[x + draw_y.start] = pixels[((int)(get_float_part(current.floor.x + current.floor_step.x * x) * text->w) & t_max.w) + ((int)(get_float_part(current.floor.y + current.floor_step.y * x) * text->h) & t_max.h) * text->w];
		//d->p_screen[x + draw_y.start] = pixels[((int)(get_float_part(current.floor.x) * text->w) & t_max.w) + ((int)(get_float_part(current.floor.y) * text->h) & t_max.h) * text->w];
		//d->p_screen[x + draw_y.start] = 0xDD88CCFF;
		draw_y.start += WIN_SIZE_X;
		y.start++;
	}
}

void draw_all_floor_slice(t_data *d)
{
	int x;
	int y;

	init_floors(d);
	x = 0;
		while (x < WIN_SIZE_X)
		{
			print_floor_slice(d, d->fl[0], x, (t_range){d->screen_height - 1, WIN_SIZE_Y}, 0);
			x++;
		}
}