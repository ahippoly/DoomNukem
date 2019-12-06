/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 21:09:03 by ahippoly          #+#    #+#             */
/*   Updated: 2019/10/15 16:46:25 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft/libft.h"

int main (int ac, char **av)
{
	SDL_Point p1;
	SDL_Point p2;
	SDL_Point p3;
	SDL_Point p4;
	SDL_Point res;

	p1.x = 5;
	p2.x = 5;
	p3.x = 1;
	p4.x = 7;
	p1.y = 0;
	p2.y = 8;
	p3.y = 5;
	p4.y = 5;

	res = segment_intersect(p1, p2, p3, p4);
	printf("res.x = %d, res.y = %d\n",res.x, res.y);
}
