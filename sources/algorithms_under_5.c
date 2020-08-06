/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_under_5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:28:28 by atote             #+#    #+#             */
/*   Updated: 2020/07/26 14:48:17 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algorithm_2(t_head *stacks)
{
	if (stacks->a->value > stacks->a->next->value)
		ft_putstr("sa\n");
}

void	algorithm_3(t_head *stacks)
{
	int alg_case;

	if ((alg_case = get_case(stacks)))
		handling_case(alg_case);
}

void	algorithm_4(t_head *stacks)
{
	if (hmm(stacks))
		return ;
	push_b_min(stacks);
	algorithm_3(stacks);
	print_com("pa", stacks);
}

void	algorithm_5(t_head *stacks)
{
	if (hmm(stacks))
		return ;
	push_b_min(stacks);
	algorithm_4(stacks);
	print_com("pa", stacks);
}
