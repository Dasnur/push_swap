/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:05:17 by atote             #+#    #+#             */
/*   Updated: 2020/02/28 16:05:17 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int		main(int argc, char **argv)
{
	t_head	*stacks;

	stacks->a = NULL;
	stacks->b = NULL;
	if (argc == 1)
		return (0);
	while (argc > 1)
	{
		stacks->a = l_add_first(stacks->a, ft_atoi(argv[argc - 1]));
		argc--;
	}
	char *line;
	l_print(stacks->a);
	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "sa") == 0)
			stacks->a = l_swap(&(stacks->a));
		if (ft_strcmp(line, "sb") == 0)
			stacks->b = l_swap(&(stacks->b));
		if (ft_strcmp(line, "ss") == 0)
		{
			stacks->a = l_swap(&(stacks->a));
			stacks->b = l_swap(&(stacks->b));
		}
		if (ft_strcmp(line, "pb") == 0)
			l_pushb(stacks);
		if (ft_strcmp(line, "pa") == 0)
			l_pusha(stacks);
		if (ft_strcmp(line, "ra") == 0)
			stacks->a = l_rotate(stacks->a);
		if (ft_strcmp(line, "rb") == 0)
			stacks->b = l_rotate(stacks->b);
		if (ft_strcmp(line, "rr") == 0)
		{
			stacks->a = l_rotate(stacks->a);
			stacks->b = l_rotate(stacks->b);
		}
		if (ft_strcmp(line, "rra") == 0)
			stacks->a = l_reverse_rotate(stacks->a);
		if (ft_strcmp(line, "rrb") == 0)
			stacks->b = l_reverse_rotate(stacks->b);
		if (ft_strcmp(line, "rrr") == 0)
		{
			stacks->a = l_reverse_rotate(stacks->a);
			stacks->b = l_reverse_rotate(stacks->b);
		}
		l_print(stacks->a);
		printf("%s", "\n");
		l_print(stacks->b);
		if (ft_strcmp(line, "") == 0)
			break;
	}
	// int ret = read(0, line, 10);
	// line[ret] = '\0';
	//printf("%s", test);
	return (0);
}		