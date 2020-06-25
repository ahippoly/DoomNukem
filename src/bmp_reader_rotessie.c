#include "proto_global.h"

int	ft_short(unsigned char *nb)
{
	return ((nb[0] << 8) | (nb[1]));
}

int	ft_int(unsigned char *nb)
{
	return ((nb[0] << 24) | (nb[1] << 16) | (nb[2] << 8) | (nb[3]));
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

uint16_t	swap2(uint16_t x)
{
	return ((x >> 8) | (x << 8));
}

uint32_t	swap4(uint32_t x)
{
	uint32_t	n1;
	uint32_t	n2;

	n1 = ((x >> 24) & B3) | ((x << 8) & B1);
	n2 = ((x >> 8) & B2) | ((x << 24) & B0);
	return (n1 | n2);
}

void		setup_infos(t_info *info)
{
	info->padding = padding(info->dib);
	info->scanline = scanline(info->dib, info->padding);
	info->bytes = info->dib.bpp / 8;
	info->row = info->scanline - info->padding;
	info->memory = memory(info->dib);
}

static void	setup_errors(t_file *file)
{
	file->msg[0] = "";
	file->msg[1] = ")\n\t- Unable to open the given file.\n\0";
	file->msg[2] = ")\n\t- Unable to allocate memory.\n\0";
	file->msg[3] = ")\n\t- Unable to read the given file.\n\0";
	file->msg[4] = ")\n\t- File is too large (expected at most 16MiB).\n\0";
	file->msg[5] = ")\n\t- Unable to close the given file.\n\0";
	file->msg[6] = ")\n\t- Wrong file signature (expected 0x424D).\n\0";
	file->msg[7] = ")\n\t- Unable to reposition reading offset.\n\0";
	file->msg[8] = ")\n\t- DIB not supported (expected BITMAPV4HEADER).\n\0";
	file->msg[9] = ")\n\t- Bits per pixel not supported (expected 24bits).\n\0";
	file->msg[10] = ")\n\t- Compression method not supported (expected 0).\n\0";
	file->msg[11] = ")\n\t- Misformated header encountered.\n\0";
	file->msg[12] = ")\n\t- Wrong data offset (expected 122 Bytes).\n\0";
	file->msg[13] = ")\n\t- Null resolution found (expected at least 1px).\n\0";
	file->msg[14] = ")\n\t- Wrong scanline size (expected multiple of 4).\n\0";
}

void		presets(t_file *file)
{
	ft_bzero(file, sizeof(t_file));
	ft_bzero(file->msg, sizeof(char*));
	ft_bzero(&file->info, sizeof(t_info));
	ft_bzero(&file->info.bmp, sizeof(t_hdr));
	ft_bzero(&file->info.dib, sizeof(t_dib));
	ft_bzero(&file->info.dib.dpi, sizeof(t_vec));
	ft_bzero(&file->info.dib.res, sizeof(t_vec));
	setup_errors(file);
}

void	load_image(t_file *file, t_bmp *image)
{
	ft_bzero(image, sizeof(t_bmp));
	image->width = file->info.dib.res.x;
	image->height = file->info.dib.res.y;
	image->pixels = file->pixels;
}



int			dislay_output(t_file *file, uint32_t status)
{
	if (status)
	{
		ft_putstr("\033[31;1mError:\033[0m BMP Parser returned an error (");
		ft_putnbr(status);
		ft_putstr(file->msg[status]);
		return (status);
	}
	else
		return (BMP_OK);
}

static uint32_t	build_pixel(uint8_t *stream)
{
	return ((stream[2] << 16) | (stream[1] << 8) | stream[0]);
}

void			build_image(t_file *file, uint8_t *stream, t_info info)
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
			px = build_pixel(stream + x + y * info.scanline);
			file->pixels[(info.dib.res.y - y - 1) * info.dib.res.x + i++] = px;
			x += info.bytes;
		}
	}
}

int	check_signature(uint8_t *buffer)
{
	return ((ft_short(buffer) != BMP_SIGN) ? BMP_E_SIGNATURE : BMP_OK);
}

int	check_size(uint32_t *size, uint8_t *buff)
{
	return (((*size = swap4(ft_int(buff))) >= MAX_SIZE) ? BMP_E_SIZE : BMP_OK);
}

int	check_header(t_file *file)
{
	if ((file->info.bmp.offset = swap4(ft_int(file->stream + 10))) != BMP_SHIFT)
		return (BMP_E_OFFSET);
	if ((file->info.dib.size = swap4(ft_int(file->stream + 14))) != DIB_SIZE)
		return (BMP_E_DIB);
	if (!(file->info.dib.res.x = swap4(ft_int(file->stream + 18)))
		|| !(file->info.dib.res.y = swap4(ft_int(file->stream + 22))))
		return (BMP_E_RES);
	file->info.dib.planes = swap2(ft_short(file->stream + 26));
	if ((file->info.dib.bpp = swap2(ft_short(file->stream + 28))) != 24)
		return (BMP_E_BPP);
	if ((file->info.dib.compression = swap4(ft_int(file->stream + 30))))
		return (BMP_E_COMPRESSION);
	if (((file->info.dib.raw = swap4(ft_int(file->stream + 34))) % 4))
		return (BMP_E_PADDING);
	file->info.dib.dpi.x = swap4(ft_int(file->stream + 38));
	file->info.dib.dpi.y = swap4(ft_int(file->stream + 42));
	file->info.dib.colors = swap4(ft_int(file->stream + 46));
	file->info.dib.important = swap4(ft_int(file->stream + 50));
	return (BMP_OK);
}

int	wipe(t_file *file, uint32_t status)
{
	if (file->stream)
		free(file->stream);
	return (dislay_output(file, status));
}

static int	prechecks(t_file *file, char *bmp, uint8_t *buffer)
{
	int			fd;
	int			size;

	if ((fd = open(bmp, O_RDONLY)) < 0)
		return (BMP_E_OPEN);
	if ((size = read(fd, buffer, BUFFER_SIZE)) < 0)
		return (BMP_E_READ);
	if (size < BUFFER_SIZE)
		return (BMP_E_HEADER);
	if (check_signature(buffer))
		return (BMP_E_SIGNATURE);
	if (check_size(&file->info.bmp.weight, buffer + 2))
		return (BMP_E_SIZE);
	if (!(file->stream = (uint8_t*)malloc(file->info.bmp.weight)))
		return (BMP_E_MALLOC);
	if (lseek(fd, 0, SEEK_SET) < 0)
		return (BMP_E_LSEEK);
	if ((read(fd, file->stream, file->info.bmp.weight)) < 0)
		return (BMP_E_READ);
	if (close(fd))
		return (BMP_E_CLOSE);
	return (BMP_OK);
}

static int	parse_bmp(t_file *file, t_bmp *image)
{
	if ((file->info.error = check_header(file)))
		return (file->info.error);
	setup_infos(&file->info);
	if (!(file->pixels = (uint32_t*)malloc(file->info.memory)))
		return (BMP_E_MALLOC);
	build_image(file, file->stream + BMP_SHIFT, file->info);
	load_image(file, image);
	return (BMP_OK);
}

int			bmp_to_array(char *bmp, t_bmp *img)
{
	t_file		file;
	uint8_t		buffer[BUFFER_SIZE];

	presets(&file);
	if ((file.info.error = prechecks(&file, bmp, buffer)))
		return (wipe(&file, file.info.error));
	else
		return (wipe(&file, parse_bmp(&file, img)));
}