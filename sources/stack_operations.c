/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:37:26 by pgenesis          #+#    #+#             */
/*   Updated: 2020/07/26 18:41:51 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	completely_push_a(t_head *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->ac)
	{
		l_pusha(stacks);
		ft_putstr("pa\n");
		i++;
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
			print_com("rrb", stacks);
			gap_index--;
		}
	}
	else
	{
		while (gap_index > 0)
		{
			print_com("rb", stacks);
			gap_index--;
		}
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
			print_com("rrb", stacks);
			position--;
		}
	}
	else
		while (position > 0)
		{
			print_com("rb", stacks);
			position--;
		}
}

int		get_stack_size(t_lst *l)
{
	t_lst	*tmp;
	int		size;

	size = 0;
	tmp = l;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
