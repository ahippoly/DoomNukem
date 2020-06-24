#include "proto_global.h"

int				init_weapon_0(t_data *d, t_hud *hud)
{
	hud->perso_weapon[0]->id = 0;
	hud->perso_weapon[0]->name = WEAPON_NAME_0;
	hud->perso_weapon[0]->ammo_left = 0;
	hud->perso_weapon[0]->capacity = 50;
	hud->perso_weapon[0]->dammage = 0;
	hud->perso_weapon[0]->range = 0;
	if (!(hud->perso_weapon[0]->surface = SDL_LoadBMP(WEAPON_PATH_0)))
	{
		printf("Erreur de chargement de l'image : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	if (!(hud->perso_weapon[0]->texture = SDL_CreateTextureFromSurface(d->rend, hud->perso_weapon[0]->surface)))
	{
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	SDL_FreeSurface(hud->perso_weapon[0]->surface);
	return (0);
}

int				init_weapon_1(t_data *d, t_hud *hud)
{
	hud->perso_weapon[1]->id = 0;
	hud->perso_weapon[1]->name = WEAPON_NAME_1;
	hud->perso_weapon[1]->ammo_left = 0;
	hud->perso_weapon[1]->capacity = 70;
	hud->perso_weapon[1]->dammage = 0;
	hud->perso_weapon[1]->range = 0;
	if (!(hud->perso_weapon[1]->surface = SDL_LoadBMP(WEAPON_PATH_1)))
	{
		printf("Erreur de chargement de l'image : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	if (!(hud->perso_weapon[1]->texture = SDL_CreateTextureFromSurface(d->rend, hud->perso_weapon[1]->surface)))
	{
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	SDL_FreeSurface(hud->perso_weapon[1]->surface);
	return (0);
}

int				init_weapon_2(t_data *d, t_hud *hud)
{
	hud->perso_weapon[2]->id = 0;
	hud->perso_weapon[2]->name = WEAPON_NAME_2;
	hud->perso_weapon[2]->ammo_left = 0;
	hud->perso_weapon[2]->capacity = 0;
	hud->perso_weapon[2]->dammage = 0;
	hud->perso_weapon[2]->range = 0;
	if (!(hud->perso_weapon[2]->surface = SDL_LoadBMP(WEAPON_PATH_2)))
	{
		printf("Erreur de chargement de l'image : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	if (!(hud->perso_weapon[2]->texture = SDL_CreateTextureFromSurface(d->rend, hud->perso_weapon[2]->surface)))
	{
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	SDL_FreeSurface(hud->perso_weapon[2]->surface);
	return (0);
}

int				init_weapon_3(t_data *d, t_hud *hud)
{
	hud->perso_weapon[3]->id = 0;
	hud->perso_weapon[3]->name = WEAPON_NAME_3;
	hud->perso_weapon[3]->ammo_left = 0;
	hud->perso_weapon[3]->capacity = 0;
	hud->perso_weapon[3]->dammage = 0;
	hud->perso_weapon[3]->range = 0;
	if (!(hud->perso_weapon[3]->surface = SDL_LoadBMP(WEAPON_PATH_3)))
	{
		printf("Erreur de chargement de l'image : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	if (!(hud->perso_weapon[3]->texture = SDL_CreateTextureFromSurface(d->rend, hud->perso_weapon[3]->surface)))
	{
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	SDL_FreeSurface(hud->perso_weapon[3]->surface);
	return (0);
}

int				init_weapon_4(t_data *d, t_hud *hud)
{
	hud->perso_weapon[4]->id = 0;
	hud->perso_weapon[4]->name = WEAPON_NAME_4;
	hud->perso_weapon[4]->ammo_left = 0;
	hud->perso_weapon[4]->capacity = 0;
	hud->perso_weapon[4]->dammage = 0;
	hud->perso_weapon[4]->range = 0;
	if (!(hud->perso_weapon[4]->surface = SDL_LoadBMP(WEAPON_PATH_4)))
	{
		printf("Erreur de chargement de l'image : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	if (!(hud->perso_weapon[4]->texture = SDL_CreateTextureFromSurface(d->rend, hud->perso_weapon[4]->surface)))
	{
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
		return (exit_hud(hud));
	}
	SDL_FreeSurface(hud->perso_weapon[4]->surface);
	return (0);
}