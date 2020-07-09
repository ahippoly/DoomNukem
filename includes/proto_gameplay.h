/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto_gameplay.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 23:16:21 by robin             #+#    #+#             */
/*   Updated: 2020/07/09 11:36:43 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_GAMEPLAY_H
# define PROTO_GAMEPLAY_H

# include "data.h"

void	ref_origin(void *type_list, int nb_type, int type);

void	anim_reload(t_data *d);
void	reload_weapon(t_data *d, t_weapon *weapon);
void	anim_weapon(t_data *d);
void	shoot_attempt(t_data *d, t_weapon *weapon);
void	aim_gun(t_data *d);
void	process_gun(t_weapon *weapon, int time, t_data *d);
void	change_mob_life(t_data *d, t_mob *mob, int damage);
void	change_player_life(t_data *d, int *hp, int damage);
void	check_mob_attack(t_param param);
void	move_mobs_in_range(t_data *d, t_mob *mobs, int nb_mob);
void	kill_mob(t_param param);

#endif
