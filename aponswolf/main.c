/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:32:15 by apons             #+#    #+#             */
/*   Updated: 2019/10/31 10:22:35 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	t_enval *env;

	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "h") == 0 || ft_strcmp(argv[1], "help") == 0)
			ft_help();
		if (!(env = (t_enval *)malloc(sizeof(t_enval))))
		{
			ft_putendl("malloc failed.");
			return (0);
		}
		init_values(argv[1], env);
		init_mlx(env);
		ray_draw(env);
		mlx_handle_hooks(env);
	}
	else
		ft_putendl("Usage : ./wolf3d [map]. Try [(h)elp] instead for help.");
	return (0);
}
