/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto_gameplay.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 23:16:21 by robin             #+#    #+#             */
/*   Updated: 2020/07/05 23:16:25 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_GAMEPLAY_H
# define PROTO_GAMEPLAY_H

# include "data.h"

void ref_origin(void *type_list, int nb_type, int type);

void anim_reload(t_data *d);
void reload_weapon(t_data *d, t_weapon *weapon);
void anim_weapon(t_data *d);
void shoot_attempt(t_data *d, t_weapon *weapon);
void aim_gun(t_data *d);
void process_gun(t_weapon *weapon, int time, t_data *d);

#endif
