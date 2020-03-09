/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:05:53 by atote             #+#    #+#             */
/*   Updated: 2020/03/09 14:49:04 by atote            ###   ########.fr       */
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
	int		n;

	stacks = (t_head*)malloc(sizeof(t_head));
	stacks->a = NULL;
	stacks->b = NULL;
	if (argc == 1)
	{
		free(stacks);
		return (0);
	}
	n = argc - 1;
	if (!valid_arg(stacks, argv, argc, 1))
	{
		free(stacks);
		return (0);
	}
	al_min(stacks, n);
	free_all(stacks);
	free(stacks);
	return (0);
}
