/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:54:44 by alebui            #+#    #+#             */
/*   Updated: 2020/07/08 21:21:47 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"

# define BUFF_SIZE 500

//GNL ALEX

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
