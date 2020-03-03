/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_add_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:08:17 by atote             #+#    #+#             */
/*   Updated: 2020/02/28 18:08:17 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst		*l_add_first(t_lst *head, int value)
{
	t_lst	*new;

	if (!head)
	{
		head = (t_lst*)malloc(sizeof(t_lst));
		head->value = value;
		head->next = NULL;
		return (head);
	}
	new = (t_lst *)malloc(sizeof(t_lst));
	new->value = value;
	new->next = head;
	return (new);
}

void	l_print(t_lst *head)
{
	t_lst *tmp;

	tmp = head;
	while (tmp)
	{
		ft_putnbr(tmp->value);
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', 0);
}