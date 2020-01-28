/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:10:54 by apons             #+#    #+#             */
/*   Updated: 2019/11/15 12:10:54 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**This function is a manual, typing ".wolf3d (h)elp" prints it on standard OP.
*/

void	ft_help(void)
{
	ft_putendl("To launch the program, type './wolf3d [map].");
	ft_putendl("A map should look like this :\n\n--------------------\n");
	ft_putendl("X Y x y");
	ft_putendl("1 1 1 1 1\n1 0 0 0 1\n1 0 1 0 1\n1 0 0 0 1\n1 1 1 1 1\n");
	ft_putendl("--------------------\n");
	ft_putendl("However :");
	ft_putendl("X & Y must be between 3 & 200 ;");
	ft_putendl("x & y must be between 2 & X-1 (Y-1 respectively) ;");
	ft_putendl("The map must be rectangular, with 1s surrounding it ;");
	ft_putendl("Its width and height must be equal to X (Y respectively) ;");
	ft_putendl("Walls can be placed on the map by using 1s, but make sure");
	ft_putendl("the player's starting coordinates (x & y) are not");
	ft_putendl("invalidated : they need empty spaces to move (0s) after all.");
	ft_putendl("\nUp & Down keys to move forward or backward.");
	ft_putendl("Left & Right keys to turn left or right.");
	ft_putendl("ESC key or click on the red cross to end program.\n");
	ft_putendl("Now, type './wolf3d [map]' to start walking around the map");
	ft_putendl("Have fun ! \n\n...\n\nPlease do not judge the textures...");
	exit(0);
}
