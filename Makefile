NAME = wolf3d

SRC = main2.c raycastingPOWERED.c print_map.c \
parsing.c parsing2.c octant2.c utils.c Engine3D.c \
readfile1.c

OBJ = $(SRC:.c=.o)

SRC_PATH = srcs/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I includes

LIBFT = libft/libft.a

CC = gcc -g 

MLX = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

PTHREAD = -lpthread

SDLM = `sdl2-config --cflags --libs`

#CFLAGS = -Wall -Wextra -Werror

HEADER = -I .

SDL2 = -L lib -l SDL2

SAN = -fsanitize=address

MATH = -lm

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(HEADER) $(OBJ) -o $(NAME) $(LIBFT) $(SDLM) $(MATH)

$(LIBFT):
	make -C ./libft/

clean:
	make clean -C ./libft/
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft/
	rm -rf $(NAME)

re: fclean all
