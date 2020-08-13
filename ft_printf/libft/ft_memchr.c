/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdaway <bdaway@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:56:27 by bdaway            #+#    #+#             */
/*   Updated: 2019/09/20 18:36:47 by bdaway           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		new;

	ptr = (unsigned char *)s;
	new = (unsigned char)c;
	while (n > 0)
	{
		if (*ptr == new)
			return ((void*)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
