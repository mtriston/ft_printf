/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 20:58:58 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/17 22:19:16 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_argument(char *flags, int width, int precision, char type, va_list ap)
{
	float tmp;
	
	tmp = 1;
	if (type == 's')
		print_string(flags, width, precision, va_arg(ap, char *));
	if (type == 'c' || type == 'C')
		print_char(flags, width, precision, va_arg(ap, int));
	else if (type == 'd' || type == 'i')
		print_number(type, flags, width, precision, va_arg(ap, int));
	else if (type == 'o')
		print_number(type, flags, width, precision, va_arg(ap, size_t));
	else if (type == 'x' || type == 'X' || type == 'u')
		print_number(type, flags, width, precision, va_arg(ap, size_t));
	else if (type == 'p')
		print_number(type, flags, width, precision, va_arg(ap, intptr_t));
	else if (type == 'f')
	{
		if (tmp)
			tmp = va_arg(ap, double);
				
	}
	else if (type == '%')
		ft_putchar_fd('%', 1);
}

static char	*handle_next_argument(char *str, va_list ap)
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
	print_argument(flags, width, precision, type, ap);
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
			str = handle_next_argument(++str, ap);
		else
			ft_putchar_fd(*str++, 1);
	}
	return (0);
}
