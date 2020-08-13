/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <pgenesis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 12:02:45 by pgenesis          #+#    #+#             */
/*   Updated: 2020/07/26 18:40:48 by pgenesis         ###   ########.fr       */
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
	int				flag_visual;
	char			*line;
}					t_head;

void				completely_push_a(t_head *stacks);
void				sort_b(t_head *stacks);
void				prepare_args(t_head *stacks);
int					get_target_position(t_head *stacks, int gap_index, int value);
int					get_gap_index(t_head *stacks);
void				order_b(t_head *stacks, int value);
int					get_stack_size(t_lst *l);
void				place_holder_to_b(t_head *stacks, int current_chunk);
void				lift_up_place_holder(t_head *stacks,
					int place_holder_position);
int					get_place_holder_position(t_head *stacks, int current_chunk);
void				define_place_holders(int *place_holder_bottom,
					int *place_holder_top, t_head *stacks, int current_chunk);
void				lift_up_place_holder(t_head *stacks,
					int place_holder_position);
int					get_min_arg_index(t_lst a);
int					get_max_arg_index(t_lst a);
int					handling_unsorted_b_after_gap(int value, t_lst *tmp,
					int gap_index);
int					handling_sorted_b_case(int value, t_lst *tmp);
void				handling_case(int alg_case);
void				push_b_min(t_head *stacks);
int					get_case(t_head *stacks);
void				algorithm_2(t_head *stacks);
void				algorithm_3(t_head *stacks);
void				algorithm_4(t_head *stacks);
void				algorithm_5(t_head *stacks);
void				algorithm_over_5(t_head *stacks);
void				place_holder_to_b(t_head *stacks, int current_chunk);
void				chunks_to_b(t_head *stacks);
int					get_chunks_cnt(int ac);
int					belongs_to_chunk(int value, t_head *stacks,
					int current_chunk);
void				fill_chunks(t_head *stacks, int chunks_cnt);
void				fill_stack_a(t_head *stacks);
t_head				*init(t_head *stacks, int ac, char **argv);
int					partition(int *a, int l, int r);
void				swap(int *a, int *b);
void				quick_sort(int *a, int l, int r);
void				fill_stack_a(t_head *stacks);
void				print_com(char *res, t_head *stacks);
void				free_stack_a(t_lst *a);
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
int					exc(void);
void				free_all(t_head *stacks);
void				free_line(char **line);

#endif
