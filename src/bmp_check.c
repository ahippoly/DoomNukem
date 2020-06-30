#include "proto_global.h"
#include "bmp.h"

void		set_file(t_file *file)
{
	ft_bzero(file, sizeof(t_file));
	ft_bzero(&file->info, sizeof(t_info));
	ft_bzero(&file->info.bmp, sizeof(t_hdr));
	ft_bzero(&file->info.dib, sizeof(t_dib));
	ft_bzero(&file->info.dib.dpi, sizeof(t_vec));
	ft_bzero(&file->info.dib.res, sizeof(t_vec));
}

int	check_size(uint32_t *size, uint8_t *buff)
{
	return (((*size = swap4(ft_int(buff))) >= 16842752u) ? 1 : 0);
}

int	check_file(t_file *file, char *bmp, uint8_t *buffer)
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