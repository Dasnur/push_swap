/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:30:57 by pgenesis          #+#    #+#             */
/*   Updated: 2020/02/25 20:31:05 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_width_more_3(t_params *m, int size_number)
{
	while (m->f_check_width != ((m->f_otricatelnoe || m->f_check_plus) +
			biggest(size_number, m->f_check_presicion)))
	{
		ft_putchar2(' ');
		m->f_check_width--;
	}
	if ((m->f_check_presicion > 0) && m->f_check_plus &&
			!m->f_otricatelnoe && (m->type == 4 || m->type == 6))
		ft_putchar2('+');
	if (m->f_otricatelnoe && (m->type == 4 || m->type == 6))
	{
		ft_putchar2('-');
		m->ff = 1;
	}
	while (m->f_check_presicion > size_number)
	{
		ft_putchar2('0');
		m->f_check_presicion--;
	}
	ft_put_choose(m);
	if (!m->isnull && (!m->f_check_presicion || m->f_check_presicion == -1) &&
			m->f_check_plus)
		ft_putchar2('+');
}

void	print_width_more_4(t_params *m, int size_number)
{
	if (m->f_otricatelnoe)
		while (m->f_check_width > (size_number +
			m->f_otricatelnoe))
		{
			ft_putchar2(' ');
			m->f_check_width--;
		}
	else
		while (m->f_check_width > (size_number + m->f_check_plus +
			m->f_otricatelnoe))
		{
			ft_putchar2(' ');
			m->f_check_width--;
		}
	if (m->f_check_plus && !m->f_otricatelnoe && (m->type == 4 || m->type == 6))
		ft_putchar2('+');
	ft_put_choose(m);
}

void	print_format_d(t_params *m, int size_number)
{
	int i;

	i = 0;
	if (m->f_check_presicion < -1)
	{
		m->f_check_point = 0;
		m->f_check_presicion = 0;
	}
	if (m->f_check_width <= (size_number + m->f_check_plus) &&
			m->f_check_presicion <= (m->f_check_plus + size_number))
		print_only_d_u(m);
	else if (m->f_check_presicion > m->f_check_width)
		print_p_more(m, size_number, i);
	else if (m->f_check_width >= m->f_check_presicion)
	{
		if (m->f_check_minus)
			print_width_1(m, size_number, i);
		else if (m->f_check_zero && !m->f_check_presicion)
			print_width_2(m, size_number);
		else if (m->f_check_presicion)
			print_width_more_3(m, size_number);
		else
			print_width_more_4(m, size_number);
	}
}

void	d_u(char *line, int i, va_list a, t_params m)
{
	take_all_params_2(line, i, &m, a);
}

void	for_help_f(t_params *m)
{
	if (m->long_long_in > 0)
		ft_putstr2("1444565444646.646542");
	else
		ft_putstr2("-1444565444646.646542");
	return ;
}
