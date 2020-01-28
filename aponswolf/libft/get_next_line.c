/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:36:53 by apons             #+#    #+#             */
/*   Updated: 2019/10/23 09:46:23 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_restock(char **keep, size_t i)
{
	char	*tmp;

	tmp = *keep;
	*keep = ft_strdup(*keep + i + 1);
	free(tmp);
}

int				get_next_line(const int fd, char **line)
{
	size_t		size;
	char		buffer[BUFF_SIZE + 1];
	static char *keeper = NULL;

	if (!line || !BUFF_SIZE || read(fd, buffer, 0) < 0)
		return (-1);
	(!keeper) ? keeper = ft_strnew(0) : 0;
	while ((size = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[size] = '\0';
		if (!(keeper = ft_joindel(keeper, buffer)))
			return (-1);
		if (ft_strchr(keeper, '\n'))
			break ;
	}
	if ((size < BUFF_SIZE) && (ft_strlen(keeper) == 0))
		return (0);
	size = 0;
	while (keeper[size] != '\n' && keeper[size])
		size++;
	*line = ft_strndup(keeper, size);
	(size < ft_strlen(keeper)) ? ft_restock(&keeper, size) : ft_strdel(&keeper);
	return (1);
}
