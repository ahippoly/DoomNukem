/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_button_fct2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 05:07:58 by ahippoly          #+#    #+#             */
/*   Updated: 2020/06/10 05:31:21 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include "global_header.h"

void change_selected_wall_texture(t_env *env, int texture_id)
{
    if (env->selected_wall_id != -1)
        env->wall_list[env->selected_wall_id].texture_id = texture_id;
}

void select_previous_mob(t_env *env)
{
    if (env->selected_mob == ICON_MOB_RANGE_BEGIN)
        env->selected_mob = ICON_MOB_RANGE_END - 1;
    else
        env->selected_mob--;
}

void select_next_mob(t_env *env)
{
    if (env->selected_mob == ICON_MOB_RANGE_END - 1)
        env->selected_mob = ICON_MOB_RANGE_BEGIN;
    else
        env->selected_mob++;
}

void select_previous_texture(t_env *env)
{
    if (env->selected_texture == 0)
        env->selected_texture = NB_TEXTURE - 1;
    else
        env->selected_texture--;
    change_selected_wall_texture(env, env->selected_texture);
}
