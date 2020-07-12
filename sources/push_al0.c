/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_al0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:23:16 by atote             #+#    #+#             */
/*   Updated: 2020/07/12 19:25:36 by atote            ###   ########.fr       */
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

void	fill_stack_a(t_head *stacks)
{
	int	i;
	int	k;

	k = 0;
	i = stacks->ac;
	while (k < stacks->ac - 1)
	{
		stacks->a = l_add_first(stacks->a, ft_atoi(stacks->av[i - 1])); 
		i--;
		k++;
	}
}

void	fill_chunks(t_head *stacks, int chunks_cnt)
{
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

int		belongs_to_chunk(int value, t_head *stacks, int current_chunk)
{
	int	i;
	
	i = 0;
	while (i < stacks->chunk_size)
	{
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

void	define_place_holders(int *place_holder_top, int *place_holder_bottom, t_head *stacks, int current_chunk)
{
	t_lst *tmp;
	int	i;

	i = 0;	
	tmp = stacks->a;
	while (tmp)
	{
		if (belongs_to_chunk(tmp->value, stacks, current_chunk))
		{
			if (*place_holder_top == -1)
				*place_holder_top = i;
			*place_holder_bottom = i;
			}
		i++;
		tmp = tmp->next;
	}
}

int		get_place_holder_position(t_head *stacks, int current_chunk)
{
	int	*place_holder_top;
	int	*place_holder_bottom;

	*place_holder_bottom = -1;
	*place_holder_top = -1;
	define_place_holders(place_holder_bottom, place_holder_top, stacks, current_chunk);
	if (get_stack_size(stacks->a) - *place_holder_bottom < *place_holder_top)
		return (*place_holder_bottom);
	return *place_holder_top;
}

int		get_gap_index(t_head *stacks)
{
	int		gap_index;
	t_lst	*tmp;
	
	tmp = stacks->b;
	gap_index = 1;
	while (tmp->next)
	{
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
	if (position > get_stack_size(stacks->b) / 2)
	{
		position = get_stack_size(stacks->b) - position;
		while (position > 0)
		{
			print_com("rb", stacks);
			position--;
		}
	}
	else
	{
		while (position > 0)
		{
			print_com("rrb", stacks);
			position--;
		}
	}	
}

void	sort_b(t_head *stacks) 
{
	int		gap_index;
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = stacks->b;
	gap_index = get_gap_index(stacks);
	if (gap_index > get_stack_size(stacks->b) / 2)
	{
		gap_index = get_stack_size(stacks->b) - gap_index;
		while (gap_index > 0)
		{
			print_com("rb", stacks);
			gap_index--;
		}
	}
	else
	{
		while (gap_index > 0)
		{
			print_com("rrb", stacks);
			gap_index--;
		}
	}	
}


void	lift_up_place_holder(t_head *stacks, int place_holder_position)
{
	if (place_holder_position > get_stack_size(stacks->a) / 2)
	{
		while (place_holder_position > 0)
		{
			print_com("rra", stacks);
			place_holder_position--;
		}
	}
	else
	{
		while (place_holder_position > 0)
		{
			print_com("ra", stacks);
			place_holder_position--;
		}
	}
}

void	place_holder_to_b(t_head *stacks, int current_chunk)
{
	int	place_holder_position;
	
	place_holder_position = get_place_holder_position(stacks, current_chunk);
	lift_up_place_holder(stacks, place_holder_position);
	order_b(stacks, stacks->a->value);
	l_pushb(stacks);
	ft_putstr("pb");
}

int		get_chunks_cnt(int ac)
{
	if (ac <= 100)
		return (ac / 20);
	else if (ac <= 450) 
		return (ac / 100 + 5);
	else
		return (ac / 100 + 6);	
}

void	swap(int *a, int *b)
{
	int	tmp;
	
	tmp = *b;
	*b = *a;
	*a = tmp;
}

int		partition(int *a, int l, int r)
{
	int v = a[(l + r) / 2];
	int i = l;
	int j = r;
	while (i <= j)
	{
		while (a[i] < v)
			i++;
		while (a[j] > v)
			j--;
		if (i < j)
			swap(&a[i++], &a[j--]);
		else
			i++;
	}
	return j;
}

void	quick_sort(int *a, int l, int r)
{
	int q;
	if (l < r)
	{
		q = partition(a, l, r);
		quick_sort(a, l, q);
		quick_sort(a, q + 1, r);
	}
}

void	prepare_args(t_head *stacks)
{
	int	i;

	i = 1;
	while (i < stacks->ac)
	{
		stacks->sorted_args[i - 1] = ft_atoi(stacks->av[i]);
		i++;
	}
}

void	algorithm_over_5(t_head *stacks) {
	int	chunks_cnt;
	int	current_chunk;
	int	i;
	
	current_chunk = 0;
	stacks->sorted_args = (int *)malloc(sizeof(int) * (stacks->ac - 1));
	prepare_args(stacks);
	quick_sort(stacks->sorted_args, 0, stacks->ac - 2); // не готово
	i = 1;
	chunks_cnt = get_chunks_cnt(stacks->ac); // не готово +100 делить на 6
	stacks->chunk_size = stacks->ac / chunks_cnt;
	fill_chunks(stacks, chunks_cnt);
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

void	algorithm(char** argv, int ac, t_head *stacks)
{
	int		i;
	
	i = 0;
	if (ac < 4) {
//		algorithm_3(stacks);	
	}
	else if (ac < 7) {
//		algorithm_5(stacks);
	}
	else {
		algorithm_over_5(stacks);
	}
}
