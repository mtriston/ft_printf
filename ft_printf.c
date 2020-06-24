/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 20:58:58 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/24 17:18:38 by mtriston         ###   ########.fr       */
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

static int		print_arg(t_mods *list, va_list ap)
{
	if (list->type == 's')
		return (print_string(*list, va_arg(ap, char *)));
	else if (list->type == 'c')
		return (print_char(list, va_arg(ap, int)));
	else if (list->type == 'd' || list->type == 'i')
		return (print_number(*list, va_arg(ap, int)));
	else if (list->type == 'o')
		return (print_number(*list, va_arg(ap, size_t)));
	else if (list->type == 'x' || list->type == 'X' || list->type == 'u')
		return (print_number(*list, va_arg(ap, size_t)));
	else if (list->type == 'p')
		return (print_number(*list, va_arg(ap, intptr_t)));
	else if (list->type == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		tmp;
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
			if ((tmp = print_arg(&list, ap)) < 0 && (count += tmp))
				return (-1);
		}
		else
			count += ft_putchar(format[i++]);
	}
	return (count);
}
