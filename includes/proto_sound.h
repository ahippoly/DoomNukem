/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto_sound.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 23:42:12 by robin             #+#    #+#             */
/*   Updated: 2020/07/05 23:42:46 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_SOUND_H
# define PROTO_SOUND_H

# include "data.h"

void		init_sound(t_data *d);
int			play_sound(t_data *d, int index);
void		clean_sounds(t_data *d);

#endif
