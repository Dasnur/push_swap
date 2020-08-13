/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <pgenesis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:08:07 by pgenesis          #+#    #+#             */
/*   Updated: 2020/07/26 13:49:00 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	long long int	ch;

	ch = (long long int)(n);
	if (ch < 0)
		return (NULL);
	i = 0;
	dest1 = (unsigned char*)dest;
	while (i < n)
	{
		dest1[i] = c;
		i++;
	}
	return (dest1);
}
