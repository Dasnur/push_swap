/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:54:51 by atote             #+#    #+#             */
/*   Updated: 2020/07/13 21:14:23 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../ft_printf/includes/libftprintf.h"
# include "../libft/libft.h"

typedef struct		s_lst
{
	int				value;
	struct s_lst	*next;
	int				is_color;
}					t_lst;

typedef struct		s_head
{
	t_lst			*a;
	t_lst			*b;
	int				**chunks;
	int				*sorted_args;
	char			**av;
	int				ac;
	int				chunk_size;
	
	int				flag_visual; //delete me pls
	char			*line;
}					t_head;

int					ft_printf(char *line, ...);
t_head				*init(t_head * stacks, int ac, char **argv);
void				algorithm(char** argv, int ac, t_head *stacks);
t_lst				*l_add_first(t_lst *head, int value);
void				l_print(t_lst *head);
t_lst				*l_reverse_rotate(t_lst *a);
t_lst				*l_rotate(t_lst *a);
int					l_pushb(t_head *stacks);
int					l_pusha(t_head *stacks);
t_lst				*l_swap(t_lst **h);
int					hmm(t_head *stacks);
void				al_min(t_head *stacks, int n);
int					ft_printf(char *line, ...);
void				print_all(t_head *stacks, int n);
int					check_argv(char *res);
int					check_dupl(t_lst *a, int check);
int					valid_arg(char **argv, int argc, t_head *stacks, int flag_visual);
int					exc(void);
int					find_maxi(t_lst a);
int					find_mini(t_lst a);
int					l_count_elem(t_lst *a);
void				free_all(t_head *stacks);
void				free_line(char **line);

#endif
