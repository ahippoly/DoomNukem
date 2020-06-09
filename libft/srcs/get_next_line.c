/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:57:21 by saneveu           #+#    #+#             */
/*   Updated: 2018/12/09 16:15:18 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrandsub(char **save, char **line, int fd, int res)
{
	int		len;
	char	*tmp;

	len = 0;
	while (save[fd][len] != '\n' && save[fd][len] != '\0')
		len++;
	if (save[fd][len] == '\n')
	{
		*line = ft_strsub(save[fd], 0, len);
		tmp = ft_strdup(save[fd] + len + 1);
		free(save[fd]);
		save[fd] = tmp;
		if (save[fd][0] == '\0')
			ft_strdel(&save[fd]);
	}
	else if (save[fd][len] == '\0')
	{
		if (res == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(save[fd]);
		ft_strdel(&save[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*save[1024];
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				res;

	if (fd < 0)
		return (-1);
	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strnew(1);
		tmp = ft_strjoin(save[fd], buff);
		free(save[fd]);
		save[fd] = tmp;
		if (!ft_strchr(buff, '\n'))
			break ;
	}
	if (res < 0)
		return (-1);
	else if (res == 0 && (save[fd] == NULL || save[fd][0] == '\0'))
		return (0);
	return (ft_chrandsub(save, line, fd, res));
}
