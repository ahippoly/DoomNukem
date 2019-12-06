/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 05:02:25 by ahippoly          #+#    #+#             */
/*   Updated: 2019/04/07 23:39:52 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_line load_corner(t_var *v, int i, int j)
{
	SDL_Point pos;
	SDL_Point size;
	SDL_Point pos2;
	SDL_Point size2;
	SDL_Point win_size;
	t_pos diff;
	t_pos diff2;
	double width;
	double width2;
	double depth;
	double start;
	double diffx_distance;
	double diffy_screenpos;
	SDL_Point endray;
    SDL_Point startray;
    SDL_Point perso_pos;
	t_line ret;
	int half_screen;

	size.x = 3;
	size.y = 3;
	pos2.x = 0;
	pos2.y = 0;
	size2.x = 2;
	size2.y = 90;

	ret.pos1.x = -10000;
	ret.pos2.x = 0;
	ret.pos1.y = 0;
	ret.pos2.y = 0;

	half_screen = WIN_SIZE / 2;

	diff.x = i - v->perso_pos.x;
	diff.y = j - v->perso_pos.y;
	depth = (diff.x * sin((v->rot) * M_PI_2) + diff.y * cos((v->rot) * M_PI_2));
	diffx_distance = depth 
		//* cos(M_PI_4); 
		//* sin(v->fov); 
		* v->fov;
	diffy_screenpos = (diff.y * sin((v->rot) * M_PI_2)) - (diff.x * cos((v->rot) * M_PI_2));
	pos.x = i * MINI_MAP_W / (v->map_size.x) +  MINI_MAP_X;
	pos.y = j * MINI_MAP_H / (v->map_size.y) +  MINI_MAP_Y;
	width2 = depth * 2 * sin(v->fov * M_PI_2);
	width = depth * 2 
		//* sin(M_PI_4);
		//* sin(v->fov); 
		* v->fov;
	start = diffy_screenpos + diffx_distance;
	printf("i = %i, j = %i\n",i , j);
	printf("posx = %i , posy = %i\n",pos.x, pos.y);
	printf("diffx = %f, diffy = %f\n",diff.x, diff.y);
//	printf("diffx_distance = %f\n", diffx_distance);
	printf("diffy_screenpos = %f\n", diffy_screenpos);
//              printf("diff_layer calc = %f\n",  sin( M_PI_2));
	printf("diffx_distance = %f, width = %f\n", diffx_distance, width);
	printf("         dist2 = %f, width2 = %f\n", depth * cos(v->fov * M_PI_2),width2);
	printf("start = %f\n", start);
//	printf("start = %f\n", diffx_distance);
/*	endray.x =  pos.x + 100 * cos((v->rot) * M_PI_2);
	endray.y =  pos.y + 100 * -sin((v->rot) * M_PI_2);
	startray.x =  pos.x + 100 * -cos((v->rot) * M_PI_2);
	startray.y =  pos.y + 100 * sin((v->rot) * M_PI_2);
	octant(startray, endray, v->p_tab, 0xff00aa00);
*/
//////////////////////////////////////////////////////  Display CALC

	if (start > 0 && start < width )
	{
		pos2.x = start * WIN_SIZE / width;
		//pos2.y = WIN_SIZE / 2 - 200 / (diffx_distance * 0.5);
		//size2.y = 300 / (diffx_distance * 0.5);
		pos2.y = half_screen - (half_screen / diffx_distance) * v->z_pos;
		size2.y = half_screen / (diffx_distance);
		ret.pos1.x = pos2.x;
		ret.pos1.y = pos2.y;
		ret.pos2.x = pos2.x;
		ret.pos2.y = pos2.y + size2.y;
		put_rect(v->p_tab, pos2, size2, 0xffffffff, v->win_size);
		put_rect(v->p_tab, pos, size, 0xffffffff, v->win_size);
	}
	return (ret);
}

void load_wall(t_var *v)
{
	int i;
	int j;
	t_line wall_hight_tmp;
	t_line wall_hight;
	t_line wall_hight2;

	i = 0;
	while (i < v->map_size.x)
	{
		j = 0;
		while (j < v->map_size.y)
		{
			//printf("i = %i , j = %i\n",i,j);
			if (v->map[j][i] > 0)
			{
				wall_hight = load_corner(v , i , j);
				wall_hight_tmp = wall_hight;
				wall_hight2 = load_corner(v , i+1 , j);
				if (wall_hight.pos1.x != -10000 && wall_hight2.pos1.x != -10000)
				{
					octant(wall_hight.pos1, wall_hight2.pos1, v->p_tab, 0xff00ffff);
					octant(wall_hight.pos2, wall_hight2.pos2, v->p_tab, 0xff00ffff);
				}
				wall_hight = load_corner(v , i+1 , j+1);
				if (wall_hight.pos1.x != -10000 && wall_hight2.pos1.x != -10000)
				{
					octant(wall_hight.pos1, wall_hight2.pos1, v->p_tab, 0xff00ffff);
					octant(wall_hight.pos2, wall_hight2.pos2, v->p_tab, 0xff00ffff);
				}	
				wall_hight2 = load_corner(v , i , j+1);
				if (wall_hight.pos1.x != -10000 && wall_hight2.pos1.x != -10000)
				{
					octant(wall_hight.pos1, wall_hight2.pos1, v->p_tab, 0xff00ffff);
					octant(wall_hight.pos2, wall_hight2.pos2, v->p_tab, 0xff00ffff);
				}
				if (wall_hight_tmp.pos1.x != -10000 && wall_hight2.pos1.x != -10000)
				{
					octant(wall_hight_tmp.pos1, wall_hight2.pos1, v->p_tab, 0xff00ffff);
					octant(wall_hight_tmp.pos2, wall_hight2.pos2, v->p_tab, 0xff00ffff);
				}
			}
			j++;
		}
		i++;
	}
}
