/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:40:18 by pgenesis          #+#    #+#             */
/*   Updated: 2020/07/26 17:56:07 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	handling_case(int alg_case)
{
	if (alg_case == 1)
		ft_putstr("sa\n");
	else if (alg_case == 2)
	{
		ft_putstr("sa\n");
		ft_putstr("rra\n");
	}
	else if (alg_case == 3)
		ft_putstr("ra\n");
	else if (alg_case == 4)
	{
		ft_putstr("sa\n");
		ft_putstr("ra\n");
	}
	else if (alg_case == 5)
		ft_putstr("rra\n");
}

void	push_b_min(t_head *stacks)
{
	int		min_arg_index;
	t_lst	*tmp;

	tmp = stacks->a;
	min_arg_index = get_min_arg_index(*tmp);
	lift_up_place_holder(stacks, min_arg_index);
	l_pushb(stacks);
	ft_putstr("pb\n");
}

int		get_case(t_head *stacks)
{
	t_lst *tmp;

	tmp = stacks->a;
	if (tmp->value > tmp->next->value && tmp->value < tmp->next->next->value)
	{
		if (tmp->next->value < tmp->next->next->value)
			return (1);
	}
	if (tmp->value > tmp->next->value && tmp->value > tmp->next->next->value)
	{
		if (tmp->next->value > tmp->next->next->value)
			return (2);
		else
			return (3);
	}
	if (tmp->value < tmp->next->value && tmp->value < tmp->next->next->value)
	{
		if (tmp->next->value < tmp->next->next->value)
			return (0);
		else
			return (4);
	}
	if (tmp->value < tmp->next->value && tmp->value > tmp->next->next->value)
		return (5);
	return (0);
}

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
