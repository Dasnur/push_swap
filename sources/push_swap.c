/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:05:53 by atote             #+#    #+#             */
/*   Updated: 2020/03/04 18:16:59 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		hmm(t_head *stacks)
{
	t_lst	*tmp;

	tmp = stacks->a;
	if (stacks->b == NULL)
	{
		while (tmp->next)
		{
			if (tmp->value < tmp->next->value)
				tmp = tmp->next;
			else
				return (0);
		}
		return (1);
	}
	else
		return (0);
	return (1);
}

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

void	free_all(t_head *stacks)
{
	t_lst	*tmp;
	
	while (stacks->a)
	{
		tmp = stacks->a->next;
		free(stacks->a);
		stacks->a = tmp;	
	}
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
	while (argc > 1)
	{
		stacks->a = l_add_first(stacks->a, ft_atoi(argv[argc - 1]));
		argc--;
	}
	l_pushb(stacks);
	//al_min(*stacks, n);
	free_all(stacks);
	free(stacks);
	return (0);
}
