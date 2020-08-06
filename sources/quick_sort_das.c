/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_das.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:34:12 by atote             #+#    #+#             */
/*   Updated: 2020/07/26 14:34:24 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

int		partition(int *a, int l, int r)
{
	int v;
	int i;
	int j;

	v = a[(l + r) / 2];
	i = l;
	j = r;
	while (i <= j)
	{
		while (a[i] < v)
			i++;
		while (a[j] > v)
			j--;
		if (i < j)
			swap(&a[i++], &a[j--]);
		else
			i++;
	}
	return (j);
}

void	quick_sort(int *a, int l, int r)
{
	int q;

	if (l < r)
	{
		q = partition(a, l, r);
		quick_sort(a, l, q);
		quick_sort(a, q + 1, r);
	}
}
