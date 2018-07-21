#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/30 18:43:03 by ahrytsen          #+#    #+#              #
#    Updated: 2018/07/21 12:18:12 by ahrytsen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	pipex
DIRSRC		=	./src/
DIROBJ		=	./obj/
INCLUDE		=	-I./inc/ -I./libft/includes
SUB_MAKE	=	./libft/
SUB_OBJ		=	libftprintf.a
INC_LIB		=	-L./libft -lftprintf

SRC			=	main.c\

HDR			=	inc/pipex.h
LIBFT		=	libft/libftprintf.a
OBJ			=	$(addprefix $(DIROBJ), $(SRC:.c=.o))

ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS		=
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -g
	endif
else
CFLAGS		=	-Wall -Wextra -Werror -O2
endif

CC			=	gcc
RM			=	rm -rf
ECHO		=	echo

all		:		lib $(NAME)

$(NAME)	:		$(DIROBJ) $(OBJ) $(LIBFT)
				@$(CC) $(INCLUDE) $(INC_LIB) $(CFLAGS) -O3 -o $(NAME) $(OBJ)
				@$(ECHO) "\033[31m> \033[32m"$(NAME)": Compiled\033[0m"

lib		:
				@$(MAKE) -C $(SUB_MAKE) -j3

$(LIBFT):		lib

clean	:
				@($(RM) $(DIROBJ))
ifdef SUB_MAKE
				@$(MAKE) -C $(SUB_MAKE) clean
endif
				@$(ECHO) "\033[31m> \033[33m"$(NAME)": Directory cleaned\033[0m"



fclean	:		clean
ifdef SUB_MAKE
				@$(MAKE) -C $(SUB_MAKE) fclean
endif
				-@$(RM) $(NAME)
				@$(ECHO) "\033[31m> \033[33m"$(NAME)": Executable removed\033[0m"

re		:		fclean all

.PHONY	:		all clean re

$(DIROBJ):
				@mkdir -p $(DIROBJ)

$(OBJ)	:		$(DIROBJ)%.o : $(DIRSRC)%.c $(HDR)
				@$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<
