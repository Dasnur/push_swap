/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <pgenesis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:11:07 by pgenesis          #+#    #+#             */
/*   Updated: 2020/07/26 13:51:09 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	p;
	int	t;

	t = 0;
	p = 0;
	i = 0;
	while (haystack[p] != '\0')
	{
		if (needle[i] == haystack[p++])
			i++;
		else
		{
			p = ++t;
			i = 0;
		}
		if ((needle[i] == '\0') && (i == 0))
			return ((char *)(&(haystack[0])));
		if (needle[i] == '\0')
			return ((char *)(&(haystack[t])));
	}
	if ((haystack[p] == '\0') && ((needle[i]) == '\0'))
		return ((char*)(&(haystack[0])));
	return (NULL);
}
