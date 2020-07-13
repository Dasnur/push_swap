/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:05:53 by atote             #+#    #+#             */
/*   Updated: 2020/07/13 15:31:01 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_head	*init(t_head * stacks, int ac, char **argv)
{
	stacks = (t_head*)malloc(sizeof(t_head));
	stacks->ac = ac;
	stacks->av = argv;
	stacks->a = NULL;
	stacks->b = NULL;
	return stacks;
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
