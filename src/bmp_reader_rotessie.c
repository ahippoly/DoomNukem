#include "proto_global.h"
#include "bmp.h"

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