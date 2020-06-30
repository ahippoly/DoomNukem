#include "proto_global.h"

uint8_t		padding(t_dib dib)
{
	return ((dib.raw - (dib.res.x * dib.res.y * (dib.bpp / 8))) / dib.res.y);
}

uint32_t	scanline(t_dib dib, uint8_t padding)
{
	return (dib.res.x * (dib.bpp / 8) + padding);
}

uint32_t	memory(t_dib dib)
{
	return (dib.res.x * dib.res.y * sizeof(uint32_t));
}

void		set_info(t_info *info)
{
	info->padding = padding(info->dib);
	info->scanline = scanline(info->dib, info->padding);
	info->bytes = info->dib.bpp / 8;
	info->row = info->scanline - info->padding;
	info->memory = memory(info->dib);
}

int	check_header(t_file *file)
{
	file->info.bmp.offset = swap4(ft_int(file->stream + 10));
	file->info.dib.size = swap4(ft_int(file->stream + 14));
	if (!(file->info.dib.res.x = swap4(ft_int(file->stream + 18)))
		|| !(file->info.dib.res.y = swap4(ft_int(file->stream + 22))))
		exit_with_msg("BMP file error : resolution issue\n");		
	file->info.dib.planes = swap2(ft_short(file->stream + 26));
	if ((file->info.dib.bpp = swap2(ft_short(file->stream + 28))) != 24)
		exit_with_msg("BMP file error : 24bits image expected\n");		
	if ((file->info.dib.compression = swap4(ft_int(file->stream + 30))))
		exit_with_msg("BMP file error : compression not supported\n");		
	if (((file->info.dib.raw = swap4(ft_int(file->stream + 34))) % 4))
		exit_with_msg("BMP file error : padding issue\n");		
	file->info.dib.dpi.x = swap4(ft_int(file->stream + 38));
	file->info.dib.dpi.y = swap4(ft_int(file->stream + 42));
	file->info.dib.colors = swap4(ft_int(file->stream + 46));
	file->info.dib.important = swap4(ft_int(file->stream + 50));
	return (0);
}