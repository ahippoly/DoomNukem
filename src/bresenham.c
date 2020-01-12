#include "global_header.h"
#include "bresenham.h"

void	oct_ini(t_oct *oct, SDL_Point pos1, SDL_Point pos2, int pos[2][2])
{
	pos[0][0] = pos1.x;
	pos[0][1] = pos2.x;
	pos[1][0] = pos1.y;
	pos[1][1] = pos2.y;
	oct->inc[0] = pos2.x - pos1.x > 0 ? 1 : -1;
	oct->inc[1] = pos2.y - pos1.y > 0 ? 1 : -1;
	oct->d[0] = (pos2.x - pos1.x) * 2 * oct->inc[0];
	oct->d[1] = (pos2.y - pos1.y) * 2 * oct->inc[1];
	oct->bool = oct->d[0] > oct->d[1] ? 1 : 0;
	oct->boolxy = 1 - oct->bool;
	oct->e = oct->d[oct->boolxy] / 2;
	oct->ecart = (pos[oct->boolxy][1] - pos[oct->boolxy][0])
		* oct->inc[oct->boolxy];
}


void	octant(SDL_Point pos1, SDL_Point pos2, char *pixel, int color)
{
	t_oct			oct;
	int				pos[2][2];
	int				i;
	unsigned int	*p_tab;
	int 			length;

	if (pos1.x != -42 && pos2.x != -42
		&& pos1.x != -2147483648
		&& pos2.x != -2147483648
		&& pos1.y != -2147483648
		&& pos2.y != -2147483648)
	{
		p_tab = (unsigned int*)pixel;
		i = 0;
		oct_ini(&oct, pos1, pos2, pos);
		if (oct.bool == 0)
			length = ft_min(WIN_SIZE_X, ft_abs(pos[oct.boolxy][0] - pos[oct.boolxy][1]));
		else
			length = ft_min(WIN_SIZE_Y, ft_abs(pos[oct.boolxy][0] - pos[oct.boolxy][1]));
		//printf("pixels drawed = %i\n", length);
		while (i < length)
		{
			if (pos[0][0] < WIN_SIZE_X && pos[0][0] > 0 && pos[1][0] > 0
				&& pos[1][0] < WIN_SIZE_Y)
			p_tab[pos[0][0] + pos[1][0] * WIN_SIZE_X] = color;
		//	if (forced_side != 0)
		//		printf("oct.e = %d\n",oct.e);
			oct.e -= oct.d[oct.bool];
			while (oct.e <= 0)
			{
				pos[oct.bool][0] += oct.inc[oct.bool];
				oct.e += oct.d[oct.boolxy];
			}
			i++;
			pos[oct.boolxy][0] += oct.inc[oct.boolxy];
		}
		//printf("octant line length = %d \n", length);
		if (pos[0][0] < WIN_SIZE_X && pos[0][0] > 0 && pos[1][0] > 0
				&& pos[1][0] < WIN_SIZE_Y)
			p_tab[pos[0][0] + pos[1][0] * WIN_SIZE_X] = color;
	}
}