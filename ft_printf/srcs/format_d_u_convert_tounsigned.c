/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d_u_convert_tounsigned.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdaway <bdaway@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:34:23 by pgenesis          #+#    #+#             */
/*   Updated: 2020/02/26 06:35:37 by bdaway           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	to_u(char *line, int i, t_params m, va_list a)
{
	m.unsigned_long_long_in = va_arg(a, unsigned int);
	m.f_otricatelnoe = nalicie_minusa(m.unsigned_long_long_in);
	m.isnull = is_null_ulli(m.unsigned_long_long_in);
	if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
	{
		if (m.f_check_plus)
			ft_putchar2('+');
		return ;
	}
	print_format_d(&m, number_counting(m.unsigned_long_long_in));
}

void	to_lu(char *line, int i, t_params m, va_list a)
{
	m.unsigned_long_long_in = (long int)va_arg(a, long);
	m.f_otricatelnoe = nalicie_minusa(m.unsigned_long_long_in);
	m.isnull = is_null_ulli(m.unsigned_long_long_in);
	if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
	{
		if (m.f_check_plus)
			ft_putchar2('+');
		return ;
	}
	print_format_d(&m, number_counting(m.unsigned_long_long_in));
}

void	to_llu(char *line, int i, t_params m, va_list a)
{
	m.unsigned_long_long_in = (unsigned long long)va_arg(a, unsigned long long);
	m.f_otricatelnoe = nalicie_minusa(m.unsigned_long_long_in);
	m.isnull = is_null_ulli(m.unsigned_long_long_in);
	if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
	{
		if (m.f_check_plus)
			ft_putchar2('+');
		return ;
	}
	print_format_d(&m, number_counting(m.unsigned_long_long_in));
}

void	to_hu(char *line, int i, t_params m, va_list a)
{
	m.unsigned_long_long_in = (short unsigned int)va_arg(a, unsigned int);
	m.f_otricatelnoe = nalicie_minusa(m.unsigned_long_long_in);
	m.isnull = is_null_ulli(m.unsigned_long_long_in);
	if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
	{
		if (m.f_check_plus)
			ft_putchar2('+');
		return ;
	}
	print_format_d(&m, number_counting(m.unsigned_long_long_in));
}

void	to_hhu(char *line, int i, t_params m, va_list a)
{
	m.unsigned_long_long_in = (unsigned char)va_arg(a, unsigned int);
	m.f_otricatelnoe = nalicie_minusa(m.unsigned_long_long_in);
	m.isnull = is_null_ulli(m.unsigned_long_long_in);
	if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
		return ;
	print_format_d(&m, number_counting(m.unsigned_long_long_in));
}
