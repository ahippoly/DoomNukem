#ifndef PROTO_CLEAN_H
# define PROTO_CLEAN_H

# include "render.h"

/* malloc.c */

SDL_Texture		**malloc_texture_tab(int size);
t_range			*malloc_range(int size);
int				*malloc_int_tab(int size);
t_icon			*malloc_icon(int size);
t_img			*malloc_img(int size);
t_wall			*malloc_wall(int size);
t_ssprite		*malloc_ssprite(int size);
t_button		*malloc_button(int size);
t_txt_img		*malloc_txtimg(int size);
t_input			*malloc_input(int size);


/* clean_editor.c */

void			clear_map_ref(t_env *env);
int				exit_editor(t_env *e, char *msg);

#endif