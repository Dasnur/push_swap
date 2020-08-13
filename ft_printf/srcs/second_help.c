/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:04:38 by pgenesis          #+#    #+#             */
/*   Updated: 2020/02/25 21:04:40 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_check_vl(char c)
{
	if (c == 'Z')
		return (1);
	return (0);
}

int		choose_flags_first_help(char *line, int i)
{
	if (line[i] == 'o')
		return (5);
	if (line[i] == 'u' || line[i] == 'D' || line[i] == 'U')
		return (6);
	if (line[i] == 'x')
		return (7);
	if (line[i] == 'X')
		return (8);
	if (line[i] == 'f' || line[i] == 'F')
		return (9);
	if (line[i] == '%')
		return (10);
	return (ft_choose_flags_help(line, i));
}

int		help_ft_printf(char *line, int i)
{
	if (line[i - 1] == '%' && line[i] == '%' &&
		!ft_check_all_flags(line, i + 1))
		return (1);
	return (0);
}

int		help2_ft_printf(va_list a, int g_count)
{
	va_end(a);
	return (g_count);
}
