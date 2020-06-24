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

static char		*handle_arg(t_mods *list, va_list ap)
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
		return (ft_strdup("%"));
	else
		return (NULL);
}

static char		*join_argument(char **str, char *format, va_list ap)
{
	char	*arg;
	char	*tmp;
	t_mods	list;

	list = list_init();
	if (!(format = check_flags(format, &list)))
		return (NULL);
	if (!(format = check_width(format, &list, ap)))
		return (NULL);
	if (!(format = check_precision(format, &list, ap)))
		return (NULL);
	if (is_type(*format))
		list.type = *format;
	else
		return (NULL);
	if (!(arg = handle_arg(&list, ap)))
		return (NULL);
	tmp = *str;
	if (!*arg)
		return (format + 1);
	if (!(*str = ft_strjoin(*str, arg)))
		return (NULL);
	free(tmp);
	free(arg);
	return (format + 1);
}

static char		*join_str(char **str, char *format)
{
	int		i;
	char	*tmp;
	char	*sub_str;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	tmp = *str;
	if (!(sub_str = ft_substr(format, 0, i)))
		return (NULL);
	if (!(*str = ft_strjoin(*str, sub_str)))
		return (NULL);
	free(tmp);
	free(sub_str);
	return (format + i);
}

int				ft_printf(const char *format, ...)
{
	char	*new_str;
	char	*str;
	va_list	ap;
	int		str_len;

	if (!format)
		return (-1);
	if (!(new_str = ft_calloc(1, sizeof(char))))
		return (-1);
	str = (char *)format;
	va_start(ap, format);
	while (*str != '\0')
	{
		if (*str == '%')
			str = join_argument(&new_str, ++str, ap);
		else
			str = join_str(&new_str, str);
		if (!str)
			return (-1);
	}
	ft_putstr_fd(new_str, 1);
	str_len = ft_strlen(new_str);
	free(new_str);
	return (str_len);
}
