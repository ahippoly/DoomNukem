/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object3D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:20:27 by ahippoly          #+#    #+#             */
/*   Updated: 2019/04/09 16:36:29 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void load_triangle1_plane(t_var *v, int x, int y, int z , t_point corner[4])
{
    SDL_Point point;
    SDL_Point point2;

    corner[0] = load_corner(v, x , y , z);
    corner[1] = load_corner(v, x + 1, y , z);
    corner[2] = load_corner(v, x , y + 1 , z);

    octant(corner[0], corner[1], v->p_tab, 0xff00ffff, 0);
    octant(corner[0], corner[2], v->p_tab, 0xff00ffff, 0);
    octant(corner[1], corner[2], v->p_tab, 0xff00ffff, 0);
}

void load_triangle2_plane(t_var *v, int x, int y, int z , t_point corner[4])
{
    SDL_Point point;
    SDL_Point point2;

    corner[0] = load_corner(v, x , y , z);
    corner[1] = load_corner(v, x + 1, y , z);
    corner[2] = load_corner(v, x + 1 , y + 1 , z);

    octant(corner[0], corner[1], v->p_tab, 0xff00ffff, 0);
    octant(corner[0], corner[2], v->p_tab, 0xff00ffff, 0);
    octant(corner[1], corner[2], v->p_tab, 0xff00ffff, 0);
}

void load_triangle3_plane(t_var *v, int x, int y, int z , t_point corner[4])
{
    SDL_Point point;
    SDL_Point point2;

    corner[0] = load_corner(v, x , y , z);
    corner[1] = load_corner(v, x , y + 1 , z);
    corner[2] = load_corner(v, x + 1 , y + 1 , z);

    octant(corner[0], corner[1], v->p_tab, 0xff00ffff, 0);
    octant(corner[0], corner[2], v->p_tab, 0xff00ffff, 0);
    octant(corner[1], corner[2], v->p_tab, 0xff00ffff, 0);
}

void load_triangle4_plane(t_var *v, int x, int y, int z , t_point corner[4])
{
    SDL_Point point;
    SDL_Point point2;

    corner[0] = load_corner(v, x + 1 , y , z);
    corner[1] = load_corner(v, x + 1, y + 1 , z);
    corner[2] = load_corner(v, x , y + 1 , z);

    octant(corner[0], corner[1], v->p_tab, 0xff00ffff, 0);
    octant(corner[0], corner[2], v->p_tab, 0xff00ffff, 0);
    octant(corner[1], corner[2], v->p_tab, 0xff00ffff, 0);
}

void load_triangle_point(t_var *v, int x, int y, int z, int rot)
{
    t_point upcorner[3];
    t_point downcorner[3];
    t_point point;
    t_point point2;

	if (rot == 1)
	{
		load_triangle1_plane(v, x, y, z, upcorner);
		load_triangle1_plane(v, x, y, z - 1, downcorner);
	}
	else if (rot == 2)
	{
		load_triangle2_plane(v, x, y, z, upcorner);
		load_triangle2_plane(v, x, y, z - 1, downcorner);
	}
	else if (rot == 3)
	{
		load_triangle3_plane(v, x, y, z, upcorner);
		load_triangle3_plane(v, x, y, z - 1, downcorner);
	}
	else if (rot == 4)
	{
		load_triangle4_plane(v, x, y, z, upcorner);
		load_triangle4_plane(v, x, y, z - 1, downcorner);
	}

    octant(downcorner[0], upcorner[0], v->p_tab, 0xff00ffff, 0);
    octant(downcorner[1], upcorner[1], v->p_tab, 0xff00ffff, 0);
    octant(downcorner[2], upcorner[2], v->p_tab, 0xff00ffff, 0);
}
