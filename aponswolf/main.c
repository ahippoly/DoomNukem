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

static void ft_showmap(int **map, int x, int y)
{
	int i;
	int j;

	ft_putnbr(x);
	ft_putstr(" ");
	ft_putnbr(y);
	ft_putendl("");
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_putnbr(map[i][j]);
			ft_putstr(" ");
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}

int main(int argc, char **argv)
{
	t_enval *env;

	env = (t_enval *)malloc(sizeof(t_enval));
	if (argc == 2)
	{
		env = init_values(argv[1], env);
		env = init_mlx(env);
		ft_showmap(env->map.walls, env->map.width, env->map.height);
		ft_putendl("Calc successful !");
		env = ray_draw(env);
		mlx_handle_hooks(env);
	}
	return (0);
}
