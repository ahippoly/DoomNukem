/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 22:58:50 by robin             #+#    #+#             */
/*   Updated: 2020/07/05 22:58:51 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_H
# define BRESENHAM_H

# include "SDL.h"

typedef struct	s_oct
{
	int			inc[2];
	int			d[2];
	int			e;
	int			bool;
	int			boolxy;
	int			ecart;
}				t_oct;

#endif
