/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:17:40 by atote             #+#    #+#             */
/*   Updated: 2020/03/04 18:18:35 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lst	*l_swap(t_lst **h)
{
	t_lst	*tmp;

	if ((*h)->next == NULL || !(*h))
		return (NULL);
	tmp = (*h)->next;
	(*h)->next = (*h)->next->next;
	tmp->next = (*h);
	tmp->is_color = 1;
	return (tmp);
}

int		l_pushb(t_head *stacks)
{
	t_lst	*tmp;

	if (!stacks->a)
		return (1);
	if (!stacks->b)
	{
		tmp = stacks->a->next;
		stacks->a->next = NULL;
		stacks->b = stacks->a;
		stacks->a = tmp;
		return (0);
	}
	tmp = (stacks->a)->next;
	(stacks->a)->next = stacks->b;
	stacks->b = stacks->a;
	stacks->a = tmp;
	return (0);
}

int		l_pusha(t_head *stacks)
{
	t_lst	*tmp;
	t_lst	*tmp1;

	if (!stacks->b)
		return (1);
	stacks->b->is_color = 0;
	tmp = (stacks->b)->next;
	tmp1 = stacks->a;
	(stacks->b)->next = tmp1;
	stacks->a = stacks->b;
	stacks->b = tmp;
	return (0);
}

t_lst	*l_rotate(t_lst *a)
{
	t_lst *tmp;
	t_lst *last;

	last = a;
	while (last->next)
		last = last->next;
	tmp = a->next;
	last->next = a;
	a->next = NULL;
	return (tmp);
}

t_lst	*l_reverse_rotate(t_lst *a)
{
	t_lst	*tmp;
	t_lst	*prelast;

	prelast = a;
	while (prelast->next->next)
		prelast = prelast->next;
	tmp = prelast->next;
	prelast->next->next = a;
	prelast->next = NULL;
	return (tmp);
}
