/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 20:58:58 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/28 13:56:13 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_mods	list_init(void)
{
	t_mods list;

	list.flag_sharp = 0;
	list.flag_zero = 0;
	list.flag_minus = 0;
	list.flag_plus = 0;
	list.flag_space = 0;
	list.width = 0;
	list.precision = 0;
	list.type = 0;
	return (list);
}

static int		print_arg(t_mods *list, va_list ap, int count)
{
	int return_value;

	return_value = -1;
	if (list->type == 's')
		return_value = print_string(*list, va_arg(ap, char *));
	else if (list->type == 'c')
		return_value = print_char(list, va_arg(ap, int));
	else if (list->type == 'd' || list->type == 'i')
		return_value = print_number(*list, va_arg(ap, int));
	else if (list->type == 'x' || list->type == 'X' || \
			list->type == 'u' || list->type == 'o')
		return_value = print_number(*list, va_arg(ap, unsigned int));
	else if (list->type == 'p')
		return_value = print_number(*list, va_arg(ap, intptr_t));
	else if (list->type == '%')
		return_value = print_char(list, '%');
	if (return_value == -1)
		return (-1);
	return (count + return_value);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;
	t_mods	list;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			list = list_init();
			i = check_modifications(format, ++i, &list, ap);
			count = print_arg(&list, ap, count);
			if (count == -1)
				return (-1);
		}
		else
			count += ft_putchar(format[i++]);
	}
	va_end(ap);
	return (count);
}
