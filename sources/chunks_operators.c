/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_operators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:39:26 by atote             #+#    #+#             */
/*   Updated: 2020/07/26 15:00:20 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		belongs_to_chunk(int value, t_head *stacks, int current_chunk)
{
	int	i;

	i = 0;
	while (i < stacks->chunk_size)
	{
		if (value == stacks->chunks[current_chunk][i])
			return (1);
		i++;
	}
	return (0);
}

int		get_chunks_cnt(int ac)
{
	if (ac < 20)
		return (1);
	if (ac <= 110)
		return (ac / 20);
	else if (ac <= 450)
		return (ac / 100 + 5);
	else
		return (ac / 100 + 5);
}

void	fill_chunks(t_head *stacks, int chunks_cnt)
{
	int	i;
	int	k;
	int	j;

	j = 0;
	k = 0;
	i = 0;
	stacks->chunks = (int**)malloc(sizeof(int*) * chunks_cnt);
	while (i < chunks_cnt)
	{
		stacks->chunks[i] = (int *)malloc(sizeof(int) * (stacks->chunk_size));
		while (k < (stacks->chunk_size))
		{
			if (j >= stacks->ac - 1)
				stacks->chunks[i][k] = 0;
			else
				stacks->chunks[i][k] = stacks->sorted_args[j];
			j++;
			k++;
		}
		k = 0;
		i++;
	}
}
