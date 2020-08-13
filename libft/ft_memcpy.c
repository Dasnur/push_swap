/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <pgenesis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:45:26 by pgenesis          #+#    #+#             */
/*   Updated: 2020/07/26 12:08:59 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptd;
	unsigned char	*pts;
	long long int	ch;

	ch = (long long int)(n);
	pts = (unsigned char *)(src);
	ptd = (unsigned char *)(dest);
	if (ch < 0)
		return (NULL);
	if ((pts == NULL) && (ptd == NULL))
		return (dest);
	i = 0;
	while (i < n)
	{
		*ptd = *pts;
		i++;
		ptd++;
		pts++;
	}
	return (dest);
}
