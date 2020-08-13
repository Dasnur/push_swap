/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <pgenesis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:06:03 by pgenesis          #+#    #+#             */
/*   Updated: 2020/07/26 13:51:02 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (s[i] == c)
		return ((char*)(&(s[i])));
	i--;
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char*)(&(s[i])));
		i--;
	}
	return (NULL);
}
