# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atote <atote@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 17:58:09 by atote             #+#    #+#              #
#    Updated: 2020/07/26 18:45:25 by atote            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C:= checker
NAME_PS:= push_swap
FILE_C:= checker push_com l_add_print push_print push_free init_fill_a
FILE_PS:= push_swap push_al0 l_add_print push_com push_print init_fill_a algorithms_under_5 algorithms_under_5_help quick_sort_das get_target_position order_b chunks_operators place_holders

LFTDIR:=./libft
PFDIR:=./ft_printf

COMPILER:=clang
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
	@cd $(PFDIR) && $(MAKE)
	@$(COMPILER) $(CFLAGS) $(OBJ_PS) -o $(NAME_PS) $(LFLAGS) $(PFFLAGS)

$(NAME_C): $(OBJ_C)
	@cd $(LFTDIR) && $(MAKE)
	@cd $(PFDIR) && $(MAKE)
	@$(COMPILER) $(CFLAGS) $(OBJ_C) -o $(NAME_C) $(LFLAGS) $(PFFLAGS)

clean:
	@rm -f $(OBJ_C)
	@rm -f $(OBJ_PS)
	@cd $(LFTDIR) && $(MAKE) clean
	@cd $(PFDIR) && $(MAKE) clean

fclean: clean
	@rm -f $(NAME_C)
	@rm -f $(NAME_PS)
	@cd $(LFTDIR) && $(MAKE) fclean
	@cd $(PFDIR) && $(MAKE) fclean
	
.c.o:
	clang -Wall -Wextra -Werror -I includes/ -Ilibft -o $@ -c $<
	
re: fclean
	@$(MAKE) all

.PHONY: all clean fclean re