/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <pgenesis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:23:16 by pgenesis          #+#    #+#             */
/*   Updated: 2020/07/26 18:41:40 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_com(char *res, t_head *stacks)
{
	if (ft_strcmp(res, "rb") == 0)
	{
		stacks->b = l_rotate(stacks->b);
		ft_putstr("rb\n");
	}
	if (ft_strcmp(res, "rrb") == 0)
	{
		stacks->b = l_reverse_rotate(stacks->b);
		ft_putstr("rrb\n");
	}
	if (ft_strcmp(res, "ra") == 0)
	{
		stacks->a = l_rotate(stacks->a);
		ft_putstr("ra\n");
	}
	if (ft_strcmp(res, "rra") == 0)
	{
		stacks->a = l_reverse_rotate(stacks->a);
		ft_putstr("rra\n");
	}
	if (ft_strcmp(res, "pa") == 0)
	{
		ft_putstr("pa\n");
		l_pusha(stacks);
	}
}

void	prepare_args(t_head *stacks)
{
	int	i;

	i = 1;
	while (i < stacks->ac)
	{
		stacks->sorted_args[i - 1] = ft_atoi(stacks->av[i]);
		i++;
	}
}

void	algorithm(int ac, t_head *stacks)
{
	int		i;

	i = 0;
	if (ac == 3)
		algorithm_2(stacks);
	else if (ac == 4)
		algorithm_3(stacks);
	else if (ac == 5)
		algorithm_4(stacks);
	else if (ac == 6)
		algorithm_5(stacks);
	else if (ac > 6)
		algorithm_over_5(stacks);
}
