/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:13:29 by pgenesis          #+#    #+#             */
/*   Updated: 2020/07/26 17:24:24 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	chunks_to_b(t_head *stacks)
{
	int	i;
	int	current_chunk;

	i = 0;
	current_chunk = 0;
	while (stacks->a)
	{
		if (i == stacks->chunk_size)
		{
			i = 0;
			current_chunk++;
		}
		place_holder_to_b(stacks, current_chunk);
		i++;
	}
}
