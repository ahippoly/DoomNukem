#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 13:12:19 by ahippoly          #+#    #+#              #
#    Updated: 2019/10/08 16:55:59 by ahippoly         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_bzero.c \
ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c \
ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strdupfree.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c \
ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_itoa.c ft_memalloc.c ft_memdel.c ft_putchar.c ft_putchar_fd.c \
ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strclr.c ft_strdel.c \
ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strjoinfree.c ft_strmap.c ft_strmapi.c ft_strnequ.c \
ft_strnew.c ft_strsplit.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_atoi.c ft_lstnew.c ft_lstdelone.c \
ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c print_memory.c ft_pow.c ft_abs.c ft_max.c ft_min.c \
ft_fmax.c ft_fmin.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc -c -I . $(SRC)
	ar rcs $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
