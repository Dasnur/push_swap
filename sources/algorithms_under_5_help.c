/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_under_5_help.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:47:17 by atote             #+#    #+#             */
/*   Updated: 2020/07/26 14:58:43 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	return (-1);
}
