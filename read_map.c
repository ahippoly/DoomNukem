/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:04:51 by ahippoly          #+#    #+#             */
/*   Updated: 2019/03/26 15:29:06 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char **read_map(char *file)
{
	int fd;
	int ret;
	char buf[BUFF_SIZE];

	fd = open(file,O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (read(fd, buf, 0) == -1)
		return (NULL);
	
}
