/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_modifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 16:17:29 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/24 20:17:50 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_flags(const char *format, int i, t_mods *list)
{
	while (is_flag(format[i]) && format[i])
	{
		if (format[i] == '#')
			list->flag_sharp = 1;
		else if (format[i] == '0')
			list->flag_zero = 1;
		else if (format[i] == '-')
			list->flag_minus = 1;
		else if (format[i] == '+')
			list->flag_plus = 1;
		else if (format[i] == ' ')
			list->flag_space = 1;
		i++;
	}
	if (list->flag_plus == 1)
		list->flag_space = 0;
	return (i);
}

static int	check_width(const char *format, int i, t_mods *list, va_list ap)
{
	if (format[i] == '*')
		list->width = va_arg(ap, int);
	else
		list->width = ft_atoi(&format[i]);
	while (ft_isdigit(format[i]) || format[i] == '*')
		i++;
	if (list->width < 0)
	{
		list->flag_minus = 1;
		list->width *= -1;
	}
	return (i);
}

static int	check_precision(const char *format, int i, t_mods *list, va_list ap)
{
	if (format[i] != '.')
	{
		list->precision = -1;
		return (i);
	}
	if (format[++i] == '*')
	{
		list->precision = va_arg(ap, int);
		return (++i);
	}
	list->precision = ft_atoi(&format[i]);
	while (ft_isdigit(format[i]))
		++i;
	return (i);
}

static int	check_length(const char *format, int i)
{
	while (format[i] && ft_strchr("lhjztL", format[i]))
		i++;
	return (i);
}

int			check_modifications(const char *format, int i, \
		t_mods *list, va_list ap)
{
	i = check_flags(format, i, list);
	i = check_width(format, i, list, ap);
	i = check_precision(format, i, list, ap);
	i = check_length(format, i);
	if (is_type(format[i]))
		list->type = format[i];
	return (format[i] != '\0' ? i + 1 : i);
}
