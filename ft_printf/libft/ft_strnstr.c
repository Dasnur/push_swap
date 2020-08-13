/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdaway <bdaway@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:48:17 by bdaway            #+#    #+#             */
/*   Updated: 2019/09/22 22:01:43 by bdaway           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr_hay;
	char	*ptr_needle;
	size_t	i;
	size_t	j;

	ptr_hay = (char *)haystack;
	ptr_needle = (char *)needle;
	i = 0;
	j = 0;
	if (ptr_needle[0] == 0)
		return (&ptr_hay[i]);
	while (ptr_hay[i] && i < len)
	{
		while ((ptr_hay[i + j] == ptr_needle[j])
			&& ptr_needle[j] && (i + j) < len)
		{
			j++;
			if (ptr_needle[j] == 0)
				return (&ptr_hay[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}
