/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <pgenesis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:33:53 by pgenesis          #+#    #+#             */
/*   Updated: 2020/07/26 12:04:49 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	long long int			res;
	int						i;
	int						flag;

	flag = 0;
	i = 0;
	res = 0;
	while (((nptr[i] > 8) && (nptr[i] < 14)) || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '-')
		flag = 1;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
		i++;
	while ((nptr[i] > 47) && (nptr[i] < 58))
	{
		res = res * 10 + (nptr[i++] - '0');
		if ((res > 2147483647) && (flag != 1))
			return (-1);
		if ((res > 2147483648) && (flag == 1))
			return (0);
	}
	if (flag == 1)
		res = res * (-1);
	return (res);
}
