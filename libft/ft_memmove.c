/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <pgenesis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:51:34 by pgenesis          #+#    #+#             */
/*   Updated: 2020/07/26 13:48:56 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rewrite(unsigned char *dest, unsigned char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*dest = *src;
		i++;
		dest++;
		src++;
	}
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptd;
	unsigned char	*pts;
	unsigned char	*tmp;
	long long int	ch;

	ch = (long long int)(n);
	if (ch < 0)
		return (NULL);
	if ((dest == NULL) && (src == NULL))
		return (NULL);
	ptd = (unsigned char *)(dest);
	pts = (unsigned char *)(src);
	tmp = (unsigned char *)malloc(sizeof(unsigned char) * n);
	if (!tmp)
	{
		rewrite(ptd, pts, n);
		return (dest);
	}
	rewrite(tmp, pts, n);
	rewrite(ptd, tmp, n);
	return (dest);
}
