/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:05:53 by atote             #+#    #+#             */
/*   Updated: 2020/07/13 21:16:50 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_head	*stacks;
	
	if (argc == 1)
	{
		return (0);
	}
	stacks = init(stacks, argc, argv);
	fill_stack_a(stacks);
	if (!valid_arg(argv, argc, stacks, stacks->flag_visual))
	{
		return (0);
	}
	algorithm(argv, argc, stacks);
	return (0);
}
