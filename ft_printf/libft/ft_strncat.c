/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdaway <bdaway@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:33:36 by bdaway            #+#    #+#             */
/*   Updated: 2019/09/22 21:38:11 by bdaway           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*result;
	int		dst_size;

	result = s1;
	dst_size = ft_strlen(s1);
	while (n > 0 && *s2)
	{
		s1[dst_size] = *s2;
		dst_size++;
		s2++;
		n--;
	}
	s1[dst_size] = '\0';
	return (result);
}
