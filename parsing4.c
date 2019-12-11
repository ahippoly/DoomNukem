/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:26:29 by ahippoly          #+#    #+#             */
/*   Updated: 2019/03/25 18:25:33 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
//#include <stdio.h>

int hex2dec(unsigned char *mem, int bytes)
{
	int i;
    int po;
    int hex;

    i = 0;
    po = 0;
    hex = 0;
    while (i < bytes)
    {
		// printf("hex1 = %i  hex2 = %i\n",mem[i] / 16, mem[i] % 16);
        hex += (mem[i] / 16 * ft_pow(16,po + 1)) + (mem[i] % 16 * ft_pow(16,po));
        i++;
        po += 2;
		// printf("hex = %i\n",hex);
    }
    return (hex);
}

void *nazi_case(void)
{
	char str[] = "Alerte nazi, Test de nazi detecte, Alerte nazi\n";
	write(1,str,ft_strlen(str));
	return (NULL);
}

char *read_pixels(int fd)
{
	size_t str_length;
	size_t totalread;
	size_t ret;
	char *str;
	char *new_str;
	char buf[100001];

	str = ft_strdup("");	
	totalread = 0;
	str_length = 0;
	while ((ret = read(fd , buf, 100000)))
	{
		buf[ret] = 0;
		totalread += ret;
		new_str = (char*)malloc(totalread);
		ft_memcpy(new_str, str, str_length);
	 	ft_memcpy(&new_str[str_length] , buf , ret);
		free(str);
		str = new_str;
		str_length = totalread;
	}
	//print_memory(str,totalread);
	return (str);
}

char *convert2bgra(char *str, int w, int h)
{
	int end;
	int i;
	int j;
	char *new_str;

	end = w * h * 3;
	if (!(new_str = (char*)malloc(w * h * 4)))
		return(nazi_case());
	i = 0;
	j = 0;
	while (i < end)
	{
		ft_memcpy(&new_str[j],&str[i],3);
		new_str[j + 3] = (char)255;
		j += 4;
		i += 3;
	}
	free(str);
	return (new_str);
}

char *ft_load_bmp(char *file, int *width, int *height)
{
	int fd;
	char head[100];
	char *str;
	size_t ret;
	int pix_array_pos;
	int bpp;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (nazi_case());
	if (read(fd, head, 0) == -1)
		return (nazi_case());
	if ((ret = read(fd, head, 26)) != 26)
		return (nazi_case());
	pix_array_pos = hex2dec(&((unsigned char*)head)[10],4);
	*width = hex2dec(&((unsigned char*)head)[18],4);
	*height = ft_abs(hex2dec(&((unsigned char*)head)[22],4));
	if ((ret = read(fd, head, pix_array_pos - 26)) != (size_t)pix_array_pos - 26)
		return (nazi_case());
	bpp = hex2dec(&((unsigned char*)head)[2],2);
	printf("bpp = %i\n",bpp);
//	print_memory(buf,pix_array_pos - 26);
	str = read_pixels(fd);
	if (bpp == 24)
	{
		str = convert2bgra(str,*width,*height);
	}
	return (str);
}
