/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdaway <bdaway@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:52:22 by bdaway            #+#    #+#             */
/*   Updated: 2019/09/20 21:44:39 by bdaway           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_ptr;
	unsigned char		*src_ptr;
	size_t				i;

	dst_ptr = (unsigned char*)dst;
	src_ptr = (unsigned char*)src;
	i = 0;
	while (n > i)
	{
		dst_ptr[i] = src_ptr[i];
		if (dst_ptr[i] == (unsigned char)c)
		{
			return (dst_ptr + i + 1);
		}
		i++;
	}
	return (0);
}
