/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_icon2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 19:16:45 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/07 19:16:46 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void		add_icon(t_env *env, t_icon new)
{
	env->icon_list[env->icon_count++] = new;
	if (env->icon_count >= env->icon_list_size)
	{
		env->icon_list = double_array_size(env->icon_list,
			sizeof(t_icon), env->icon_count);
		env->icon_list_size *= 2;
	}
}
