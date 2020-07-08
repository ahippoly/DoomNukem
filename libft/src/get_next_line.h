/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:54:44 by alebui            #+#    #+#             */
/*   Updated: 2019/05/15 15:55:58 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"

# define BUFF_SIZE 500

int					get_next_line(const int fd, char **line);

typedef struct		s_read
{
	int				fd;
	char			*buf;
	char			*left;
	char			*tmp;
	struct s_read	*next;
}					t_read;

#endif
