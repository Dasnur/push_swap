/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_al0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:23:16 by atote             #+#    #+#             */
/*   Updated: 2020/07/26 15:46:27 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

void	algorithm_over_5_help(t_head *stacks, int i, int *current_chunk)
{
	while (stacks->a)
	{
		if (i == stacks->chunk_size)
		{
			i = 0;
			(*current_chunk)++;
		}
		place_holder_to_b(stacks, *current_chunk);
		i++;
	}
	i = 0;
	sort_b(stacks);
	while (i < stacks->ac)
	{
		l_pusha(stacks);
		ft_putstr("pa\n");
		i++;
	}
}

void	algorithm_over_5(t_head *stacks)
{
	int	chunks_cnt;
	int	current_chunk;
	int	i;

	current_chunk = 0;
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
	algorithm_over_5_help(stacks, i, &current_chunk);
	free(stacks->sorted_args);
	while (i < chunks_cnt)
	{
		free(stacks->chunks[i]);
		i++;
	}
	free(stacks->chunks);
}

void	algorithm(int ac, t_head *stacks)
{
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
