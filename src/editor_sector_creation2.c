/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_sector_creation2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 23:17:23 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/07 23:19:03 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

static void	reference_wall(t_point pos, int wall_id, t_env *env)
{
	t_wall_ref *new_ref;

	new_ref = alloc_wall(wall_id);
	new_ref->next = env->map_wall_ref[(int)pos.y][(int)pos.x];
	env->map_wall_ref[(int)pos.y][(int)pos.x] = new_ref;
}

void		add_wall_ref_point(t_wall wall, t_env *env)
{
	if (wall.id != -1)
	{
		reference_wall(wall.p1, wall.id, env);
		reference_wall(wall.p2, wall.id, env);
	}
}

static void	process_print_wall(int *one_at_least, t_wall_ref *ref, int fd)
{
	*one_at_least = 1;
	ft_putstr_fd(ft_itoa(ref->wall_id), fd);
	ref = ref->next;
	if (ref)
		ft_putstr_fd(",", fd);
}

void		print_wall_ref(t_wall_ref ***map_wall_ref, t_size map_size, int fd)
{
	int			i;
	int			j;
	int			one_at_least;
	t_wall_ref	*ref;

	i = 0;
	while (i < map_size.h)
	{
		j = 0;
		while (j < map_size.w)
		{
			ref = map_wall_ref[i][j];
			one_at_least = 0;
			while (ref)
				process_print_wall(&one_at_least, ref, fd);
			if (one_at_least == 0)
				ft_putstr_fd("-1", fd);
			ft_putstr_fd(" ", fd);
			j++;
		}
		i++;
		ft_putstr_fd("\n", fd);
	}
	ft_putstr_fd("\n", fd);
}
