SRC_NAME =	$(sort \
			editor_wall_add_del.c \
			editor_wall_edit.c editor_buttons.c \
			editor_map_move.c \
			editor_mouse_event.c editor_map_output.c \
			editor_input.c editor_debug_utils.c \
			editor_icon.c editor_init_data.c editor_init_data2.c  \
			editor_display_data.c editor_grid.c editor_button_fct.c editor_button_fct2.c \
			editor_map_input.c \
			editor_map_reader.c editor_sector_creation.c \
			error_gesture.c image_gesture.c line_intersect.c \
			tool_sdlpoint_arithmetic.c utils.c render_minimap.c \
			bresenham.c render_init_data.c render_init_data2.c render_event_gesture.c \
			render_wall_processing.c render_event_poll.c render_texture_loading.c \
			text_img.c render_movement.c image_gesture2.c render_raycast.c \
			render_world_edit.c render_collide_z.c \
			render_draw_floor.c render_draw_floor2.c render_props.c render_obj.c render_draw_slice.c \
			render_ray_process.c render_pixel_put.c \
			render_icon2obj.c \
			hud_weapon.c hud_init_weapons.c hud_perso.c \
			hud_health.c hud_ammo.c hud_inv.c hud_inv1.c hud_utils.c hud_render.c \
			ttf_init.c hud_init.c \
			sprite_main.c sprite_init_gun.c sprite_init_mob.c mob_anim.c gun_anim.c sound.c \
			gameplay_mobs.c ssprite.c gameplay_props.c gameplay_weapon.c \
			bmp_reader.c \
			render_skybox.c \
			sprite_init_gun2.c sprite_init_gun3.c sprite_init_gun4.c sprite_main.c \
			menu_clean.c menu_button.c menu_render.c menu_exec.c menu_background.c hud_clean.c exit.c \
			gameover_background.c gameover_button.c gameover_render.c \
			game_render.c \
			render_game.c frame.c render_icon2obj_type.c)

GAME_MAIN = render_main.c $(SRC_NAME)

EDITOR_MAIN = editor_main.c $(SRC_NAME)


SRC_PATH = ./src/
OBJ_PATH = ./obj/
SDL_PATH = ./SDL2/
LIBFT_PATH = ./libft/
FMOD_LIB_PATH = ./FMOD/
INC_PATH = ./includes/ $(LIBFT_PATH)includes/ ./includes/SDL2/
OBJ_EDITOR_NAME = $(EDITOR_MAIN:.c=.o)
OBJ_REND_NAME = $(GAME_MAIN:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ_EDITOR = $(addprefix $(OBJ_PATH),$(OBJ_EDITOR_NAME))
OBJ_REND = $(addprefix $(OBJ_PATH),$(OBJ_REND_NAME))
INC = $(addprefix -I,$(INC_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
EDITOR_NAME = editor
GAME_NAME = doom-nukem
OPTI = -g3
PTHREAD = -lpthread

LIBFT = libft/libft.a

URL = https://drive.google.com/uc?export=download&id=1esNwBxxYwrrXUokdo6JR5H0i9vTKrj2Q

LDFLAGS = $(addprefix -L,$(LIBFT_PATH) $(FMOD_LIB_PATH))

SDLM = `sdl2-config --cflags --libs`

LIBS = -lft -lm -lSDL2 -lSDL2_ttf -lfmod

LDLIBS = -lft -lm

.PHONY: all clean fclean re libft

all: $(EDITOR_NAME) $(GAME_NAME) link_fmod

link_fmod :
	export "LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./FMOD"

libft:
	@printf "/--------------- creating library \e[1;36m$@\e[0m... ----------/\n"
	@make -C $(LIBFT_PATH)
	@printf "/---------------- library $@ created... ----------/\n"

$(EDITOR_NAME): libft $(OBJ_EDITOR)
	@printf "%-50s" "create executable "$(notdir $@)...
	@$(CC) $(CFLAGS) $(OPTI) $(INC) $(OBJ_EDITOR) -o $(EDITOR_NAME) $(SDLM) $(LDFLAGS) $(LIBS) $(PTHREAD)
	@printf "\e[1;32m[OK]\e[0m\n"

$(GAME_NAME): libft $(OBJ_REND)
	@printf "%-50s" "create executable "$(notdir $@)...
	@$(CC) $(OPTI) $(CFLAGS) $(INC) $(OBJ_REND) -o $(GAME_NAME) $(SDLM) $(LDFLAGS) $(LIBS) $(PTHREAD)
	@printf "\e[1;32m[OK]\e[0m\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "%-50s" "compiling "$(notdir $<)...
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(OPTI) $(INC) -o $@ -c $<
	@printf "\e[1;32m[OK]\e[0m\n"

clean:
	@printf "%-50s" "deleting objects..." 
	@make -C libft clean
	@$(RM) $(OBJ_EDITOR) $(OBJ_REND)
	@$(RM) -r $(OBJ_PATH)
	@printf "\e[1;32m[OK]\e[0m\n"

fclean: clean
	@printf "%-50s" "deleting executable..." 
	@make -C libft fclean
	@$(RM) $(EDITOR_NAME) $(GAME_NAME) $(HUD) $(SPRITE)
	@printf "\e[1;32m[OK]\e[0m\n"

re: fclean all
