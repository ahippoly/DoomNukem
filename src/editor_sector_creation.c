/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_sector_creation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 23:13:45 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/07 23:17:07 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

static void	recreate_room_height(t_env *env)
{
	int nb_deleted;
	int i;

	i = 0;
	nb_deleted = 0;
	while (i < env->room_count)
	{
		while (env->room_height[i + nb_deleted].start == -42)
			nb_deleted++;
		env->room_height[i] = env->room_height[i + nb_deleted];
		i++;
	}
}

static void	recreate_floor_text(t_env *env)
{
	int	nb_deleted;
	int	i;

	i = 0;
	nb_deleted = 0;
	while (i < env->room_count)
	{
		while (env->room_text[i + nb_deleted] == -42)
			nb_deleted++;
		env->room_text[i] = env->room_text[i + nb_deleted];
		i++;
	}
}

static void	process_current_room(t_env *env, t_room *current_room,
	int current_room_id, int i)
{
	int		begin;

	begin = i;
	current_room_id = env->wall_list[begin].room_id_ref;
	while (i < env->wall_count
		&& current_room_id == env->wall_list[i].room_id_ref)
		i++;
	current_room = &env->room_list[current_room_id];
	current_room->room_id = current_room_id;
	current_room->wall_ref.start = begin;
	current_room->wall_ref.end = i;
	current_room->nb_wall = i - begin;
	current_room->height = env->room_height[current_room_id];
	current_room->floor_text = env->room_text[current_room_id];
}

void		recreate_room_list(t_env *env)
{
	int		i;
	int		current_room_id;
	t_room	*current_room;

	i = 0;
	current_room_id = 0;
	current_room = NULL;
	free(env->room_list);
	if (!(env->room_list = (t_room*)p_malloc(sizeof(t_room) * env->room_count)))
		exit_editor(env, "error: failed to malloc");
	recreate_room_height(env);
	recreate_floor_text(env);
	while (i < env->wall_count)
	{
		if (env->wall_list[i].id != -1 && env->wall_list[i].room_id_ref != -1)
			process_current_room(env, current_room, current_room_id, i);
		i++;
	}
}
