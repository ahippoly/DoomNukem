# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apons <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/25 15:33:28 by apons             #+#    #+#              #
#    Updated: 2019/10/25 16:18:05 by apons            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

_C = ft_abs.c\
	ft_atoi.c\
	ft_atoi_base.c\
	ft_bzero.c\
	ft_count.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
	ft_itoa_base.c\
	ft_joindel.c\
	ft_max.c\
	ft_memalloc.c\
	ft_memccpy.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memdel.c\
	ft_memmove.c\
	ft_memset.c\
	ft_min.c\
	ft_power_x.c\
	ft_putchar.c\
	ft_putchar_fd.c\
	ft_putendl.c\
	ft_putendl_fd.c\
	ft_putnbr.c\
	ft_putnbr_fd.c\
	ft_putstr.c\
	ft_putstr_fd.c\
	ft_square.c\
	ft_strcat.c\
	ft_strchr.c\
	ft_strchrpos.c\
	ft_strclr.c\
	ft_strcmp.c\
	ft_strcpy.c\
	ft_strdel.c\
	ft_strdup.c\
	ft_strequ.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlen.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strncat.c\
	ft_strncmp.c\
	ft_strncpy.c\
	ft_strndup.c\
	ft_strnequ.c\
	ft_strnew.c\
	ft_strnstr.c\
	ft_strrev.c\
	ft_strrchr.c\
	ft_strsplit.c\
	ft_strstr.c\
	ft_strsub.c\
	ft_strtrim.c\
	ft_swap.c\
	ft_tabcpy.c\
	ft_tabfree.c\
	ft_tablen.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_valcpy.c\
	ft_valfree.c\
	ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstdel.c\
	ft_lstadd.c\
	ft_lstiter.c\
	ft_lstmap.c\
	get_next_line.c

_O = ${_C:%.c=%.o}

all : $(NAME)

$(NAME): $(_O)
	ar rcs $(NAME) $(_O)

clean:
	/bin/rm -f $(_O)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
