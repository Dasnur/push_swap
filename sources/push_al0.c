/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_al0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:23:16 by atote             #+#    #+#             */
/*   Updated: 2020/03/04 17:53:52 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		l_count_elem(t_lst *a)
{
	int		i;
	t_lst	*tmp;

	tmp = a;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

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

void	al_min_help1(t_head *stacks, int *countshag)
{
	int		t;
	int		mini;

	while (l_count_elem(stacks->b))
	{
		mini = find_maxi(*stacks->b);
		if (mini > ((l_count_elem(stacks->b)) / 2))
			t = l_count_elem(stacks->b) - mini;
		else
			t = mini;
		while (t > 0)
		{
			if (mini > ((l_count_elem(stacks->b)) / 2))
				print_com("rrb", stacks);
			else
				print_com("rb", stacks);
			t--;
		}
		l_pusha(stacks);
		ft_putstr("pa\n");
		if (*countshag == 0)
			print_com("ra", stacks);
	}
	*countshag = *countshag + 1;
}

void	al_min_help2(t_head *stacks)
{
	int		mini;
	int		t;

	mini = find_mini(*stacks->a);
	if (mini > ((l_count_elem(stacks->a)) / 2))
		t = l_count_elem(stacks->a) - mini;
	else
		t = mini;
	while (t > 0)
	{
		if (mini > ((l_count_elem(stacks->a)) / 2))
			print_com("rra", stacks);
		else
			print_com("ra", stacks);
		t--;
	}
	l_pushb(stacks);
	ft_putstr("pb\n");
}

void	al_min(t_head stacks, int n)
{
	int		i;
	int		countshag;

	i = 0;
	countshag = 0;
	while (countshag < 2 && n > 50)
	{
		while (i < (n / 2 + 1))
		{
			l_pushb(&stacks);
			ft_putstr("pb\n");
			i++;
		}
		al_min_help1(&stacks, &countshag);
		i = 0;
	}
	while (l_count_elem(stacks.a) && hmm(&stacks) != 1)
		al_min_help2(&stacks);
	while (l_count_elem(stacks.b))
		print_com("pa", &stacks);
}
