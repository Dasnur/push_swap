/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_al0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:23:16 by atote             #+#    #+#             */
/*   Updated: 2020/02/29 14:23:16 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     hmm(t_head *stacks)
{
    t_lst   *tmp;

    tmp = stacks->a;
    if (stacks->b == NULL)
    {
        while (tmp->next)
        {
            if (tmp->value < tmp->next->value)
                tmp = tmp->next;
            else
                return (0);
        }
        return (1);
    }
    else
        return (0);
    return (1);
}

int     find_mini(t_lst a)
{
    t_lst	*tmp;
    int		min;
	int		i;
	int		place;

	i = 0;
	place = 0;
    min = a.value;
    tmp = &a;
    while (tmp)
    {
        if (min > tmp->value)
		{
            min = tmp->value;
			place = i;
		}
        tmp = tmp->next;
		i++; 
    }
    return (place);
}

int     find_maxi(t_lst a)
{
    t_lst	*tmp;
    int		max;
	int		i;
	int		place;

	i = 0;
	place = 0;
    max = a.value;
    tmp = &a;
    while (tmp)
    {
        if (max > tmp->value)
		{
            max = tmp->value;
			place = i;
		}
        tmp = tmp->next;
		i++; 
    }
    return (place);
}

int		skolkih_menshe(t_lst a)
{
	int	i;
	int tmp;

	tmp = a.value;
	i = 0;
	while (a.next)
	{
		if (tmp < a.next->value)
			i++;
		a = *(a.next);
	}
	return i;
}

int		l_count_elem(t_lst *a)
{
	int i;
	t_lst *tmp;

	tmp = a;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return i;
}

void    push_al0(t_head stacks, int n)
{
    int i = 1;
    int k = 1;
    int ktmp;
    int back = 0;
    int sh = 0;
    int flag1 = 0;
    int count = 0;
    t_lst *tmp;
    // printf("\n%d\n", hmm(stacks));
    while (k < n && (hmm(&stacks) != 1))
    {
        // printf("\n%d\n", hmm(stacks));
        // l_print(stacks->a);
        // printf("\n");
        if (stacks.a->value > stacks.a->next->value)
        {
            ktmp = k;
            while (ktmp > 0)
            {
                if (i == 1 && (stacks.a->value > stacks.a->next->value))
                {
                    //ft_putstr_fd("sa\n", 0);
                    count++;
                    stacks.a = l_swap(&stacks.a);
                    ktmp--;
                    i++;
                }
                else if (i > 1 && stacks.a->value <= stacks.a->next->value)
                {
                    //ft_putstr_fd("pb\n", 0);
                    count++;
                    l_pushb(&stacks);
                    i--;
                    back++;
                }
                else if (i == 1 && (stacks.a->value <= stacks.a->next->value))
                    ktmp--;
            }
            while (back > 0)
            {
                //ft_putstr_fd("pa\n", 0);
                count++;
                l_pusha(&stacks);
                back--;
            }
        }
        else if (k < n - 1)
        {
            //ft_putstr_fd("rra\n", 0);
            count++;
            stacks.a = l_reverse_rotate(stacks.a);
            i = 1;
            k++;
            sh++;
        }
        else
            k++;
    }
    printf("\ncount-->%d\n", count);
    l_print(stacks.a);
}

void    al_min(t_head stacks, int n)
{
	int		mini;
	int count;
	int t;
	count = 0;
	int i = 0;
    while (i < n)
	{
		mini = find_mini(*(stacks.a));
		while (mini > 0)
		{
			stacks.a = l_rotate(stacks.a);
			count++;
			mini--;
		}
		i++;
		l_pushb(&stacks);
		count += 1;
	}
	while (l_count_elem(stacks.b))
	{
		l_pusha(&stacks);
		count++;
	}
	printf("\nold: count-->%d\n", count);
	//l_print(stacks.a);
}

void	al_mini_half(t_head stacks, int n)
{
	int		i;
	int		mini;
	int count;
	int t;
	int count1 = 0;
	count = 0;
	i = 1;
    while (l_count_elem(stacks.a))
	{
		mini = find_mini(*stacks.a);
		//printf("\nmini->%d\n", mini);
		if (mini > ((l_count_elem(stacks.a)) / 2))
			t = l_count_elem(stacks.a) - mini;
		else
			t = mini;
		while (t > 0)
		{
			if (mini > ((l_count_elem(stacks.a)) / 2))
				stacks.a = l_reverse_rotate(stacks.a);
			else
				stacks.a = l_rotate(stacks.a);
			count++;
			t--;
		}
		l_pushb(&stacks);
		count += 1;
		i++;
	}
	i = 1;
	while (l_count_elem(stacks.b))
	{
		l_pusha(&stacks);
		count++;
		i++;
	}
	printf("\nhalf: count-->%d\n", count);
    //l_print(stacks.a);
}

void	al_min_pro(t_head stacks, int n)
{
	int		i;
	int		mini;
	int minib;
	int minia;
	int count;
	int tb;
	int ta;
	int count1 = 0;
	count = 0;
	i = 1;
	while (i < n / 2)
	{
		l_pushb(&stacks);
		count++;
		i++;
	}
	while (l_count_elem(stacks.b))
	{
		minib = find_mini(*stacks.b);
		minia = find_mini(*stacks.a);
		//printf("\nmini->%d\n", mini);
		if (minib > ((l_count_elem(stacks.b)) / 2))
			tb = l_count_elem(stacks.b) - minib;
		else
			tb = minib;
		if (minia > ((l_count_elem(stacks.a)) / 2))
			ta = l_count_elem(stacks.a) - minia;
		else
			ta = minia;
		while (tb > 0 && ta > 0)
		{
			if (minib > ((l_count_elem(stacks.b)) / 2))
				stacks.b = l_reverse_rotate(stacks.b);
			else
				stacks.b = l_rotate(stacks.b);
			count++;
			t--;
		}
		l_pusha(&stacks);
		count += 1;
	}
    while (l_count_elem(stacks.a))
	{
		mini = find_mini(*stacks.a);
		//printf("\nmini->%d\n", mini);
		if (mini > ((l_count_elem(stacks.a)) / 2))
			t = l_count_elem(stacks.a) - mini;
		else
			t = mini;
		while (t > 0)
		{
			if (mini > ((l_count_elem(stacks.a)) / 2))
				stacks.a = l_reverse_rotate(stacks.a);
			else
				stacks.a = l_rotate(stacks.a);
			count++;
			t--;
		}
		l_pushb(&stacks);
		count += 1;
	}
	while (l_count_elem(stacks.b))
	{
		l_pusha(&stacks);
		count++;
		i++;
	}
	printf("\npro: count-->%d\n", count);
    //l_print(stacks.a);
}

void	al_min_pro_turbo(t_head stacks, int n)
{
	int		i;
	int		mini;
	int count;
	int t;
	int count1 = 0;
	count = 0;
	i = 1;
	int countshag = 0;
	int barrier = n / 4;
	while (countshag < 4)
	{
		while (i < barrier)
		{
			l_pushb(&stacks);
			count++;
			i++;
		}
		while (l_count_elem(stacks.b))
		{
			mini = find_mini(*stacks.b);
			//printf("\nmini->%d\n", mini);
			if (mini > ((l_count_elem(stacks.b)) / 2))
				t = l_count_elem(stacks.b) - mini;
			else
				t = mini;
			while (t > 0)
			{
				if (mini > ((l_count_elem(stacks.b)) / 2))
					stacks.b = l_reverse_rotate(stacks.b);
				else
					stacks.b = l_rotate(stacks.b);
				count++;
				t--;
			}
			l_pusha(&stacks);
			stacks.a = l_rotate(stacks.a);
			count += 2;
		}
		countshag++;
		i = 0;
	}
    while (l_count_elem(stacks.a))
	{
		mini = find_mini(*stacks.a);
		//printf("\nmini->%d\n", mini);
		if (mini > ((l_count_elem(stacks.a)) / 2))
			t = l_count_elem(stacks.a) - mini;
		else
			t = mini;
		while (t > 0)
		{
			if (mini > ((l_count_elem(stacks.a)) / 2))
				stacks.a = l_reverse_rotate(stacks.a);
			else
				stacks.a = l_rotate(stacks.a);
			count++;
			t--;
		}
		l_pushb(&stacks);
		count += 1;
	}
	while (l_count_elem(stacks.b))
	{
		l_pusha(&stacks);
		count++;
		i++;
	}
	printf("\nturbo: count-->%d\n", count);
    l_print(stacks.a);
}

void	al_1(t_head stacks, int n)
{
	int i = 0;
	int count;
	int	k;
	int	p;
	int ptmp =0;

	p = 0;
	k = 0;
	count = 0;
	while (i < n)
	{
		if (stacks.a->value <= stacks.a->next->value)
		{
			stacks.a = l_swap(&stacks.a);
			stacks.a = l_rotate(stacks.a);
			k++;
			// printf("\nllok-->%d", k);
			// l_print(stacks.a);
			// l_print(stacks.b);
			count += 2;
			i++;
		}
		else
		{
			stacks.a = l_swap(&stacks.a);
			l_pushb(&stacks);
			p = skolkih_menshe(*stacks.b);
			//printf("\np-->%d\n", p);
			ptmp = p;
			while (ptmp > 0)
			{
				stacks.b = l_swap(&stacks.b);
				count++;
				l_pusha(&stacks);
				count++;
				ptmp--;
			}
			count++;
			i++;
			//k++;
			while (p > 0)
			{
				l_pushb(&stacks);
				count++;
				p--;
			}
			// n = k - 1;
			// k = 0;
		}
		if (i == n - 1)
		{
			i = 0;
			l_pushb(&stacks);
			count++;
			// p = skolkih_menshe(*stacks.b);
			// ptmp = p;
			// while (ptmp > 0)
			// {
			// 	stacks.b = l_swap(&stacks.b);
			// 	count++;
			// 	l_pusha(&stacks);
			// 	count++;
			// 	ptmp--;
			// }
			// while (p > 0)
			// {
			// 	l_pushb(&stacks);
			// 	count++;
			// 	p--;
			// }
			printf("\nk-->%d\n", k);
			n = k - 1;
			k = 0;
		}
		// l_print(stacks.a);
		// l_print(stacks.b);
	}
	while (stacks.b)
	{
		l_pusha(&stacks);
		count++;
	}
	printf("\ncount-->%d\n", count);
    l_print(stacks.a);
}