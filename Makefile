EDITOR_NAME = editor

GAME_NAME = doom-nukem

SRC_NAME =	$(sort \
			editor_wall_add_del.c editor_wall_add_del2.c \
			editor_wall_edit.c editor_buttons.c \
			editor_map_move.c \
			editor_mouse_event.c editor_mouse_event2.c editor_map_output.c editor_map_output2.c\
			editor_input.c editor_input2.c editor_debug_utils.c \
			editor_icon.c editor_icon2.c editor_init_data.c editor_init_data2.c editor_init_data3.c \
			editor_display_data.c editor_display_data2.c editor_grid.c editor_button_fct.c editor_button_fct2.c \
			editor_map_input.c \
			parser_map.c parser_map2.c parser_map3.c parser_map4.c \
			editor_sector_creation.c editor_sector_creation2.c editor_sector_creation3.c \
			editor_key_event.c \
			error_gesture.c image_gesture.c line_intersect.c \
			tool_sdlpoint_arithmetic.c utils.c render_minimap.c render_minimap2.c \
			bresenham.c render_init_data.c render_init_data2.c render_event_gesture.c \
			render_event_poll.c render_texture_loading.c \
			text_img.c render_movement.c render_movement_utils.c render_gravity.c image_gesture2.c render_raycast.c render_raycast_utils.c\
			render_collide_z.c \
			render_draw_floor.c render_draw_floor2.c render_props.c render_obj.c render_obj_convert.c render_draw_slice.c \
			render_ray_process.c render_pixel_put.c \
			render_icon2obj.c \
			hud_weapon.c hud_init_weapons.c hud_perso.c \
			hud_health.c hud_ammo.c hud_inv.c hud_inv1.c hud_utils.c hud_render.c \
			ttf_init.c hud_init.c \
			sprite_main.c sprite_init_gun.c gun_anim.c sound.c \
			gameplay_mobs.c ssprite.c gameplay_props.c gameplay_weapon.c \
			bmp_reader.c bmp_reader2.c bmp_reader3.c\
			render_skybox.c render_ray_utils.c\
			sprite_init_gun2.c sprite_init_gun3.c sprite_init_gun4.c sprite_main.c \
			menu_clean.c menu_button.c menu_render.c menu_exec.c menu_background.c hud_clean.c exit.c \
			gameover_background.c gameover_button.c gameover_render.c \
			game_render.c \
			render_game.c frame.c render_icon2obj_type.c \
			clean_data.c clean_editor.c \
			malloc_env.c malloc_env1.c malloc_data.c \
			sdl_init.c utils2.c utils3.c utils4.c utils5.c utils6.c sprite_init.c sprite_init_mob.c \
			copy_frame.c tool_sdlpoint_arithmetic2.c)

GAME_MAIN = render_main.c $(SRC_NAME)

EDITOR_MAIN = editor_main.c $(SRC_NAME)

## Folders paths 

