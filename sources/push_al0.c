/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_al0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:23:16 by atote             #+#    #+#             */
/*   Updated: 2020/07/11 21:57:41 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		l_count_elem(t_lst *a)
{
	int		i;
	t_lst	*tmp;

	tmp = a;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	print_com(char *res, t_head *stacks)
{
	if (ft_strcmp(res, "rb") == 0)
	{
		stacks->b = l_rotate(stacks->b);
		ft_putstr("rb\n");
	}
	if (ft_strcmp(res, "rrb") == 0)
	{
		stacks->b = l_reverse_rotate(stacks->b);
		ft_putstr("rrb\n");
	}
	if (ft_strcmp(res, "ra") == 0)
	{
		stacks->a = l_rotate(stacks->a);
		ft_putstr("ra\n");
	}
	if (ft_strcmp(res, "rra") == 0)
	{
		stacks->a = l_reverse_rotate(stacks->a);
		ft_putstr("rra\n");
	}
	if (ft_strcmp(res, "pa") == 0)
	{
		ft_putstr("pa\n");
		l_pusha(stacks);
	}
}

void	al_min_help1(t_head *stacks, int *countshag)
{
	int		t;
	int		mini;

	while (l_count_elem(stacks->b))
	{
		mini = find_maxi(*stacks->b);
		if (mini > ((l_count_elem(stacks->b)) / 2))
			t = l_count_elem(stacks->b) - mini;
		else
			t = mini;
		while (t > 0)
		{
			if (mini > ((l_count_elem(stacks->b)) / 2))
				print_com("rrb", stacks);
			else
				print_com("rb", stacks);
			t--;
		}
		l_pusha(stacks);
		ft_putstr("pa\n");
		if (*countshag == 0)
			print_com("ra", stacks);
	}
	*countshag = *countshag + 1;
}

void	al_min_help2(t_head *stacks)
{
	int		mini;
	int		t;

	mini = find_mini(*stacks->a);
	if (mini > ((l_count_elem(stacks->a)) / 2))
		t = l_count_elem(stacks->a) - mini;
	else
		t = mini;
	while (t > 0)
	{
		if (mini > ((l_count_elem(stacks->a)) / 2))
			print_com("rra", stacks);
		else
			print_com("ra", stacks);
		t--;
	}
	l_pushb(stacks);
	ft_putstr("pb\n");
}

void	fill_stack_a(t_head *stacks) {
	int	i;

	i = 0;
	while (i < stacks->ac - 1) {
		stacks->a = l_add_first(stacks->a, ft_atoi(stacks->av[stacks->ac - 1])); 
		i++;
	}
}

void	fill_chunks(t_head *stacks, int chunks_cnt) {
	int	i;
	int	k;
	int	j;

	j = 0;
	k = 0;
	i = 0;
	stacks->chunks = (int**)malloc(sizeof(int*) * chunks_cnt);
	while (i < chunks_cnt) 
	{
		stacks->chunks[i] = (int *)malloc(sizeof(int) * (stacks->chunk_size));
		while (k < (stacks->chunk_size))
		{
			if (j >= stacks->ac - 1)
				stacks->chunks[i][k] = 0;
			else
				stacks->chunks[i][k] = stacks->sorted_args[j];
			j++;
			k++;
		}
		k = 0;
		i++;
	}
}

int		belongs_to_chunk(int value, t_head *stacks, int current_chunk) {
	int	i;
	
	i = 0;
	while (i < stacks->chunk_size) {
		if (value == stacks->chunks[current_chunk][i])
			return 1;
		i++;
	}
	return 0;
}

int		get_stack_size(t_lst *l) {
	t_lst	*tmp;
	int		size;

	size = 0;
	tmp = l;
	while (tmp) {
		size++;
		tmp = tmp->next;
	}
	return size;
}

int		get_place_holder_position(t_head *stacks, int current_chunk) {
	int	place_holder_top;
	int	place_holder_bottom;
	int	i;
	t_lst *tmp;

	i = 0;
	place_holder_bottom = -1;
	place_holder_top = -1;
	tmp = stacks->a;
	while (tmp) {
		if (belongs_to_chunk(tmp->value, stacks, current_chunk))
		{
			if (place_holder_top == -1)
				place_holder_top = i;
			place_holder_bottom = i;
		}
		i++;
		tmp = tmp->next;
	}
	if (get_stack_size(stacks->a) - place_holder_bottom < place_holder_top)
		return (get_stack_size(stacks->a) - place_holder_bottom);
	return place_holder_top;
}

int		get_gap_index(t_head *stacks) {
	int		gap_index;
	t_lst	*tmp;
	
	tmp = stacks->b;
	gap_index = 1;
	while (tmp->next) {
		if (tmp->value > tmp->next->value)
			return gap_index;
		gap_index++;
	}
	return 0;
}

int		handling_sorted_b_case(int gap_index, int value, t_lst *tmp)
{
	int	i;

	i = 0;	 
	while (value < tmp->value) 
	{
		tmp = tmp->next;
		i++;
	}
	return i;
}

int		handling_unsorted_b_after_gap(int value, t_lst *tmp, int gap_index)
{
	int	i;

	i = 0;
	while (i != gap_index) 
	{
		tmp = tmp->next;
		i++;
	}
	while (value < tmp->value) 
	{
		tmp = tmp->next;
		i++;
	}
	return i;
}

int		get_target_position(t_head *stacks, int gap_index, int value) 
{
	int	i;
	t_lst	*tmp;

	tmp = stacks->b;
	i = 0;
	if (gap_index == 0)
		handling_sorted_b_case(gap_index, value, tmp);
	if (value > tmp->value) 
		handling_unsorted_b_after_gap(value, tmp, gap_index);
	else
	{
		while (value < tmp->value && i < gap_index) 
		{
			tmp = tmp->next;
			i++;
		}
		return i;
	}
}

void	order_b(t_head *stacks, int value) 
{
	int		gap_index;
	t_lst	*tmp;
	int		i;
	int		position;

	i = 0;
	tmp = stacks->b;
	gap_index = get_gap_index(stacks);
	position = get_target_position(stacks, gap_index, value);
	
}

void	place_holder_to_b(t_head *stacks, int current_chunk) {
	int	place_holder_position;

	place_holder_position = get_place_holder_position(stacks, current_chunk);
	// двигаем на топ
	order_b(stacks, stacks->a->value);
}

void	algorithm_over_5(t_head *stacks) {
	int	chunks_cnt;
	int	current_chunk;
	int	i;
	
	current_chunk = 0;
	stacks->sorted_args = (int *)malloc(sizeof(int) * stacks->ac);
	stacks->sorted_args = quick_sort(stacks->av); // не готово
	fill_stack_a(stacks);
	i = 1;
	chunks_cnt = get_chunks_cnt(stacks->ac); // не готово +100 делить на 6
	stacks->chunk_size = stacks->ac / chunks_cnt;
	fill_chunks(stacks, chunks_cnt); // have to malloc args, last massive must be null terminated;
	while (stacks->a) 
	{
		if (i == stacks->chunk_size) 
		{
			i = 1;
			current_chunk++;
		}
		place_holder_to_b(stacks, current_chunk); // не готово
		i++;
	}
	sort_b(stacks);
	while (i < stacks->ac) 
	{
		ft_putstr("pa\n");
		i++;
	}
}

void	algorithm(char** argv, int ac)
{
	t_head	*stacks;
	int		i;
	
	i = 0;
	stacks->ac = ac;
	stacks->av = argv;
	stacks = (t_head*)malloc(sizeof(t_head));
	stacks->a = NULL;
	stacks->b = NULL;
	// while (i < ac - 1) {
	// 	stacks->a = l_add_first(stacks->a, ft_atoi(argv[ac - 1])); // засунуть внутрь всех алгоритмов ниже;
	// 	i++;
	// }
	if (ac < 4) {
		algorithm_3(stacks);	
	}
	else if (ac < 7) {
		algorithm_5(stacks);
	}
	else {
		algorithm_over_5(stacks);
	}
}
