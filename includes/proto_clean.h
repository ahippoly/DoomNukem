#ifndef PROTO_CLEAN_H
# define PROTO_CLEAN_H

# include "render.h"

/* clean_editor.c */

SDL_Texture		**malloc_texture_tab(int size);
int				exit_editor(t_env *e);
void			clear_map_ref(t_env *env);


#endif