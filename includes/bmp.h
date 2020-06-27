#ifndef BMP_H
# define BMP_H

# include <stdint.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE	6

typedef	struct		s_vec
{
	int				x;
	int				y;
}					t_vec;

typedef	struct		s_hdr
{
	uint32_t		offset;
	uint32_t		weight;
}					t_hdr;

typedef	struct		s_dib
{
	t_vec			dpi;
	t_vec			res;
	uint8_t			bpp;
	uint8_t			planes;
	uint8_t			important;
	uint8_t			compression;
	uint32_t		raw;
	uint32_t		size;
	uint32_t		colors;

}					t_dib;

typedef struct		s_info
{
	t_hdr			bmp;
	t_dib			dib;
	uint8_t			bytes;
	uint8_t			error;
	uint8_t			padding;
	uint32_t		row;
	uint32_t		memory;
	uint32_t		scanline;
}					t_info;

typedef struct		s_file
{
	t_info			info;
	uint8_t			*stream;
	uint32_t		*pixels;
}					t_file;

void				bmp_reader(char *bmp, t_img *image);


#endif