# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atote <atote@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 17:58:09 by atote             #+#    #+#              #
#    Updated: 2020/03/04 17:58:11 by atote            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= checker
NAME_PW:= push_swap
FILE_C:= ft_checker
FILE_PW:= ft_push_swap 
FILES:= pw_helper_1 pw_helper_2 pw_sort_data \
		pw_operators pw_print pw_sort_simple ch_operators \
		pw_sort_backtrack_1 pw_sort_backtrack_2

LFTDIR:=./libft

COMPILER:=clang
LINKER:=ar rc
SRCPATH:=src/
HDRPATH:=include/
CCHPATH:=obj/
IFLAGS:=-I $(HDRPATH) -I $(LFTDIR)/include
LFLAGS:=-L $(LFTDIR) -lft
CFLAGS:=-Wall -Wextra -Werror $(IFLAGS)

# ------ Auto ------
SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
SRC_PW:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILE_PW)))
SRC_C:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILE_C)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
OBJ_C:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILE_C)))
OBJ_PW:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILE_PW)))
# ==================
CCHF:=.cache_exists

all: $(NAME_PW) $(NAME)

$(NAME): $(OBJ) $(OBJ_C)
	@cd $(LFTDIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(COMPILER) $(CFLAGS) $(SRC) $(LFLAGS) $(SRCPATH)$(FILE_C).c -o $(NAME)
	@echo $(GREEN) " - OK" $(EOC)

$(NAME_PW): $(OBJ) $(OBJ_PW)
	@cd $(LFTDIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(COMPILER) $(CFLAGS) $(SRC) $(LFLAGS) $(SRC_PW) -o $(NAME_PW)
	@echo $(GREEN) " - OK" $(EOC)

$(CCHPATH)%.o: $(SRCPATH)%.c | $(CCHF)
	@echo $(PURPLE) " - Compiling $< into $@" $(EOC)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

%.c:
	@echo $(RED)"Missing file : $@" $(EOC)

$(CCHF):
	@mkdir $(CCHPATH)
	@touch $(CCHF)

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)
	@cd $(LFTDIR) && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_PW)
	@rm -rf $(NAME).dSYM/
	@rm -rf $(NAME_PW).dSYM/
	@cd $(LFTDIR) && $(MAKE) fclean

re: fclean
	@$(MAKE) all

test: $(NAME) $(NAME_PW)
	@$(COMPILER) -g -w $(CFLAGS) $(SRC_C) $(SRC) $(LFLAGS) -o checker
	@$(COMPILER) -g -w $(CFLAGS) $(SRC_PW) $(SRC) $(LFLAGS) -o push_swap
	@./push_swap $(ARG) | ./checker $(OPT) $(ARG)

test_ch: $(NAME)
	@$(COMPILER) -g -w $(CFLAGS) $(SRC_C) $(SRC) $(LFLAGS) -o checker
	@./push_swap $(ARG) | ./checker $(ARG)

test_pw: $(NAME_PW)
	@$(COMPILER) -g -w $(CFLAGS) $(SRC_PW) $(SRC) $(LFLAGS) -o push_swap
	@ ./push_swap $(ARG)
	@ echo $(ARG) > input.txt
	
debug_pw: $(NAME_PW)
	@$(COMPILER) -g -w $(CFLAGS) $(SRC_PW) $(SRC) $(LFLAGS) -o push_swap
	@ ./push_swap $(OPT) $(ARG)
	@ echo $(ARG) > input.txt

debug: $(NAME) $(NAME_PW)
	@$(COMPILER) -g $(IFLAGS) $(SRC_C) $(SRC) $(LFLAGS) -o checker
	@$(COMPILER) -g $(IFLAGS) $(SRC_PW) $(SRC) $(LFLAGS) -o push_swap

check: check_leak check_error check_ko check_ok check_pw

check_leak: $(NAME) $(NAME_PW)
	valgrind ./push_swap 2>&1 | grep lost
	valgrind ./push_swap "1 2" 2>&1 | grep lost
	valgrind ./push_swap "2 2" 2>&1 | grep lost
	valgrind ./push_swap "a 2" 2>&1 | grep lost
	valgrind ./push_swap "2147483649" 2>&1 | grep lost
	echo "sa" | valgrind ./checker 2>&1 | grep lost
	echo "sa" | valgrind ./checker 1 2 2>&1 | grep lost
	echo "sa" | valgrind ./checker "2 2" 2>&1 | grep lost
	echo "sa" | valgrind ./checker "a 2" 2>&1 | grep lost
	echo "sa" | valgrind ./checker "2147483649" 2>&1 | grep lost
	echo "sa " | valgrind ./checker "1 2" 2>&1 | grep lost
	echo "  sa" | valgrind ./checker "1 2" 2>&1 | grep lost
	echo "sa" | valgrind ./checker -v "1 2" 2>&1 | grep lost
	echo "sa" | valgrind ./checker -vact "1 2" 2>&1 | grep lost
	echo "sa" | valgrind ./checker -g "1 2" 2>&1 | grep lost
	ARG=`ruby -e "puts (1..30).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | valgrind ./checker -t $$ARG 2>&1 | grep lost
	ARG=`ruby -e "puts (1..30).to_a.shuffle.join(' ')"`; valgrind ./push_swap $$ARG 2>&1 | grep lost

.PHONY: all clean fclean re test norme test_ch test_pw debug check