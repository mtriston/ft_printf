/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 20:58:58 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/15 16:05:33 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*check_flags(char *str, char *flags)
{
	char	*all_flags;
	int		i;

	all_flags = "#0- +";
	i = 0;
	ft_bzero(flags, 6);
	while (ft_strchr(all_flags, *str))
		flags[i++] = *str++;
	return (str);
}

static char	*check_width(char *str, int *width, va_list ap)
{
	*width = 0;
	if (*str == '*')
	{
		*width = va_arg(ap, int);
		return (str + 1);
	}
	if (!(ft_isdigit(*str)))
	{
		*width = -1;
		return (str);
	}
	*width = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	return (str);
}

static char	*check_precision(char *str, int *precision, va_list ap)
{
	*precision = 0;
	if (*str != '.')
	{
		*precision = -1;
		return (str);
	}
	else if (*++str == '*')
	{
		*precision = va_arg(ap, int);
		return (str + 1);
	}
	else if (ft_isdigit(*str))
	{
		*precision = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
	}
	return (str);
}

static char *check_length(char *str, char *length)
{
	char *all_mods;
	int i;

	all_mods = "lLhjzt";
	i = 0;
	ft_bzero(length, 3);
	while (*str && ft_strchr(all_mods, *str) && i < 3)
		length[i++] = *str++;
	return (str);
}

static void	check_type(char *flags, int width, int precision, char type, va_list ap)
{
	if (type == 's')
		print_string(flags, width, precision, va_arg(ap, char *));
	if (type == 'c' || type == 'C')
		print_char(flags, width, precision, va_arg(ap, int));
	else if (type == 'd' || type == 'i' || type == 'o')
		print_number(type, flags, width, precision, va_arg(ap, int));
	else if (type == 'x' || type == 'X' || type == 'u')
		print_number(type, flags, width, precision, va_arg(ap, size_t));
	else if (type == 'p')
		print_number(type, flags, width, precision, va_arg(ap, intptr_t));
	else if (type == '%')
		ft_putchar_fd('%', 1);
}

static char	*print_argument(char *str, va_list ap)
{
	char	flags[6];
	int		width;
	int		precision;
	char	length[3];
	char	type;

	str = check_flags(str, flags);
	str = check_width(str, &width, ap);
	str = check_precision(str, &precision, ap);
	str = check_length(str, length);
	type = *str;
	if (type == '\0')
		return (str);
	check_type(flags, width, precision, type, ap);
	return (str + 1);
}

int			ft_printf(const char *format, ...)
{
	char	*str;
	va_list	ap;

	str = (char *)format;
	va_start(ap, format);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str = print_argument(++str, ap);
		}
		else
			ft_putchar_fd(*str++, 1);
	}
	return (0);
}
