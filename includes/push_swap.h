/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:54:51 by atote             #+#    #+#             */
/*   Updated: 2020/07/26 18:08:14 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/includes/libftprintf.h"

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
	int				flag_visual;
	char			*line;
}					t_head;

int					ft_printf(char *line, ...);
t_head				*init(t_head *stacks, int ac, char **argv);
void				algorithm(int ac, t_head *stacks);
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
int					valid_arg(char **argv, int argc, t_head *stacks,
int flag_visual);
int					exc(t_head *stacks);
int					find_maxi(t_lst a);
int					find_mini(t_lst a);
int					l_count_elem(t_lst *a);
void				free_all(t_head *stacks);
void				free_line(char **line);
void				fill_stack_a(t_head *stacks);
void				algorithm_2(t_head *stacks);
void				algorithm_3(t_head *stacks);
void				algorithm_4(t_head *stacks);
void				algorithm_5(t_head *stacks);
void				quick_sort(int *a, int l, int r);
int					get_stack_size(t_lst *l);
int					get_place_holder_position(t_head *stacks,
int current_chunk);
void				place_holder_to_b(t_head *stacks,
int current_chunk);
int					get_chunks_cnt(int ac);
int					get_case(t_head *stacks);
void				handling_case(int alg_case);
int					get_min_arg_index(t_lst a);
void				push_b_min(t_head *stacks);
int					get_gap_index(t_head *stacks);
void				order_b(t_head *stacks, int value);
void				sort_b(t_head *stacks);
void				fill_chunks(t_head *stacks, int chunks_cnt);
void				print_com(char *res, t_head *stacks);
void				lift_up_place_holder(t_head *stacks,
int place_holder_position);
int					get_target_position(t_head *stacks,
int gap_index, int value);
int					belongs_to_chunk(int value, t_head *stacks,
int current_chunk);

#endif
