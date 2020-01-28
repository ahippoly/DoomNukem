# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apons <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 10:56:12 by apons             #+#    #+#              #
#    Updated: 2019/10/29 09:27:11 by apons            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -I includes -I libft -I minilibx_macos
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

NAME = wolf3d

LIBDIR = libft
LIB = libft.a

MLXDIR = minilibx_macos
MLX = libmlx.a

_C = main.c\
	 src/fc_draw.c\
	 src/ft_error.c\
	 src/key_handle.c\
	 src/mlx_handle.c\
	 src/raycasting.c\
	 src/wall_draw.c\
	 src/wolf_init.c

_O = ${_C:%.c=%.o}

all: $(NAME)

$(NAME): ${_O}
	make -C $(MLXDIR)
	make -C $(LIBDIR)
	gcc $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(_O) $(LIBDIR)/$(LIB) $(MLXDIR)/$(MLX)

clean:
	make -C $(MLXDIR) clean
	make -C $(LIBDIR) clean
	/bin/rm -f $(_O)

fclean:
	/bin/rm -f $(MLXDIR)/$(MLX)
	make -C $(LIBDIR) fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
