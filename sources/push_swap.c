/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:05:53 by atote             #+#    #+#             */
/*   Updated: 2020/07/13 18:43:59 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_mini(t_lst a)
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

int		find_maxi(t_lst a)
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

int		main(int argc, char **argv)
{
	t_head	*stacks;
	
	if (argc == 1)
	{
		return (0);
	}
	stacks = init(stacks, argc, argv);
	fill_stack_a(stacks);
	if (!valid_arg(argv, argc, stacks))
	{
		return (0);
	}
	algorithm(argv, argc, stacks);
	return (0);
}
