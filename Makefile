RENDER_NAME = doom-nukem

SRC_NAME =	$(sort editor_main.c error_gesture.c image_gesture.c \
			bresenham.c tool_sdlpoint_arithmetic.c editor_wall_add_del.c \
			editor_wall_edit.c text_img.c editor_buttons.c bmp_reader.c \
			editor_map_move.c editor_sector_creation.c line_intersect.c \
			editor_mouse_event.c editor_map_output.c utils.c \
			editor_input.c editor_map_reader.c editor_debug_utils.c \
			editor_icon.c editor_init_data.c editor_init_data2.c image_gesture2.c \
			editor_display_data.c editor_grid.c editor_button_fct.c editor_button_fct2.c \
			editor_map_input.c ssprite.c render_texture_loading.c \
			ttf_init.c  \
			menu_clean.c hud_clean.c exit.c sound.c sprite_init_gun.c sprite_init_gun2.c \
			sprite_init_gun3.c sprite_init_gun4.c sprite_main.c)

RENDER_SRC_NAME = $(sort render_main.c editor_map_reader.c editor_sector_creation.c \
						error_gesture.c image_gesture.c line_intersect.c \
						tool_sdlpoint_arithmetic.c utils.c render_minimap.c \
						bresenham.c render_init_data.c render_event_gesture.c \
						render_wall_processing.c render_draw_walls.c render_texture_loading.c \
						text_img.c render_movement.c image_gesture2.c render_raycast.c \
						render_world_edit.c render_collide_z.c \
						render_draw_floor.c render_draw_floor2.c render_props.c render_obj.c render_draw_slice.c \
						render_ray_process.c render_pixel_put.c \
						render_icon2obj.c \
						hud_weapon.c hud_init_weapons.c hud_perso.c \
						hud_health.c hud_ammo.c hud_inv.c hud_inv1.c hud_utils.c hud_render.c \
						ttf_init.c  hud_init.c \
						sprite_main.c sprite_init_gun.c sprite_init_mob.c mob_anim.c gun_anim.c sound.c \
						gameplay_mobs.c ssprite.c gameplay_props.c gameplay_weapon.c \
						bmp_reader.c \
						render_skybox.c \
						menu_clean.c hud_clean.c exit.c \
						sprite_init_gun2.c sprite_init_gun3.c sprite_init_gun4.c sprite_main.c) ##


SRC_PATH = ./src/
OBJ_PATH = ./obj/
SDL_PATH = ./SDL2/
LIBFT_PATH = ./libft/
FMOD_LIB_PATH = ./FMOD/
INC_PATH = ./includes/ $(LIBFT_PATH)includes/ ./includes/SDL2/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_REND_NAME = $(RENDER_SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ_REND = $(addprefix $(OBJ_PATH),$(OBJ_REND_NAME))
INC = $(addprefix -I,$(INC_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = editor
OPTI = -O3
PTHREAD = -lpthread

LIBFT = libft/libft.a

URL = https://drive.google.com/uc?export=download&id=1esNwBxxYwrrXUokdo6JR5H0i9vTKrj2Q

LDFLAGS = $(addprefix -L,$(LIBFT_PATH) $(FMOD_LIB_PATH))

SDLM = `sdl2-config --cflags --libs`

LIBS = -lft -lm -lSDL2 -lSDL2_ttf -lfmod

LDLIBS = -lft -lm

.PHONY: all clean fclean re libft

all: $(NAME) $(RENDER_NAME)

link_fmod :
	export "LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./FMOD"

libft:
	@printf "/--------------- creating library \e[1;36m$@\e[0m... ----------/\n"
	@make -C $(LIBFT_PATH)
	@printf "/---------------- library $@ created... ----------/\n"

$(NAME): libft $(OBJ)
	@printf "%-50s" "create executable "$(notdir $@)...
	@make -C libft
	@$(CC) $(CFLAGS) $(OPTI) $(INC) $(OBJ) -o $(NAME) $(SDLM) $(LDFLAGS) $(LIBS)
	@printf "\e[1;32m[OK]\e[0m\n"

$(RENDER_NAME): libft $(OBJ_REND)
	@printf "%-50s" "create executable "$(notdir $@)...
	@$(CC) $(OPTI) $(CFLAGS) $(INC) $(OBJ_REND) -o $(RENDER_NAME) $(SDLM) $(LDFLAGS) $(LIBS) $(PTHREAD)
	@printf "\e[1;32m[OK]\e[0m\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "%-50s" "compiling "$(notdir $<)...
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(OPTI) $(INC) -o $@ -c $<
	@printf "\e[1;32m[OK]\e[0m\n"

clean:
	@printf "%-50s" "deleting objects..." 
	@make -C libft clean
	@$(RM) $(OBJ) $(OBJ_REND)
	@$(RM) -r $(OBJ_PATH)
	@printf "\e[1;32m[OK]\e[0m\n"

fclean: clean
	@printf "%-50s" "deleting executable..."
	@make -C libft fclean
	@$(RM) $(NAME) $(RENDER_NAME) $(HUD) $(SPRITE)
	@printf "\e[1;32m[OK]\e[0m\n"

re: fclean all
