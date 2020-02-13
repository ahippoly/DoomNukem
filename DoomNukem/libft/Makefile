define MSG
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile for Libft                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/14 19:23:44 by arsciand          #+#    #+#              #
#                                                     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
endef

# Progress bar

ifneq ($(words $(MAKECMDGOALS)),1)
.DEFAULT_GOAL = make
%:
	  @$(MAKE) $@ --no-print-directory -rRf $(firstword $(MAKEFILE_LIST))
else
ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
	  -nrRf $(firstword $(MAKEFILE_LIST)) \
	  ECHO="OutputPrintable" | grep -c "OutputPrintable")
N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo "`expr "   [\`expr $C '*' 100 / $T\`" : '.*\(....\)$$'`%]"
endif

# Color

RESET_C = \033[m
B_C = \033[0;34m
Y_C = \033[0;33m
G_C = \033[0;32m
R_C = \033[0;31m
M_C = \033[0;35m
C_C = \033[0;36m

# Programms names

NAME = libft.a
HNAME = libft.h
TNAME = Libft_test

# Dir/Files Path

S_PATH = ./srcs/
H_PATH = ./includes/
B_PATH = ./build/
O_PATH = ./build/objs/


# Files

SRC += $(S_PATH)ft_atoi.c
SRC += $(S_PATH)ft_bzero.c
SRC += $(S_PATH)ft_isalnum.c
SRC += $(S_PATH)ft_isalpha.c
SRC += $(S_PATH)ft_isascii.c
SRC += $(S_PATH)ft_isdigit.c
SRC += $(S_PATH)ft_isprint.c
SRC += $(S_PATH)ft_itoa.c
SRC += $(S_PATH)ft_lstadd.c
SRC += $(S_PATH)ft_lstdel.c
SRC += $(S_PATH)ft_lstdelone.c
SRC += $(S_PATH)ft_lstiter.c
SRC += $(S_PATH)ft_lstsize.c
SRC += $(S_PATH)ft_lstmap.c
SRC += $(S_PATH)ft_lstmerge.c
SRC += $(S_PATH)ft_lstnew.c
SRC += $(S_PATH)ft_memalloc.c
SRC += $(S_PATH)ft_memccpy.c
SRC += $(S_PATH)ft_memchr.c
SRC += $(S_PATH)ft_memcmp.c
SRC += $(S_PATH)ft_memcpy.c
SRC += $(S_PATH)ft_memdel.c
SRC += $(S_PATH)ft_memmove.c
SRC += $(S_PATH)ft_memset.c
SRC += $(S_PATH)ft_putchar_fd.c
SRC += $(S_PATH)ft_putchar.c
SRC += $(S_PATH)ft_putendl_fd.c
SRC += $(S_PATH)ft_putendl.c
SRC += $(S_PATH)ft_putnbr_fd.c
SRC += $(S_PATH)ft_putnbr.c
SRC += $(S_PATH)ft_putstr_fd.c
SRC += $(S_PATH)ft_putstr.c
SRC += $(S_PATH)ft_strcat.c
SRC += $(S_PATH)ft_strchr.c
SRC += $(S_PATH)ft_strclr.c
SRC += $(S_PATH)ft_strcmp.c
SRC += $(S_PATH)ft_strcpy.c
SRC += $(S_PATH)ft_strdup.c
SRC += $(S_PATH)ft_strdel.c
SRC += $(S_PATH)ft_strequ.c
SRC += $(S_PATH)ft_striter.c
SRC += $(S_PATH)ft_striteri.c
SRC += $(S_PATH)ft_strjoin.c
SRC += $(S_PATH)ft_strlcat.c
SRC += $(S_PATH)ft_strlen.c
SRC += $(S_PATH)ft_strncat.c
SRC += $(S_PATH)ft_strncmp.c
SRC += $(S_PATH)ft_strncpy.c
SRC += $(S_PATH)ft_strnequ.c
SRC += $(S_PATH)ft_strnew.c
SRC += $(S_PATH)ft_strnstr.c
SRC += $(S_PATH)ft_strmap.c
SRC += $(S_PATH)ft_strmapi.c
SRC += $(S_PATH)ft_strrchr.c
SRC += $(S_PATH)ft_strsplit.c
SRC += $(S_PATH)ft_strstr.c
SRC += $(S_PATH)ft_strsub.c
SRC += $(S_PATH)ft_strtrim.c
SRC += $(S_PATH)ft_tolower.c
SRC += $(S_PATH)ft_toupper.c
SRC += $(S_PATH)get_next_line.c
SRC += $(S_PATH)ft_putnbr_base.c
SRC += $(S_PATH)ft_putnbr_base_fd.c
SRC += $(S_PATH)ft_atoi_base.c
SRC += $(S_PATH)ft_convert_base.c 
SRC += $(S_PATH)ft_lst_push_back.c
SRC += $(S_PATH)ft_create_elem.c
SRC += $(S_PATH)ft_strfjoin.c
SRC += $(S_PATH)ft_tablen.c
SRC += $(S_PATH)ft_isbetween.c
SRC += $(S_PATH)ft_abs.c
SRC += $(S_PATH)ft_tabfree.c
SRC += $(S_PATH)ft_max.c
SRC += $(S_PATH)ft_min.c

# Objects and Headers

OBJ = $(patsubst $(S_PATH)%.c, $(O_PATH)%.o, $(SRC))
HDR = $(H_PATH)$(HNAME)

# Variables

C_GCC = gcc
COMPL = $(C_GCC) -c -I$(H_PATH)
BUILD = $(B_PATH) $(O_PATH)
AR_RC = ar rc
RANLI = ranlib
CFLAG = -Wall -Wextra -Werror
RM_RF = /bin/rm -rf
MKDIR = mkdir -p
NORME = norminette
GCFIL = "\t- >\tCompiling\t-"
GCLAR = "\t- }\tArchiving\t-"
GCLIN = "\t- =t\Linking\t-"
GCIND = "\t- *\tIndexing\t-"
RMSHW = "\t- -\tRemoving\t-"
MKSHW = "\t- +\tCreating\t-"
DLSHW = "\t- ~\tDownloading\t-"
EXSHW = "\t- .\tExecuting\t-"
GCRUN = echo "$(G_C)===========>\tCompilation\t RUNNING$(RESET_C)"
GCSUC = "$(G_C)====>\tCompilation\t SUCCESS$(RESET_C)"
CLRUN = echo "$(R_C)===========>\tCleanup\t\t RUNNING$(RESET_C)"
CLSUC = "$(R_C)====>\tCleanup\t\t SUCCESS$(RESET_C)"
FCRUN = echo "$(R_C)===========>\tForce Cleanup\t RUNNING$(RESET_C)"
FCSUC = "$(R_C)====>\tForce Cleanup\t SUCCESS$(RESET_C)"
NORMR = echo "$(Y_C)===========>\tNorminette\t RUNNING$(RESET_C)"
NORMD = "$(G_C)====>\tNorminette\t DONE$(RESET_C)"
TESTR = echo "$(M_C)===========>\tTESTS\t\t RUNNING$(RESET_C)"
TESTD = "$(M_C)====>\tTESTS\t\t DONE$(RESET_C)"

.PHONY: all norme clean fclean re test

# Rules

make:
	@$(MSG)
	@$(MAKE) --no-print-directory all

all: $(BUILD) $(NAME)

$(NAME): $(OBJ)
	@$(AR_RC) $(NAME) $^
	@$(ECHO) $(GCLAR) $@
	@$(RANLI) $(NAME)
	@$(ECHO) $(GCIND) $@
	@$(ECHO) $(GCSUC)

$(OBJ): $(O_PATH)%.o: $(S_PATH)%.c $(HDR)
	@$(COMPL) $(CFLAG) $< -o $@
	@$(ECHO) $(GCFIL) $@


$(B_PATH):
	@$(GCRUN)
	@$(MKDIR) $(B_PATH)
	@$(ECHO) $(MKSHW) $(B_PATH)

$(O_PATH):
	@$(MKDIR) $(O_PATH)
	@$(ECHO) $(MKSHW) $(O_PATH)

norme:
	@$(NORMR)
	@$(NORME) $(SRC) $(H_PATH)$(HNAME)
	@$(ECHO) $(NORMD)

clean:
	@$(CLRUN)
	@$(RM_RF) $(OBJ)
	@$(ECHO) $(RMSHW) $(O_PATH)*.o
	@$(ECHO) $(CLSUC)

fclean:
	@$(FCRUN)
	@$(RM_RF) $(OBJ)
	@$(ECHO) $(RMSHW) $(O_PATH)*.o
	@$(ECHO) $(RMSHW) *.o
	@$(RM_RF) $(O_PATH)
	@$(ECHO) $(RMSHW) $(O_PATH)
	@$(RM_RF) $(B_PATH)
	@$(ECHO) $(RMSHW) $(B_PATH)
	@$(RM_RF) $(NAME)
	@$(ECHO) $(RMSHW) $(NAME)
	@$(ECHO) $(FCSUC)

test:
	@$(TESTR)
	@git clone -q https://github.com/acuD1/$(TNAME).git $(B_PATH)test
	@$(ECHO) $(DLSHW) $(TNAME)
	@echo "$(Y_C)STILL IN BETA : Go to build/test and modify Makefile \
		manually fear each test_*.c and run make re (IF TEST AVAILABLE)$(RESET_C)"
	@$(ECHO) $(TESTD)


re:
	@$(MAKE) --no-print-directory fclean all

endif
