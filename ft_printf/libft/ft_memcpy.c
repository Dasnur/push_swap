/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdaway <bdaway@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:54:06 by bdaway            #+#    #+#             */
/*   Updated: 2019/09/26 18:44:07 by bdaway           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	dst_ptr = (unsigned char*)dst;
	src_ptr = (const unsigned char*)src;
	while (n > 0)
	{
		if (dst_ptr == NULL && src_ptr == NULL)
			return (NULL);
		*(dst_ptr++) = *(src_ptr++);
		n--;
	}
	return (dst);
}
