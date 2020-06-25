#ifndef BMP_H
# define BMP_H

# include <stdint.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BMP_SIGN		0x424D
# define DIB_SIZE		108u
# define MAX_SIZE		16842752u
# define BMP_SHIFT		122u
# define BUFFER_SIZE	6
# define B3				0xFF
# define B2				0xFF00
# define B1				0xFF0000
# define B0				0xFF000000

typedef enum		e_errors
{
	BMP_OK,
	BMP_E_OPEN,
	BMP_E_MALLOC,
	BMP_E_READ,
	BMP_E_SIZE,
	BMP_E_CLOSE,
	BMP_E_SIGNATURE,
	BMP_E_LSEEK,
	BMP_E_DIB,
	BMP_E_BPP,
	BMP_E_COMPRESSION,
	BMP_E_HEADER,
	BMP_E_OFFSET,
	BMP_E_RES,
	BMP_E_PADDING,
	BMP_ERROR_COUNT
}					t_errors;

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
	char			*msg[BMP_ERROR_COUNT];
	t_info			info;
	uint8_t			*stream;
	uint32_t		*pixels;
}					t_file;

typedef struct		s_bmp
{
	int32_t			width;
	int32_t			height;
	uint32_t		*pixels;
}					t_bmp;

#endif