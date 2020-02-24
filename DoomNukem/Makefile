# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 18:53:52 by saneveu           #+#    #+#              #
#    Updated: 2020/02/10 13:55:51 by apons            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK	=	\033[30m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
PURPLE	=	\033[35m
TUR		=	\033[36m
WHITE	=	\033[37m
END		=	\033[0m

UP 		=	\033[A
CUT 	=	\033[K

# project
NAME	=	DoomNukem
OS		=	$(shell uname)

# directories
SRCDIR	=	./src
INCDIR	=	./includes
OBJDIR	=	./obj

# src / obj files
SRC		=	main.c \
			color_tool.c \
			display.c \
			event_ft.c \
			event.c \
			exit.c \
			fc_draw.c\
			fog.c \
			ft_error.c \
			ft_freewolf.c \
			ft_help.c \
			get_enemy_sheets.c \
			get_enemy_sheets2.c \
			get_enemy.c \
			get_weapon.c \
			handle_status_effects.c \
			handle_weapon_fire.c \
			init_game.c \
			mobility.c\
			mouse_event.c \
			perform_attack.c \
			pixel.c \
			raycasting.c \
			resolve_damage.c \
			shortcuts.c \
			wall_draw.c \
			weapon_draw.c \
			wolf_init.c \

INC		=	wolf3d.h

OBJ		=	$(addprefix $(OBJDIR)/,$(SRC:.c=.o))
HEADER	=	$(addprefix $(INCDIR)/,$(INC))

# compiler
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -pipe -Ofast -march=native

ifeq ($(OS), Linux)
	SDL		=	-lSDL2-2.0 -lSDL2_ttf
	DIRSDL	=	
else
	SDL		=	-F ~/Library/Frameworks -framework SDL2 -framework SDL2_ttf
	DIRSDL	=	-I ./SDL
endif 

# ft library
FT		=	./libft/
FT_LIB	=	$(addprefix $(FT),libft.a)

all: 		obj $(FT_LIB) $(NAME)

obj:
			mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c $(HEADER)
			@echo "${TUR}compiling [$@] ...${END}"
			@$(CC) $(CFLAGS) -I $(INCDIR) -c -o $@ $< $(DIRSDL)
			@printf "$(UP)$(CUT)"

$(FT_LIB):
			@$(MAKE) -C $(FT)
			@echo "${GREEN}[LIBRARY COMPILED]${END}"

$(NAME):	$(OBJ) $(FT_LIB)
			@$(CC) $(CFLAGS) $(OBJ) $(FT_LIB) $(SDL) -lm -lpthread -o $@
			@echo "${GREEN}[$@ COMPILED]${END}"

clean:
			@/bin/rm -rf $(OBJDIR)
			@$(MAKE) -C $(FT) clean
			@echo "${PURPLE}[.o deleted]${END}"

fclean:		clean
			@/bin/rm -rf $(NAME)
			@$(MAKE) -C $(FT) fclean
			@echo "${RED}[$(NAME) deleted]${END}"
			@echo "${RED}[$(LIB) deleted]${END}"

re:			fclean all

SDL2:
			brew install sdl2
			brew link sdl2
			brew install sdl2_ttf
			brew link sdl2_ttf
			brew install sdl2_mixer
			brew link sdl2_mixer
			cp -rf framework/SDL2_mixer.framework ~/Library/Frameworks
			cp -rf framework/SDL2_ttf.framework ~/Library/Frameworks
			cp -rf framework/SDL2.framework ~/Library/Frameworks

.PHONY:		all clean fclean re
