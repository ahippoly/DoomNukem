/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:48:17 by alebui            #+#    #+#             */
/*   Updated: 2019/05/15 15:07:25 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			split_left_into_line(t_read *f_read, char **line)
{
	int		length;
	char	*find_nl;

	if (f_read->left != NULL)
	{
		if (!(find_nl = ft_memchr(f_read->left, 10, ft_strlen(f_read->left))))
			return (-1);
		*line = ft_strsub(f_read->left, 0, (int)(find_nl - f_read->left));
		length = ft_strlen(f_read->left) - ft_strlen(*line);
		if (length > 0)
		{
			f_read->left = ft_strsubfree(&f_read->left, \
								(int)(find_nl + 1 - f_read->left), length);
		}
		else
			ft_strdel(&f_read->left);
		return (1);
	}
	return (0);
}

static void			del_maillon(t_read **lst, int fd)
{
	t_read			*tmp;
	t_read			*prev;

	tmp = *lst;
	while (tmp && tmp->fd != fd)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return ;
	if (tmp != *lst)
		prev->next = tmp->next;
	else
		*lst = tmp->next;
	ft_strdel(&tmp->left);
	ft_strdel(&tmp->buf);
	ft_strdel(&tmp->tmp);
	ft_memdel((void **)&tmp);
}

static int			read_file(t_read **lst, t_read *f_read, char **line)
{
	int				ret_read;
	int				endl;

	while ((ret_read = read(f_read->fd, f_read->buf, BUFF_SIZE)) > 0)
	{
		endl = 0;
		while (!(f_read->buf[endl] == '\n' || f_read->buf[endl] == 0) \
				&& endl < ret_read)
			endl++;
		f_read->tmp = ft_strsub(f_read->buf, 0, endl);
		*line = ft_strjoin_free(line, f_read->tmp);
		ft_strdel(&f_read->tmp);
		if (endl < ret_read)
		{
			f_read->left = ft_strsub(f_read->buf, endl + 1, ret_read - endl);
			return (1);
		}
		f_read->buf = ft_memset(f_read->buf, 0, BUFF_SIZE + 1);
	}
	if (ret_read == 0)
		del_maillon(lst, f_read->fd);
	if (*line != NULL)
		return (1);
	return (ret_read);
}

static t_read		*get_fd_lst(t_read **lst, int fd)
{
	t_read			*tmp;
	t_read			*prev;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		prev = tmp;
		tmp = tmp->next;
	}
	if (!(tmp = (t_read *)malloc(sizeof(t_read))))
		return (NULL);
	if (*lst)
		prev->next = tmp;
	else
		*lst = tmp;
	if (!(tmp->buf = ft_strnew(BUFF_SIZE)))
		return (NULL);
	tmp->fd = fd;
	tmp->left = NULL;
	tmp->tmp = NULL;
	tmp->next = NULL;
	return (tmp);
}

int					get_next_line(const int fd, char **line)
{
	static t_read	*f_read = NULL;
	t_read			*elem;

	if (line == NULL)
		return (-1);
	*line = NULL;
	if (!(elem = get_fd_lst(&f_read, fd)))
		return (-1);
	if (elem->left && ft_strlen(elem->left) == 0)
		ft_strdel(&elem->left);
	elem->buf = ft_memset(elem->buf, 0, BUFF_SIZE + 1);
	if (split_left_into_line(elem, line) == 1)
		return (1);
	if (elem->left)
	{
		ft_strdel(line);
		*line = ft_strdup(elem->left);
		ft_strdel(&elem->left);
	}
	return (read_file(&f_read, elem, line));
}
