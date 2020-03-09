# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atote <atote@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 17:58:09 by atote             #+#    #+#              #
#    Updated: 2020/03/07 19:22:32 by atote            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C:= checker
NAME_PS:= push_swap
FILE_C:= checker push_com l_add_print push_print push_free
FILE_PS:= push_swap push_al0 l_add_print push_com push_print

LFTDIR:=./libft
PFDIR:=./ft_printf

COMPILER:=gcc
SRCPATH:=sources/
HDRPATH:=includes/
IFLAGS:=-I $(HDRPATH) -I $(LFTDIR)/include
LFLAGS:=-L $(LFTDIR) -lft
PFFLAGS:=-L $(PFDIR) -lftprintf
CFLAGS:=-Wall -Wextra -Werror $(IFLAGS)

SRC_PS:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILE_PS)))
SRC_C:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILE_C)))
OBJ_C = $(CCHPATH)$(SRC_C:.c=.o)
OBJ_PS = $(CCHPATH)$(SRC_PS:.c=.o)

all: $(NAME_PS) $(NAME_C)

$(NAME_PS): $(OBJ_PS)
	@cd $(LFTDIR) && $(MAKE)
	@$(COMPILER) $(CFLAGS) $(LFLAGS) $(PFFLAGS) $(OBJ_PS) -o $(NAME_PS)

$(NAME_C): $(OBJ_C)
	@cd $(LFTDIR) && $(MAKE)
	@$(COMPILER) $(CFLAGS) $(LFLAGS) $(PFFLAGS) $(OBJ_C) -o $(NAME_C)

clean:
	@rm -f $(OBJ_C)
	@rm -f $(OBJ_PS)
	@cd $(LFTDIR) && $(MAKE) clean

fclean: clean
	@rm -f $(NAME_C)
	@rm -f $(NAME_PS)
	@cd $(LFTDIR) && $(MAKE) fclean
	
.c.o:
	gcc -Wall -Wextra -Werror -I includes/ -Ilibft -o $@ -c $<
	
re: fclean
	@$(MAKE) all

.PHONY: all clean fclean re