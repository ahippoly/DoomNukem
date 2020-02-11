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
# include <time.h>
# include "SDL2/SDL.h"
# include "enemy_id.h"

# define WEAPON_TYPE_ENEMY		0
# define WEAPON_TYPE_SEMIAUTO	1
# define WEAPON_TYPE_AUTOMATIC	2
# define WEAPON_TYPE_CHARGED	3

# define WEAPON_STATE_READY		0
# define WEAPON_STATE_RELOADING 1

# define PLAYER_UNDETECTED		0
# define PLAYER_ALERTED			1

# define PLAYER_HOSTILE			0
# define PLAYER_FRIENDLY		1

# define BUFF					0
# define DEBUFF					1
# define EFFECT_AMOUNT			2

# define DIFFICULTY_PROJECT		0
# define DIFFICULTY_EASY		1
# define DIFFICULTY_MEDIUM		2
# define DIFFICULTY_HARD		3
# define DIFFICULTY_INSANE		4
# define DIFFICULTY_IMPOSSIBLE  5

# define ZERO					0
# define INFINITE				-1

/*
** Building blocks for most other structures.
*/

typedef	struct	s_stat
{
	int			current;
	int			max;
}				t_stat;

typedef struct	s_pos
{
	double		x;
	double		y;
	double		height;
}				t_pos;

/*
** Structure for status effects.
** Value represents the strength of the status effect while
** time is the duration of said effect.
** If a stronger status effect is applied, the stronger debuff is applied
** but retains the duration of the weaker status effect if said status effect
** was supposed to last longer.
*/

typedef struct	s_buff
{
	double	value[2];
	int		duration[2];
}				t_buff;

/*
** Structure allowing for aoe or spread effects
*/

typedef struct	s_radius
{
	double		width;
	double		depth;
}				t_radius;

typedef struct	s_status
{
	t_buff		dmg_resist;
	t_buff		att_dmg;
	t_buff		att_spd;
}				t_status;

/*
** Structure handling clip sizes for weapons
*/

typedef struct  s_clip
{
	t_stat		size;
	double		reload;
}				t_clip;

typedef struct	s_attack
{
	int			type;
	int			damage;
	double		range;
	int			speed;
	t_radius	radius;
}				t_attack;

typedef struct	s_weapon
{
	char		*name;
	t_clip		clip;
	t_stat		ammo;
	t_attack	attack;
}				t_weapon;

typedef struct	s_equipped
{
	int		current;
	int		weapon_state;
	Uint32	delay;
}				t_equipped;

/*
** Bigger structures, contained in the game structure.
*/

typedef struct	s_player_character
{
	t_pos		pos;
	t_stat		health;
	t_stat		armor;
	double		movement_speed;
	t_status	effects;
	t_weapon	arsenal[5];
	t_equipped	equip;
}				t_player_character;

typedef struct	s_npc
{
	t_pos		pos;
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
	double				diff_mod;
	Uint32				time_start;
}				t_game;

/*
** Functions
*/

void		init_pc(t_player_character *pc);
void		init_game(t_game *game);
void		game_loop(t_game *game);
void		display_game_over(void);

/*
** get_weapon.c functions
*/

t_weapon	get_weapon_fist(void);
t_weapon	get_weapon_pistol(void);
t_weapon	get_weapon_rifle(void);
t_weapon	get_weapon_shotgun(void);
t_weapon	get_weapon_bfg(void);

/*
** get_enemy.c functions
*/

t_npc		get_enemy(t_stat_sheet *sheet, int id, t_pos start_pos);

/*
** perform_attack.c functions
*/

void		handle_weapon(t_weapon *weapon, Uint32 delay, t_game *game);

/*
** resolve_damage.c functions
*/

int		get_damage_dealt(t_attack attacker, t_buff att_mod);
void	get_damage_taken(int *health, int *armor, t_buff def_mod, int damage);

/*
** handle_status_effects functions
*/

void		apply_stat_eff(t_buff *effect, int id, double value, int duration);
void		countdown_status_effect_one(t_buff *effect, int delay);
void		countdown_status_effect_all(t_status *status, int delay);
void		clean_status_effect(t_buff *effect);

/*
** shortcuts.c functions
*/

void		init_stat(t_stat *stat, int max, int current);
void		init_att_stat_basic(t_attack *att, int dmg, double spd, int range);

#endif