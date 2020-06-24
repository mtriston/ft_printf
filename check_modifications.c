/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_modifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 16:17:29 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/24 14:53:36 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_flags(char *format, t_mods *list)
{
	while (is_flag(*format) && *format)
	{
		if (*format == '#')
			list->flag_sharp = 1;
		else if (*format == '0')
			list->flag_zero = 1;
		else if (*format == '-')
			list->flag_minus = 1;
		else if (*format == '+')
			list->flag_plus = 1;
		else if (*format == ' ')
			list->flag_space = 1;
		format++;
	}
	if (list->flag_plus == 1)
		list->flag_space = 0;
	return (format);
}

char	*check_width(char *format, t_mods *list, va_list ap)
{
	if (*format == '*')
		list->width = va_arg(ap, int);
	else
		list->width = ft_atoi(format);
	while (ft_isdigit(*format) || *format == '*')
		format++;
	if (list->width < 0)
	{
		list->flag_minus = 1;
		list->width *= -1;
	}
	return (format);
}

char	*check_precision(char *format, t_mods *list, va_list ap)
{
	if (*format != '.')
	{
		list->precision = -1;
		return (format);
	}
	if (*++format == '*')
	{
		list->precision = va_arg(ap, int);
		return (format + 1);
	}
	list->precision = ft_atoi(format);
	while (ft_isdigit(*format))
		format++;
	return (format);
}

int		is_type(int c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'x' || c == 's' || \
	c == 'c' || c == 'X' || c == 'u' || c == 'p' || c == '%')
		return (1);
	else
		return (0);
}

int		is_flag(int c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
		return (1);
	else
		return (0);
}
