#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

void	raycast_screen(t_data *d, t_range screen_x, double start_angle, double step)
{
	int i;
	t_calced_walls sorted_walls[NB_WALL_MAX];

	start_angle += step * screen_x.start;
	while (screen_x.start < screen_x.end)
    {
        i = 0;
        sort_walls_by_dist(d, &d->map, start_angle, sorted_walls);
        while (i < d->map.wall_count)
            draw_vertical_line(d, screen_x.start, sorted_walls[i++]);
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
    double fov_coef = ((double)FOV_ANGLE / 90) * M_PI_2;
    double start = d->rot - fov_coef / 2;
    double step = fov_coef / WIN_SIZE_X;
    int i;

    i = 0;
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
    double fov_coef = ((double)FOV_ANGLE / 90) * M_PI_2;
    double current_angle = d->rot - fov_coef / 2;
    double step = fov_coef / WIN_SIZE_X;
    int x;
    int i;
	t_calced_walls sorted_walls[NB_WALL_MAX];

    x = 0;
    while (x < WIN_SIZE_X)
    {
        i = 0;
        sort_walls_by_dist(d, map, current_angle, sorted_walls);
        while (i < map->wall_count)
            draw_vertical_line(d, x, sorted_walls[i++]);
        //draw_vertical_line(d, x, check_intersect_with_all_wall(d, map, current_angle, d->rot), d->texture[0]);
        current_angle += step;
        x++;
    }
}