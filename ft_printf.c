/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 20:58:58 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/05 23:17:12 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*check_flags(char *str, char *flags)
{
	char *all_flags;
	int i;

	all_flags = "#0- +'I";
	i = 0;
	ft_bzero(flags, 7);
	while (ft_strchr(all_flags, *str))
		flags[i++] = *str++;
	return (str);

}

static char	*check_width(char *str, int *width, va_list ap)
{
	if (*str == '*')
	{
		*width = va_arg(ap, int);
		return (str + 1);
	}
	if (!(ft_isdigit(*str)))
	{
		*width = -1;
		return (str + 1);
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
static void	check_type(char *flags, int width, int precision, char type, va_list ap)
{
	if (type == 's')
		print_string(flags, width, precision, va_arg(ap, char *));
	/*)
	else if (type == 'd' || type == 'i')
		print_integer(flags, width, precision, va_arg(ap, int));
	else if (type == 'c')
		print_char(flags, width, precision, va_arg(ap, int));
	else if (type == 'x' || type == 'X')
		print_hex(type, flags, width, precision, va_arg(ap, size_t));
	else if (type == 'p')
		print_pointer(flags, width, precision, va_arg(ap, intptr_t));
		*/
}

static char	*print_argument(char *str, va_list ap)
{
	char	flags[7];
	int		width;
	int		precision;
	char	type;

	str = check_flags(str, flags);
	str = check_width(str, &width, ap);
	str = check_precision(str, &precision, ap);
	type = *str;
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
			if (*(++str) == '%')
			{
				ft_putchar_fd(*str, 1);
				str++;
			}
			else
				str = print_argument(str, ap);
		}
		else
			ft_putchar_fd(*str++, 1);
	}
	return (0);
}
