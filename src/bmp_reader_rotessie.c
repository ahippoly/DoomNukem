#include "proto_global.h"
#include "bmp.h"

int	ft_short(unsigned char *nb)
{
	return ((nb[0] << 8) | (nb[1]));
}

int	ft_int(unsigned char *nb)
{
	return ((nb[0] << 24) | (nb[1] << 16) | (nb[2] << 8) | (nb[3]));
}

uint16_t	swap2(uint16_t x)
{
	return ((x >> 8) | (x << 8));
}

uint32_t	swap4(uint32_t x)
{
	uint32_t	n1;
	uint32_t	n2;

	n1 = ((x >> 24) & 0xFF) | ((x << 8) & 0xFF0000);
	n2 = ((x >> 8) & 0xFF00) | ((x << 24) & 0xFF000000);
	return (n1 | n2);
}

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

int	check_size(uint32_t *size, uint8_t *buff)
{
	return (((*size = swap4(ft_int(buff))) >= 16842752u) ? 1 : 0);
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

void		set_file(t_file *file)
{
	ft_bzero(file, sizeof(t_file));
	ft_bzero(&file->info, sizeof(t_info));
	ft_bzero(&file->info.bmp, sizeof(t_hdr));
	ft_bzero(&file->info.dib, sizeof(t_dib));
	ft_bzero(&file->info.dib.dpi, sizeof(t_vec));
	ft_bzero(&file->info.dib.res, sizeof(t_vec));
}

static int	check_file(t_file *file, char *bmp, uint8_t *buffer)
{
	int			fd;
	int			size;

	if ((fd = open(bmp, O_RDONLY)) < 0)
		exit_with_msg("BMP file error : error opening file\n");		
	if ((size = read(fd, buffer, BUFFER_SIZE)) < 0)
		exit_with_msg("BMP file error : error reading file\n");		
	if (size < BUFFER_SIZE)
		exit_with_msg("BMP file error : incorrect file signature\n");		
	if (check_size(&file->info.bmp.weight, buffer + 2))
		exit_with_msg("BMP file error : file is too large\n");		
	if (!(file->stream = (uint8_t*)malloc(file->info.bmp.weight)))
		exit_with_msg("BMP file error : error with malloc\n");		
	if (lseek(fd, 0, SEEK_SET) < 0)
		exit_with_msg("BMP file error : file offset issue\n");		
	if ((read(fd, file->stream, file->info.bmp.weight)) < 0)
		exit_with_msg("BMP file error : error reading file\n");		
	if (close(fd))
		exit_with_msg("BMP file error : error closing file\n");		
	return (0);
}

void	load_bmp(t_file *file, t_img *image)
{
	ft_bzero(image, sizeof(t_img));
	image->w = file->info.dib.res.x;
	image->h = file->info.dib.res.y;
	image->pixels = file->pixels;
}

static int	parse_bmp(t_file *file, t_img *image)
{
	if ((file->info.error = check_header(file)))
		return (file->info.error);
	set_info(&file->info);
	if (!(file->pixels = (uint32_t*)malloc(file->info.memory)))
		exit_with_msg("BMP file error : error with malloc\n");		
	make_img(file, file->stream + file->info.bmp.offset, file->info);
	load_bmp(file, image);
	return (0);
}

void	clean_file(t_file *file)
{
	if (file->stream)
		free(file->stream);
}

void		bmp_reader(char *bmp, t_img *img)
{
	t_file		file;
	uint8_t		buff[BUFFER_SIZE];

	set_file(&file);
	if ((file.info.error = check_file(&file, bmp, buff)))
		clean_file(&file);
	else
	{
		parse_bmp(&file, img);
		clean_file(&file);
	}
}