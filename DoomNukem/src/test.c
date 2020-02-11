#include "../includes/wolf3d.h"

t_map	*create_wall(int *a, int *b)
{
	t_map *tmp;

	if (!(tmp = (t_map *)malloc(sizeof(t_map))))
		exit (0);
	tmp->wall.point_a.x = a[0];
	tmp->wall.point_a.y = a[1];
	tmp->wall.point_b.x = b[0];
	tmp->wall.point_b.y = b[1];
	tmp->next = NULL;
	return (tmp);
}

void map_build(t_map **list, int *a, int *b)
{
	t_map	*new;

	new = create_wall(a, b);
	new->next = *list;
	*list = new;
}

void     map_drawer(t_enval *e)
{
    int i;

    i = -1;
    // printf("TEST1");
	if (!(e->tabint = (int **)malloc(sizeof(int *) * 7)))
		exit(0);
	while (++i < 7)
		if (!(e->tabint[i] = malloc(sizeof(int) * 2)))
			exit(0);
	i = 0;

	// premiere salle
	e->tabint[0][0] = 300;
	e->tabint[0][1] = 200;
	e->tabint[1][0] = 400;
	e->tabint[1][1] = 200;
	e->tabint[2][0] = 600;
	e->tabint[2][1] = 600;
	e->tabint[3][0] = 200;
	e->tabint[3][1] = 400;
	e->tabint[4][0] = 200;
	e->tabint[4][1] = 200;
	e->tabint[5][0] = 200;
	e->tabint[5][1] = 100;
	e->tabint[6][0] = 400;
	e->tabint[6][1] = 100;
	//deuxieme salle
	// e->tabint[4][0] = 400;
	// e->tabint[4][1] = 200;
	// e->tabint[5][0] = 600;
	// e->tabint[5][1] = 200;
	// e->tabint[6][0] = 600;
	// e->tabint[6][1] = 400;
	// e->tabint[7][0] = 400;
	// e->tabint[7][1] = 400;
}

void	test(t_enval *e)
{
	int i = -1;
	while (++i < 6)
	{
		map_build(&e->smap, e->tabint[i], e->tabint[i + 1]);
		printf("passage\n");
	}
	t_map	*tmp;
	tmp = e->smap;
	while (tmp)
	{
		printf("[%d %d][%d %d]\n", tmp->wall.point_a.x, tmp->wall.point_a.y, tmp->wall.point_b.x, tmp->wall.point_b.y);
		tmp = tmp->next;
	}
	tmp = e->smap;
}

int  raycaster(t_enval *e, t_map *map)
{
	double	den;
	double	t;
	double	u;
	double	ptx;
	double	pty;
	double	dist;

	den = (map->wall.point_a.x - map->wall.point_b.x) * (e->player.pos.y - (e->ray.dir.y + e->player.pos.y)) - (map->wall.point_a.y - map->wall.point_b.y) * (e->player.pos.x - (e->ray.dir.x + e->player.pos.x));
	if (den == 0)
		return (0);
	t = ((map->wall.point_a.x - e->player.pos.x) * (e->player.pos.y - (e->ray.dir.y + e->player.pos.y)) - (map->wall.point_a.y - e->player.pos.y) * (e->player.pos.x - (e->ray.dir.x + e->player.pos.x))) / den;
  	u = -((map->wall.point_a.x - map->wall.point_b.x) * (map->wall.point_a.y - e->player.pos.y) - (map->wall.point_a.y - map->wall.point_b.y) * (map->wall.point_a.x - e->player.pos.x)) / den;
	if (t > 0 && t < 1 && u > 0)
	{
		// printf("TRUE");
		ptx = map->wall.point_a.x + t * (map->wall.point_b.x - map->wall.point_a.x);
		pty = map->wall.point_a.y + t * (map->wall.point_b.y - map->wall.point_a.y);
		dist = sqrt(pow(ptx - e->player.pos.x, 2) + pow(pty - e->player.pos.y, 2));
		if (e->save.dist == 0 || dist < e->save.dist)
		{
			e->save.dist = dist * cos(e->ray.angle - e->player.angle); // SAUVEGARDE DE LA DISTANCE
			// printf("dist = %f\n", e->save.dist);
			e->save.x = ptx; // SAUVEGARDE LE POINT DE CONTACT
			e->save.y = pty; //
		}
		return(1);
  }
	return (0);
}