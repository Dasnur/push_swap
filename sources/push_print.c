/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:31:27 by atote             #+#    #+#             */
/*   Updated: 2020/03/04 17:25:39 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		exc(void)
{
	ft_putstr("Error\n");
	return (0);
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
			ft_printf("%s{green}", ft_itoa(tmpa->value));
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
