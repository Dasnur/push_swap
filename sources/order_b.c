/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:50:10 by atote             #+#    #+#             */
/*   Updated: 2020/07/26 14:50:38 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_gap_index(t_head *stacks)
{
	int		gap_index;
	t_lst	*tmp;

	tmp = stacks->b;
	gap_index = 1;
	if (tmp == NULL)
		return (0);
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			return (gap_index);
		tmp = tmp->next;
		gap_index++;
	}
	return (0);
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
	{
		while (position-- > 0)
			print_com("rb", stacks);
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
