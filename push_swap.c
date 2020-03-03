/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:05:53 by atote             #+#    #+#             */
/*   Updated: 2020/02/28 18:05:53 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main(int argc, char **argv)
{
    t_head	*stacks;

    stacks = (t_head*)malloc(sizeof(t_head));
	stacks->a = NULL;
	stacks->b = NULL;
	if (argc == 1)
		return (0);
    int n;
    n = argc - 1;
	while (argc > 1)
	{
		stacks->a = l_add_first(stacks->a, ft_atoi(argv[argc - 1]));
		argc--;
	}
    //l_print(stacks->a);
    //push_al0(*stacks, n);
    //al_min(*stacks, n);
    //al_min_pro(*stacks, n);
    al_min_pro_turbo(*stacks, n);
    //al_mini_half(*stacks, n);
    //al_1(*stacks, n);
    // printf("\n%d\n", hmm(stacks));
    return (0);
}