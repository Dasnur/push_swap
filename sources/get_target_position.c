/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_taget_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:41:22 by atote             #+#    #+#             */
/*   Updated: 2020/07/26 14:42:16 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		handling_sorted_b_case(int value, t_lst *tmp)
{
	int	i;

	i = 0;
	if (tmp == NULL)
		return (i);
	while (tmp && value < tmp->value)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
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
	while (tmp && value < tmp->value)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
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
