/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:35:23 by apons             #+#    #+#             */
/*   Updated: 2020/01/29 10:35:23 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEPLAY_H
# define GAMEPLAY_H

/*
** All includes and defines necessary for the gameplay part to function.
*/

# include <stdlib.h>

# define WEAPON_TYPE_MELEE		0
# define WEAPON_TYPE_SEMIAUTO	1
# define WEAPON_TYPE_AUTOMATIC	2
# define WEAPON_TYPE_CHARGED	3

# define PLAYER_UNDETECTED		0
# define PLAYER_ALERTED			1

# define NPC_HOSTILE			0
# define NPC_FRIENDLY			1

# define ZERO					0
# define INFINITE				-1

/*
** Building block for many stats.
*/

typedef	struct	s_stat
{
	int			current;
	int			max;
}				t_stat;

/*
** Structure for mods
*/

typedef struct	s_buff
{
	double	value[4];
	int		time[4];
}				t_buff;

/*
** Structure allowing for aoe or spread effects
*/

typedef struct	s_radius
{
	double		width;
	double		depth;
}				t_radius;

/*
** Structure handling clip sizes for weapons
*/

typedef struct  s_clip
{
	t_stat		size;
	double		reload;
}				t_clip;

typedef struct	s_status
{
	t_buff		dmg_resist;
	t_buff		att_dmg;
	t_buff		att_spd;
}				t_status;

typedef struct	s_attack
{
	int			type;
	int			damage;
	double		range;
	double		speed;
	t_radius	radius;
}				t_attack;

/*
** Bigger structures, contained in the game structure.
*/

typedef struct	s_weapon
{
	char		*name;
	t_clip		clip;
	t_stat		ammo;
	t_attack	attack;
}				t_weapon;

typedef struct	s_player_character
{
	t_stat		health;
	t_stat		armor;
	double		movement_speed;
	t_status	effects;
	t_weapon	arsenal[5];
	int			current_w;
}				t_player_character;

typedef struct	s_npc
{
	t_stat		health;
	t_attack	attack;
	double		movement_speed;
	t_status	effects;
	int			player_detection;
	int			player_allegiance;
}				t_npc;

/*
** Placeholder, in case a flag structure is required.
*/

typedef	struct	s_flag
{
} 				t_flag;

/*
** Game structure that should hold every 
** single aspect of the gameplay itself.
*/

typedef struct	s_game
{
	t_player_character	pc;
	t_npc				npcs[20];
	
}				t_game;

/*
** Functions
*/

void		init_pc(t_player_character *pc);
void		init_game(t_game *game);

t_weapon	get_fist(void);
t_weapon	get_pistol(void);
t_weapon	get_rifle(void);
t_weapon	get_shotgun(void);
t_weapon	get_bfg(void);

double		get_modifier(t_buff buff);
#endif