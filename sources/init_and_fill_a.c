/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_fill_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 15:40:56 by pgenesis          #+#    #+#             */
/*   Updated: 2020/07/26 15:55:38 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_head	*init(t_head *stacks, int ac, char **argv)
{
	stacks = (t_head*)malloc(sizeof(t_head));
	stacks->ac = ac;
	stacks->av = argv;
	stacks->flag_visual = 1;
	stacks->a = NULL;
	stacks->b = NULL;
	return (stacks);
}

void	fill_stack_a(t_head *stacks)
{
	int	i;
	int	k;

	k = 0;
	if (stacks->flag_visual == 2)
		k = 1;
	i = stacks->ac;
	while (k < stacks->ac - 1)
	{
		stacks->a = l_add_first(stacks->a, ft_atoi(stacks->av[i - 1]));
		i--;
		k++;
	}
}
