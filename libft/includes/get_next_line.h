/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:20:27 by ahippoly          #+#    #+#             */
/*   Updated: 2019/04/12 05:47:21 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# define BUFF_SIZE 50000

typedef	struct	s_var
{
	char	buff[BUFF_SIZE + 1];
	char	*endline;
	char	*line;
	char	*tmp;
	int		oct;
	int		i;
	int		j;
	int		finish;
	t_list	*first;
	t_list	*actual;
}				t_var;

int				get_next_line(const int fd, char **line);

#endif
