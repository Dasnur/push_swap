/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:31:27 by atote             #+#    #+#             */
/*   Updated: 2020/07/11 15:44:44 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all(t_head *stacks)
{
	t_lst	*tmp;

	if (!stacks)
		return ;
	while (stacks->a)
	{
		tmp = stacks->a->next;
		free(stacks->a);
		stacks->a = tmp;
	}
	while (stacks->b)
	{
		tmp = stacks->b->next;
		free(stacks->b);
		stacks->b = tmp;
	}
}

int		hmm(t_head *stacks)
{
	t_lst	*tmp;

	tmp = stacks->a;
	if (!stacks)
		return (0);
	if (stacks->b == NULL && stacks->a != NULL)
	{
		while (tmp->next)
		{
			if (tmp->value < tmp->next->value)
				tmp = tmp->next;
			else
				return (0);
		}
		return (1);
	}
	else
		return (0);
	return (1);
}

int		exc(void)
{
	ft_putstr("Error\n");
	exit(0);
}

void	help_print(t_lst **tmpb, int n, int lenf, int tmpv)
{
	if (*tmpb)
	{
		while (n - lenf > 0)
		{
			ft_putchar(' ');
			lenf++;
		}
		ft_putnbr((*tmpb)->value);
		tmpv = (*tmpb)->value;
		while (tmpv > 0)
		{
			ft_putchar('-');
			tmpv--;
		}
		*tmpb = (*tmpb)->next;
	}
	ft_putchar('\n');
}

void	print_all(t_head *stacks, int n)
{
	t_lst	*tmpa;
	t_lst	*tmpb;
	int		tmpv;
	int		lenf;

	tmpb = stacks->b;
	tmpa = stacks->a;
	while (tmpa || tmpb)
	{
		lenf = 0;
		if (tmpa)
		{
			printf(ft_itoa(tmpa->value));
			tmpv = tmpa->value;
			while (tmpv > 0)
			{
				lenf++;
				ft_putchar('-');
				tmpv--;
			}
			tmpa = tmpa->next;
		}
		help_print(&tmpb, n, lenf, tmpv);
	}
}
