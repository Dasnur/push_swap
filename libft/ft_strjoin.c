/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <pgenesis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:11:33 by pgenesis          #+#    #+#             */
/*   Updated: 2020/07/26 13:50:20 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		i;
	int		j;
	int		len1;
	int		len2;

	i = 0;
	j = 0;
	tmp = NULL;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(tmp = ft_strnew(len1 + len2 + 1)))
		return (NULL);
	while (len1--)
	{
		tmp[i] = s1[i];
		i++;
	}
	while (len2--)
		tmp[i++] = s2[j++];
	return (tmp);
}
