/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:16:19 by pgenesis          #+#    #+#             */
/*   Updated: 2020/07/26 18:27:19 by pgenesis         ###   ########.fr       */
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

int		get_target_position(t_head *stacks, int gap_index, int value)
{
	int		i;
	t_lst	*tmp;

	tmp = stacks->b;
	i = 0;
	if (gap_index == 0)
		return (handling_sorted_b_case(value, tmp));
	if (value > tmp->value)
		return (handling_unsorted_b_after_gap(value, tmp, gap_index));
	else
	{
		while (value < tmp->value && i < gap_index)
		{
			tmp = tmp->next;
			i++;
		}
		return (i);
	}
}

int		get_max_arg_index(t_lst a)
{
	t_lst	*tmp;
	int		max;
	int		i;
	int		place;

	i = 0;
	place = 0;
	max = a.value;
	tmp = &a;
	while (tmp)
	{
		if (max < tmp->value)
		{
			max = tmp->value;
			place = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (place);
}

int		get_min_arg_index(t_lst a)
{
	t_lst	*tmp;
	int		min;
	int		i;
	int		place;

	i = 0;
	place = 0;
	min = a.value;
	tmp = &a;
	while (tmp)
	{
		if (min > tmp->value)
		{
			min = tmp->value;
			place = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (place);
}
