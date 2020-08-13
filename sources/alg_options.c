/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:27:56 by pgenesis          #+#    #+#             */
/*   Updated: 2020/07/26 18:33:01 by pgenesis         ###   ########.fr       */
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

void	algorithm_over_5(t_head *stacks)
{
	int	chunks_cnt;
	int	i;

	stacks->sorted_args = (int *)malloc(sizeof(int) * (stacks->ac - 1));
	prepare_args(stacks);
	quick_sort(stacks->sorted_args, 0, stacks->ac - 2);
	i = 0;
	chunks_cnt = get_chunks_cnt(stacks->ac);
	stacks->chunk_size = (int)(stacks->ac / chunks_cnt);
	if (stacks->ac % chunks_cnt > 0)
	{
		chunks_cnt++;
	}
	fill_chunks(stacks, chunks_cnt);
	chunks_to_b(stacks);
	sort_b(stacks);
	completely_push_a(stacks);
	free(stacks->sorted_args);
	i = 0;
	while (i < chunks_cnt)
	{
		free(stacks->chunks[i]);
		i++;
	}
	free(stacks->chunks);
}
