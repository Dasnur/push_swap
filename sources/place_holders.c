/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_holders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:35:38 by atote             #+#    #+#             */
/*   Updated: 2020/07/26 14:56:59 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_stack_size(t_lst *l)
{
	t_lst	*tmp;
	int		size;

	size = 0;
	tmp = l;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	lift_up_place_holder(t_head *stacks, int place_holder_position)
{
	int		stack_size;

	stack_size = get_stack_size(stacks->a);
	if (place_holder_position > stack_size / 2)
	{
		while (stack_size - place_holder_position > 0)
		{
			print_com("rra", stacks);
			place_holder_position++;
		}
	}
	else
	{
		while (place_holder_position > 0)
		{
			print_com("ra", stacks);
			place_holder_position--;
		}
	}
}

void	place_holder_to_b(t_head *stacks, int current_chunk)
{
	int	place_holder_position;

	place_holder_position = get_place_holder_position(stacks, current_chunk);
	lift_up_place_holder(stacks, place_holder_position);
	order_b(stacks, stacks->a->value);
	l_pushb(stacks);
	ft_putstr("pb\n");
}

void	define_place_holders(int *place_holder_bottom, int *place_holder_top,
t_head *stacks, int current_chunk)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = stacks->a;
	while (tmp)
	{
		if (belongs_to_chunk(tmp->value, stacks, current_chunk))
		{
			if (*place_holder_top == -1)
				*place_holder_top = i;
			*place_holder_bottom = i;
		}
		i++;
		tmp = tmp->next;
	}
}

int		get_place_holder_position(t_head *stacks, int current_chunk)
{
	int	place_holder_top_;
	int	place_holder_bottom_;
	int	*place_holder_bottom;
	int	*place_holder_top;

	place_holder_bottom_ = -1;
	place_holder_top_ = -1;
	place_holder_bottom = &place_holder_bottom_;
	place_holder_top = &place_holder_top_;
	define_place_holders(place_holder_bottom, place_holder_top,
	stacks, current_chunk);
	if (get_stack_size(stacks->a) - *place_holder_bottom < *place_holder_top)
		return (*place_holder_bottom);
	return (*place_holder_top);
}
