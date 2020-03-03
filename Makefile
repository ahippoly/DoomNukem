SRC_NAME =	$(sort editor_main.c error_gesture.c image_gesture.c \
			bresenham.c tool_sdlpoint_arithmetic.c editor_wall_add_del.c \
			editor_wall_edit.c text_img.c editor_buttons.c bmp_reader.c \
			editor_map_move.c editor_sector_creation.c line_intersect.c \
			editor_mouse_event.c editor_map_output.c utils.c \
			editor_input.c editor_map_reader.c editor_debug_utils.c \
			editor_icon.c)

RENDER_SRC_NAME = $(sort render_main.c editor_map_reader.c editor_sector_creation.c \
						error_gesture.c image_gesture.c line_intersect.c \
						tool_sdlpoint_arithmetic.c utils.c render_minimap.c \
						bresenham.c)
SRC_PATH = ./src/
OBJ_PATH = ./obj/
SDL_PATH = ./SDL2/
LIBFT_PATH = ./libft/
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
RENDER_NAME = doom-nukem

LIBFT = libft/libft.a

LDFLAGS = $(addprefix -L,$(LIBFT_PATH))

SDLM = `sdl2-config --cflags --libs`

LIBS = -lft -lm -lSDL2 

LDLIBS = -lft -lm

.PHONY: all clean fclean re libft

all: $(NAME)

libft:
	@printf "/--------------- creating library \e[1;36m$@\e[0m... ----------/\n"
	@make -C $(LIBFT_PATH)
	@printf "/---------------- library $@ created... ----------/\n"

$(NAME): libft $(OBJ)
	@printf "%-50s" "create executable "$(notdir $@)...
	@$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME) $(SDLM) $(LDFLAGS) $(LIBS)
	@printf "\e[1;32m[OK]\e[0m\n"

$(RENDER_NAME): libft $(OBJ_REND)
	@printf "%-50s" "create executable "$(notdir $@)...
	@$(CC) $(CFLAGS) $(INC) $(OBJ_REND) -o $(RENDER_NAME) -g $(SDLM) $(LDFLAGS) $(LIBS)
	@printf "\e[1;32m[OK]\e[0m\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "%-50s" "compiling "$(notdir $<)...
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(INC) -o $@ -c $<
	@printf "\e[1;32m[OK]\e[0m\n"

clean:
	@printf "%-50s" "deleting objects..." 
	@$(RM) $(OBJ) $(OBJ_REND)
	@$(RM) -r $(OBJ_PATH)
	@printf "\e[1;32m[OK]\e[0m\n"

fclean: clean
	@printf "%-50s" "deleting executable..." 
	@$(RM) $(NAME) $(RENDER_NAME)
	@printf "\e[1;32m[OK]\e[0m\n"

re: fclean all