SRC_PATH = ./src/
OBJ_PATH = ./obj/
SDL_PATH = ./SDL2/
LIBFT_PATH = ./libft/
FMOD_LIB_PATH = ./FMOD/
ASSETS_PATH = ./asset/
FONT_DIR = font/
IMG_DIR = img/
SOUND_DIR = sound/
INC_PATH = ./includes/ $(LIBFT_PATH)includes/ ./includes/SDL2/
OBJ_EDITOR_NAME = $(EDITOR_MAIN:.c=.o)
OBJ_REND_NAME = $(GAME_MAIN:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ_EDITOR = $(addprefix $(OBJ_PATH),$(OBJ_EDITOR_NAME))
OBJ_REND = $(addprefix $(OBJ_PATH),$(OBJ_REND_NAME))
INC = $(addprefix -I,$(INC_PATH))
ASSETS = $(addprefix $(ASSETS_PATH), $(FONT_DIR) $(IMG_DIR) $(SOUND_DIR))
LIBFT = $(addprefix $(LIBFT_PATH), libft.a)
LDFLAGS = $(addprefix -L,$(LIBFT_PATH) $(FMOD_LIB_PATH))

INSTALL_LIBS = $(FMOD) $(SDL)

FMOD_WINDOWS = /usr/lib/fmod.dll /usr/lib/fmodL.dll

FMOD_OSX = /usr/local/lib/libfmod.dylib /usr/local/lib/libfmodL.dylib

FMOD_LINUX = /usr/lib/libfmod.so /usr/lib/libfmodL.so \
			 /usr/lib/libfmod.so.11 /usr/lib/libfmodL.so.11 \
			 /usr/lib/libfmod.so.11.9 /usr/lib/libfmodL.so.11.9

SED = sed

## Flags

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OPTI = -O3
PTHREAD = -lpthread
SDLM = `sdl2-config --cflags --libs`
LIBS = -lft -lm -lSDL2 -lSDL2_ttf -lfmod
LDLIBS = -lft -lm

ifeq ($(OS),Windows_NT)
	FMOD = $(FMOD_WINDOWS)
else
	UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	FMOD = $(FMOD_OSX)
	SED = gsed	
else 
	FMOD = $(FMOD_LINUX)
	endif	
endif

.PHONY: all clean fclean re libft

all: $(EDITOR_NAME) $(GAME_NAME) $(ASSETS) $(FMOD)

libft:
	@printf "/--------------- creating library \e[1;36m$@\e[0m... ----------/\n"
	@make -C $(LIBFT_PATH)
	@printf "/---------------- library $@ created... ----------/\n"

$(EDITOR_NAME): libft $(OBJ_EDITOR) $(ASSETS)
	@printf "%-50s" "create executable "$(notdir $@)...
	@$(CC) $(CFLAGS) $(OPTI) $(INC) $(OBJ_EDITOR) -o $(EDITOR_NAME) $(SDLM) $(LDFLAGS) $(LIBS) $(PTHREAD)
	@printf "\e[1;32m[OK]\e[0m\n"

$(GAME_NAME): libft $(OBJ_REND) $(ASSETS)
	@printf "%-50s" "create executable "$(notdir $@)...
	@$(CC) $(OPTI) $(CFLAGS) $(INC) $(OBJ_REND) -o $(GAME_NAME) $(SDLM) $(LDFLAGS) $(LIBS) $(PTHREAD)
	@printf "\e[1;32m[OK]\e[0m\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "%-50s" "compiling "$(notdir $<)...
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(OPTI) $(INC) -o $@ -c $<
	@printf "\e[1;32m[OK]\e[0m\n"

$(ASSETS) :
	@printf "\e[1;32m[Downloading assets]\e[0m\n"
	@wget -r -q --show-progress --load-cookies /tmp/cookies.txt \
	"https://docs.google.com/uc?export=download&confirm=$$(wget --quiet $\
	--save-cookies /tmp/cookies.txt --keep-session-cookies $\
	--no-check-certificate 'https://docs.google.com/uc?export=download&id=$\
	1sHmOhbsu_q6ltr4AYTg8bkOsn2hoGeGp' -O- | $(SED) -rn $\
	's/.*confirm=([0-9A-Za-z_]+).*/\1\n/p')\
	&id=1sHmOhbsu_q6ltr4AYTg8bkOsn2hoGeGp" -O asset.tar.gz \
	&& rm -rf /tmp/cookies.txt
	@printf "\e[1;32m[Extracting assets]\e[0m\n"
	@tar xf asset.tar.gz
	@rm -rf asset.tar.gz

$(FMOD_WINDOWS):
	@sudo cp FMOD/fmod.dll /usr/lib/
	@sudo cp FMOD/fmodL.dll /usr/lib/

$(FMOD_LINUX):
	@sudo cp FMOD/libfmod.so /usr/lib/
	@sudo cp FMOD/libfmod.so.11 /usr/lib/
	@sudo cp FMOD/libfmod.so.11.9 /usr/lib/
	@sudo cp FMOD/libfmodL.so /usr/lib/
	@sudo cp FMOD/libfmodL.so.11 /usr/lib/
	@sudo cp FMOD/libfmodL.so.11.9 /usr/lib/

$(FMOD_OSX):
	@sudo cp FMOD/libfmod.dylib /usr/local/lib
	@sudo cp FMOD/libfmodL.dylib /usr/local/lib

SDL :
	@printf "\e[1;32m[Configure SDL2]\e[0m\n"
	@./configure
	@printf "\e[1;32m[Make SDL2]\e[0m\n"
	@make
	@sudo make install

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