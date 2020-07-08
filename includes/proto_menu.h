/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto_menu.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 23:27:13 by robin             #+#    #+#             */
/*   Updated: 2020/07/09 00:57:12 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_MENU_H
# define PROTO_MENU_H

# include "data.h"

/*
** menu_main.c
*/

int				render_menu(t_data *d);

/*
** menu_button.c
*/

int				render_bg_btn(t_data *d, SDL_Rect pos);
int				render_text_btn(t_data *d, SDL_Rect pos, SDL_Texture *texture,
					char *text);
int				render_btn(t_data *d);

/*
** menu_clean.c
*/

int				free_menu(t_data *d);
int				exit_menu(t_data *d);
int				free_gameover(t_data *d);

/*
** menu_exec
*/

int				is_mouse_on_target(t_data *d, SDL_Rect pos);
int				catch_btn_event(t_data *d);
char			**malloc_argv(t_data *d, int n);

/*
** gameover_button.c
*/

int				render_gameover_button(t_data *d);
int				catch_over_btn_event(t_data *d);

/*
** gameover_render.c
*/

int				render_gameover(t_data *d);

/*
** render_wallpaper.c
*/

int				init_backgroundd(t_data *d, SDL_Texture **texture, char *path);
int				put_bg(t_data *d, SDL_Texture *texture);

/*
** win_render.c
*/

int				render_win(t_data *d);


#endif
