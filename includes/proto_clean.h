#ifndef PROTO_CLEAN_H
# define PROTO_CLEAN_H

# include "render.h"

/* clean_editor.c */

SDL_Texture		**malloc_texture_tab(int size);
t_range			*malloc_range(int size);
int				*malloc_int_tab(int size);
t_icon			*malloc_icon(int size);
int				exit_editor(t_env *e);
void			clear_map_ref(t_env *env);


#endif