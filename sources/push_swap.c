/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:05:53 by atote             #+#    #+#             */
/*   Updated: 2020/07/26 15:51:11 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	free_stacks_a(t_lst *a)
{
	t_lst *tmp;
	t_lst *tmp1;

	tmp = a;
	tmp1 = a;
	while (tmp1)
	{
		tmp1 = tmp->next;
		free(tmp);
		tmp = tmp1;
	}
}

int		main(int argc, char **argv)
{
	t_head	*stacks;

	stacks = NULL;
	if (argc == 1)
	{
		return (0);
	}
	stacks = init(stacks, argc, argv);
	fill_stack_a(stacks);
	if (!valid_arg(argv, argc, stacks, stacks->flag_visual))
		return (0);
	if (!hmm(stacks))
		algorithm(argc, stacks);
	free_stacks_a(stacks->a);
	free(stacks);
	return (0);
}
