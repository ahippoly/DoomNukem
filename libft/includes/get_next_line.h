/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:54:44 by alebui            #+#    #+#             */
/*   Updated: 2020/07/09 17:45:44 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <unistd.h>

# define BUFF_SIZE 90000

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
