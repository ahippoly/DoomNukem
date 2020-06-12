#include <hud.h>

int				init_ttf(t_hud *hud)
{
	if (TTF_Init() < 0)
	{
		printf("Erreur d'initialisation de la lib TTF : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
	hud->font = TTF_OpenFont("/font/keepcalm_font.ttf", 20);
	hud->color.r = 255;
	hud->color.g = 255;
	hud->color.b = 255;
	hud->color.a = 255;
	return (0);
}

int				quit_ttf(t_hud *hud)
{
	TTF_CloseFont(hud->font);
	TTF_Quit();		
}

SDL_Surface		*copy_surface(t_data *d, SDL_Surface *src)
{
	SDL_Surface *dest;
	
	dest = SDL_CreateRGBSurface(0, 30, 30, 32, 0, 0, 0, 0);
	if(dest != NULL) 
		SDL_BlitSurface(src, NULL, dest, NULL);
	return (dest);
}

void			set_text(t_data *d, t_hud *hud, unsigned int nb)
{
	SDL_Texture	*t_cpy;
	SDL_Surface	*s_cpy;	
	char		*text;
	
	text = ft_itoa(nb);
	if(!(s_cpy = TTF_RenderText_Blended(hud->font, text, hud->color)))
		printf("Erreur d'affichage du texte TTF : %s\n", TTF_GetError());
	hud->message_surface = copy_surface(d, s_cpy);
	SDL_FreeSurface(s_cpy);
}

void			render_text(t_data *d, t_hud *hud, SDL_Rect pos)
{
	SDL_Rect	tmp;
	SDL_Texture	*t_cpy;

	tmp = pos; 
	if (!(hud->message_texture = SDL_CreateTextureFromSurface(d->rend, hud->message_surface)))
		printf("Erreur de conversion de la surface : %s", SDL_GetError());
	SDL_RenderCopy(d->rend, hud->message_texture, NULL, &tmp);
}