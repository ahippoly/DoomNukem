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


void	octant(SDL_Point pos1, SDL_Point pos2, unsigned int *pixel, int color, SDL_Rect pos_size)
{
	t_oct			oct;
	int				pos[2][2];
	int				i;
	unsigned int	*p_tab;
	int 			length;

	if (pos1.x != -42 && pos2.x != -42)
	{
		p_tab = pixel;
		i = 0;
		oct_ini(&oct, pos1, pos2, pos);
		if (oct.bool == 0)
			length = ft_min(pos_size.w, ft_abs(pos[oct.boolxy][0] - pos[oct.boolxy][1]));
		else
			length = ft_min(pos_size.h, ft_abs(pos[oct.boolxy][0] - pos[oct.boolxy][1]));
		while (i < length)
		{
			if (pos[0][0] < pos_size.w && pos[0][0] > 0 && pos[1][0] > 0
				&& pos[1][0] < pos_size.h)
			p_tab[pos[0][0] + pos[1][0] * pos_size.w] = color;
			oct.e -= oct.d[oct.bool];
			while (oct.e <= 0)
			{
				pos[oct.bool][0] += oct.inc[oct.bool];
				oct.e += oct.d[oct.boolxy];
			}
			i++;
			pos[oct.boolxy][0] += oct.inc[oct.boolxy];
		}
	}
}