/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_add_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:08:17 by atote             #+#    #+#             */
/*   Updated: 2020/03/04 18:07:04 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_dupl(t_lst *a, int check)
{
	t_lst	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->value == check)
			return (1);
		else
			tmp = tmp->next;
	}
	return (0);
}

int		valid_arg(t_head *stacks, char **argv, int argc, int fv)
{
	while (argc > fv)
	{
		if (check_argv(argv[argc - 1]))
		{
			if (check_dupl(stacks->a, ft_atoi(argv[argc - 1])))
				return (exc());
			if (ft_strlen(argv[argc - 1]) > 3 && ft_atoi(argv[argc - 1]) == -1)
				return (exc());
			if (ft_strlen(argv[argc - 1]) > 3 && ft_atoi(argv[argc - 1]) == 0)
				return (exc());
			stacks->a = l_add_first(stacks->a, ft_atoi(argv[argc - 1]));
			argc--;
		}
		else
			return (exc());
	}
	return (1);
}

int		check_argv(char *res)
{
	int		i;

	i = 0;
	if (res[i] == '-' || res[i] == '+')
		i++;
	while (res[i] != '\0')
	{
		if (res[i] >= 48 && res[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

t_lst	*l_add_first(t_lst *head, int value)
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
