/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <pgenesis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:34:15 by bdaway            #+#    #+#             */
/*   Updated: 2020/07/26 12:18:24 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_maxmin(unsigned long long int res, long long int negative)
{
	if (res > 9223372036854775807 && negative == 1)
		return (-1);
	if (res > 9223372036854775807 && negative == -1)
		return (0);
	return (res * negative);
}

int			ft_atoi(const char *str)
{
	unsigned long long	i;
	size_t				nbr;
	size_t				negative;

	nbr = 0;
	negative = 1;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == ' ') ||
			(str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (ft_maxmin(nbr, negative));
}
