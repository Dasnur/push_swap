/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlonglong2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:56:52 by pgenesis          #+#    #+#             */
/*   Updated: 2020/02/25 20:56:54 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putlonglong2(long long int nb)
{
	char				a;
	long long int		b;

	if (nb < 0)
	{
		ft_putchar2('-');
		if (nb < -9000000000000000000)
		{
			ft_putchar2('9');
			nb = nb + 9000000000000000000;
		}
		nb *= -1;
	}
	if (nb >= 10)
		ft_putlonglong2(nb / 10);
	b = nb % 10;
	a = '0' + b;
	ft_putchar2(a);
}
