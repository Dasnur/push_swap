/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:05:17 by atote             #+#    #+#             */
/*   Updated: 2020/03/04 17:15:03 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include "../ft_printf/includes/libftprintf.h"

int		sa_rb_com(t_head *stacks, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		stacks->a = l_swap(&(stacks->a));
	else if (ft_strcmp(line, "sb") == 0)
		stacks->b = l_swap(&(stacks->b));
	else if (ft_strcmp(line, "ss") == 0)
	{
		stacks->a = l_swap(&(stacks->a));
		stacks->b = l_swap(&(stacks->b));
	}
	else if (ft_strcmp(line, "pb") == 0)
	{
		if (l_pushb(stacks))
			return (exc());
	}
	else if (ft_strcmp(line, "pa") == 0)
	{
		if (l_pusha(stacks))
			return (exc());
	}
	else if (ft_strcmp(line, "ra") == 0)
		stacks->a = l_rotate(stacks->a);
	else if (ft_strcmp(line, "rb") == 0)
		stacks->b = l_rotate(stacks->b);
	return (1);
}

int		rr_rrr_print(t_head *stacks, char *line, int argc, int fv)
{
	if (ft_strcmp(line, "rr") == 0)
	{
		stacks->a = l_rotate(stacks->a);
		stacks->b = l_rotate(stacks->b);
	}
	else if (ft_strcmp(line, "rra") == 0)
		stacks->a = l_reverse_rotate(stacks->a);
	else if (ft_strcmp(line, "rrb") == 0)
		stacks->b = l_reverse_rotate(stacks->b);
	else if (ft_strcmp(line, "rrr") == 0)
	{
		stacks->a = l_reverse_rotate(stacks->a);
		stacks->b = l_reverse_rotate(stacks->b);
	}
	else if (ft_strcmp(line, "") == 0)
		return (0);
	if (fv == 2)
	{
		print_all(stacks, argc - 2);
		system("sleep 0.1");
		system("clear");
	}
	return (1);
}

int		val_line(char *line)
{
	if (ft_strcmp(line, "sa") != 0 && ft_strcmp(line, "sb") != 0 &&
	ft_strcmp(line, "ss") != 0 && ft_strcmp(line, "pa") != 0
	&& ft_strcmp(line, "pb") != 0 && ft_strcmp(line, "ra")
	!= 0 && ft_strcmp(line, "rb") != 0 && ft_strcmp(line, "rr") != 0
	&& ft_strcmp(line, "rra")
	!= 0 && ft_strcmp(line, "rrb") != 0 && ft_strcmp(line, "rrr") != 0)
		return (exc());
	return (1);
}

void	descision(t_head *stacks)
{
	if (hmm(stacks))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int		main(int argc, char **argv)
{
	t_head	*stacks;
	int		fv;
	char	*line;

	fv = 1;
	stacks = (t_head*)malloc(sizeof(t_head));
	stacks->a = NULL;
	stacks->b = NULL;
	if (argc == 1)
		return (0);
	if (ft_strcmp("-v", argv[1]) == 0)
		fv = 2;
	if (!valid_arg(stacks, argv, argc, fv))
		return (0);
	while (get_next_line(0, &line))
	{
		if (!sa_rb_com(stacks, line))
			return (0);
		else if (!rr_rrr_print(stacks, line, argc, fv))
			break ;
		if (!val_line(line))
			return (0);
	}
	descision(stacks);
	return (0);
}
