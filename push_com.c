/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:08:17 by atote             #+#    #+#             */
/*   Updated: 2020/02/28 19:08:17 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*l_swap(t_lst **h)
{
	t_lst	*tmp;

	if ((*h)->next == NULL || !(*h))
		return (NULL);
	tmp = (*h)->next;
	(*h)->next = (*h)->next->next;
	tmp->next = (*h);
	return (tmp);
}

void	l_pushb(t_head *stacks)
{
	t_lst	*tmp;
	t_lst	*tmp1;

	if (!stacks->b)
	{
		tmp = stacks->a->next;
		stacks->a->next = NULL;
		stacks->b = stacks->a;
		stacks->a = tmp;
		return ;
	}
	tmp = (stacks->a)->next;
	tmp1 = stacks->b;
	(stacks->a)->next = tmp1;
	stacks->b = stacks->a;
	stacks->a = tmp;
}

void	l_pusha(t_head *stacks)
{
	t_lst	*tmp;
	t_lst	*tmp1;

	tmp = (stacks->b)->next;
	tmp1 = stacks->a;
	(stacks->b)->next = tmp1;
	stacks->a = stacks->b;
	stacks->b = tmp;
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