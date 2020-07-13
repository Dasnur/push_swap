/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:05:17 by atote             #+#    #+#             */
/*   Updated: 2020/07/13 21:48:02 by atote            ###   ########.fr       */
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

int		descision(t_head *stacks, char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	if (hmm(stacks) && stacks && stacks->a)
		ft_putstr("OK\n");
	if (!hmm(stacks) && stacks && stacks->a)
		ft_putstr("KO\n");
	t_lst *tmp = stacks->a;
	while (tmp) {
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	free_all(stacks);
	if (stacks)
	{
		free(stacks);
		stacks = NULL;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_head	*stacks;

	stacks = init(stacks, argc, argv);
	fill_stack_a(stacks);
	if (argc == 1)
		return (descision(stacks, stacks->line));
	if (ft_strcmp("-v", argv[1]) == 0)
		stacks->flag_visual = 2;
	if (!valid_arg(argv, argc, stacks, stacks->flag_visual))
		return (descision(stacks, stacks->line));
	while (get_next_line(0, &stacks->line))
	{
		if (!sa_rb_com(stacks, stacks->line))
			return (descision(stacks, stacks->line));
		else if (!rr_rrr_print(stacks, stacks->line, argc, stacks->flag_visual))
			break ;
		if (!val_line(stacks->line))
			return (descision(stacks, stacks->line));
		free_line(&stacks->line);
	}
	descision(stacks, stacks->line);
	t_lst *tmp = stacks->a;
	while (tmp) {
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
