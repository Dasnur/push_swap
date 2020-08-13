/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdaway <bdaway@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:22:48 by bdaway            #+#    #+#             */
/*   Updated: 2019/09/26 19:38:29 by bdaway           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	k;

	if (*needle == '\0')
		return ((char*)haystack);
	k = 0;
	i = 0;
	while (haystack[k])
	{
		while (haystack[k + i] == needle[i] && needle[i])
		{
			i++;
			if (needle[i] == '\0')
				return ((char*)&haystack[k]);
		}
		i = 0;
		k++;
	}
	return (NULL);
}
