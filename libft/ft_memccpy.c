/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <pgenesis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:55:14 by pgenesis          #+#    #+#             */
/*   Updated: 2020/07/26 12:08:37 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptd;
	unsigned char	*pts;
	size_t			i;

	i = 0;
	ptd = (unsigned char *)(dest);
	pts = (unsigned char *)(src);
	if ((!n) && (!dest) && (!src))
		return (NULL);
	while ((i < n) && (*pts != (unsigned char)(c)))
	{
		*ptd = *pts;
		i++;
		ptd++;
		pts++;
	}
	if (*pts == (unsigned char)(c) && (i != n))
	{
		*ptd = (unsigned char)(c);
		return (++ptd);
	}
	return (NULL);
}
