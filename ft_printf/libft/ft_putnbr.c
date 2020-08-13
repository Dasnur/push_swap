/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdaway <bdaway@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:15:59 by bdaway            #+#    #+#             */
/*   Updated: 2019/09/19 19:17:29 by bdaway           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putnbr(-2);
			ft_putnbr(147483648);
			return ;
		}
		ft_putchar('-');
		n = -n;
		ft_putnbr(n);
	}
	else if (n >= 0 && n < 10)
		ft_putchar(n + 48);
}
