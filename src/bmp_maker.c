#include "proto_global.h"
#include "bmp.h"

static uint32_t	make_pixel(uint8_t *stream)
{
	return ((stream[2] << 16) | (stream[1] << 8) | stream[0]);
}

void			make_img(t_file *file, uint8_t *stream, t_info info)
{
	int			y;
	int			i;
	uint32_t	x;
	uint32_t	px;

	y = info.dib.res.y;
	x = 0;
	while (--y >= 0)
	{
		x = 0;
		i = 0;
		while (x < info.row)
		{
			px = make_pixel(stream + x + y * info.scanline);
			file->pixels[(info.dib.res.y - y - 1) * info.dib.res.x + i++] = px;
			x += info.bytes;
		}
	}
}