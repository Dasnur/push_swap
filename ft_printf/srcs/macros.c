/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:15:27 by pgenesis          #+#    #+#             */
/*   Updated: 2020/02/26 06:54:37 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long int	always_pozitive(long long int x)
{
	if (x >= 0)
		return (x);
	else
		return (-x);
}

int				nalicie_minusa(long long int x)
{
	if (x < 0)
		return (1);
	else
		return (0);
}

int				biggest(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

int				is_null_lli(long long x)
{
	if (x == 0)
		return (0);
	else
		return (1);
}

int				is_null_ulli(unsigned long long x)
{
	if (x == 0)
		return (0);
	else
		return (1);
}
