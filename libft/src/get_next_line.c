/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:09:11 by ahippoly          #+#    #+#             */
/*   Updated: 2018/12/08 01:48:39 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdlib.h>

void	ft_endline_null_case(t_list *memory, t_var *v)
{
	if (v->endline == NULL)
	{
		v->endline = ft_strchr(memory->content, '\0');
		v->finish = 0;
	}
}

t_list	*ft_allocate_fd(t_list *memory, int fd, t_var *v)
{
	v->oct = 1;
	v->finish = 1;
	if (!memory)
	{
		memory = ft_lstnew("\0", 1);
		memory->content_size = fd;
		v->first = memory;
	}
	else
	{
		v->first = memory;
		while (memory && memory->content_size != (size_t)fd)
		{
			v->actual = memory;
			memory = memory->next;
		}
		if (!memory)
		{
			memory = ft_lstnew("\0", 1);
			memory->content_size = fd;
			v->actual->next = memory;
		}
	}
	return (memory);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*memory;
	t_var			v;

	if (read(fd, v.buff, 0) == -1)
		return (-1);
	memory = ft_allocate_fd(memory, fd, &v);
	while (!(v.endline = ft_strchr(memory->content, '\n')) && v.oct != 0)
	{
		v.oct = read(fd, v.buff, BUFF_SIZE);
		v.buff[v.oct] = '\0';
		memory->content = ft_strjoinfree(memory->content, v.buff, 1);
	}
	ft_endline_null_case(memory, &v);
	*v.endline = '\0';
	*line = ft_strdup(memory->content);
	v.tmp = memory->content;
	memory->content = ft_strdup(v.endline + v.finish);
	free(v.tmp);
	memory = v.first;
	if (*line[0] || v.oct != 0)
		return (1);
	return (0);
}
