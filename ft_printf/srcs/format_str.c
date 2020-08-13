/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:44:01 by pgenesis          #+#    #+#             */
/*   Updated: 2020/02/26 06:16:31 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putstr_with_colour(char *res, t_params *m)
{
	char	*rescolour;

	if (m->f_check_space && !m->f_check_minus && !m->f_check_plus)
		ft_putchar2(' ');
	rescolour = (char *)malloc(sizeof(char) * 150);
	if (m->ff == 1)
		get_colour_line(rescolour, "\e[0;31m", "\e[0m", res);
	if (m->ff == 2)
		get_colour_line(rescolour, "\e[0;32m", "\e[0m", res);
	if (m->ff == 3)
		get_colour_line(rescolour, "\e[0;33m", "\e[0m", res);
	if (m->ff == 4)
		get_colour_line(rescolour, "\e[0;34m", "\e[0m", res);
	if (m->ff == 5)
		get_colour_line(rescolour, "\e[0;35m", "\e[0m", res);
	if (m->ff == 6)
		get_colour_line(rescolour, "\e[0;36m", "\e[0m", res);
	if (m->ff == 0)
		ft_putstr2(res);
	free(rescolour);
}

void	print_first_part(t_params *m, int diff)
{
	ft_putstr_with_colour(m->cha2, m);
	if ((diff = always_pozitive((long long int)m->f_check_width)
				- ft_strlen(m->cha2) + 1) > 0)
	{
		while (--diff > 0)
			ft_putchar2(' ');
	}
}

void	print_second_part(t_params *m, int diff)
{
	if ((diff = always_pozitive((long long int)m->f_check_width)
				- ft_strlen(m->cha2) + 1) > 0)
	{
		while (--diff > 0)
		{
			if (!m->f_check_zero)
				ft_putchar2(' ');
			else
				ft_putchar2('0');
		}
	}
	ft_putstr_with_colour(m->cha2, m);
}

void	print_format_str(t_params *m)
{
	char	*res;
	int		diff;

	if (m->f_check_presicion > 0)
		m->cha2 = ft_strsub(m->cha2, 0, m->f_check_presicion);
	if (m->f_check_presicion == -1)
		m->cha2 = "\0";
	if (m->f_check_width == 0)
		m->f_check_width = ft_strlen(m->cha2);
	if (m->f_check_width != 0)
	{
		if (m->f_check_minus)
			print_first_part(m, diff);
		else
			print_second_part(m, diff);
	}
	if (m->f_check_presicion > 0)
		free(m->cha2);
}

void	format_str(char *line, int i, va_list a)
{
	t_params	m;

	m.i = i;
	while (line[m.i] != 's')
		m.i++;
	m.colour = check_colour(line, ++m.i);
	take_all_params_2(line, i, &m, a);
	free(m.colour);
}
