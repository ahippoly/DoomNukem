/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_reader2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:27:18 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/06 19:36:50 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

int		hex2dec(unsigned char *mem, int bytes)
{
	int i;
	int po;
	int hex;

	i = 0;
	po = 0;
	hex = 0;
	while (i < bytes)
	{
		hex += (mem[i] / 16 * ft_pow(16, po + 1))
			+ (mem[i] % 16 * ft_pow(16, po));
		i++;
		po += 2;
	}
	return (hex);
}

char	*read_pixels(int fd, char *str)
{
	size_t	str_length;
	size_t	totalread;
	size_t	ret;
	char	*new_str;
	char	buf[100001];

	str = ft_strdup("");
	totalread = 0;
	str_length = 0;
	while ((ret = read(fd, buf, 100000)))
	{
		buf[ret] = 0;
		totalread += ret;
		new_str = (char*)malloc(totalread);
		ft_memcpy(new_str, str, str_length);
		ft_memcpy(&new_str[str_length], buf, ret);
		free(str);
		str = new_str;
		str_length = totalread;
	}
	return (str);
}

char	*convert2bgra(char *str, int w, int h)
{
	int		end;
	int		i;
	int		j;
	char	*new_str;

	end = w * h * 3;
	if (!(new_str = (char*)malloc(w * h * 4)))
	{
		ft_putendl("Failed to malloc");
		return (NULL);
	}
	i = 0;
	j = 0;
	while (i < end)
	{
		ft_memcpy(&new_str[j], &str[i], 3);
		new_str[j + 3] = (char)255;
		j += 4;
		i += 3;
	}
	free(str);
	return (new_str);
}

void	go_next_line(int *x, int *y, int w)
{
	*x = 0;
	*y = ft_max(*y - w, 0);
}

void	convert_bmp_type32(char *pixel, int convert)
{
	if (convert == BMP_TYPE_BGRA)
	{
		swap_char(pixel, pixel + 3);
		swap_char(pixel + 1, pixel + 2);
	}
	else if (convert == BMP_TYPE_ABGR)
		swap_char(pixel + 1, pixel + 3);
}
