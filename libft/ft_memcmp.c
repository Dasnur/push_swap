/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <pgenesis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:21:20 by pgenesis          #+#    #+#             */
/*   Updated: 2020/07/26 12:08:52 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pts1;
	unsigned char	*pts2;
	size_t			i;
	long long int	ch;

	ch = (long long int)(n);
	i = 0;
	pts1 = (unsigned char *)(s1);
	pts2 = (unsigned char *)(s2);
	if (ch < 0)
		return (0);
	while (i < n)
	{
		if (*pts1 != *pts2)
			return (*pts1 - *pts2);
		i++;
		pts1++;
		pts2++;
	}
	return (0);
}
