/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 20:58:58 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/24 10:20:37 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_arg(char *flags, int width, int prec, char type, va_list ap)
{
	if (type == 's')
		return (print_string(flags, width, prec, va_arg(ap, char *)));
	else if (type == 'c' || type == 'C')
		return (print_char(flags, width, prec, va_arg(ap, int)));
	else if (type == 'd' || type == 'i')
		return (print_number(type, flags, width, prec, va_arg(ap, int)));
	else if (type == 'o')
		return (print_number(type, flags, width, prec, va_arg(ap, size_t)));
	else if (type == 'x' || type == 'X' || type == 'u')
		return (print_number(type, flags, width, prec, va_arg(ap, size_t)));
	else if (type == 'p')
		return (print_number(type, flags, width, prec, va_arg(ap, intptr_t)));
	else if (type == '%')
		return (ft_strdup("%"));
	else
		return (NULL);
}
char		*check_modification()
{
	
}
static char	*join_argument(char **str, char *format, va_list ap)
{
	char	flags[6];
	int		width;
	int		precision;
	char	length[3];
	char	type;
	char	*arg;
	char	*tmp;

	if (!(format = check_flags(format, flags)))
		return (NULL);
	if (!(format = check_width(format, &width, ap)))
		return (NULL);
	if (!(format = check_precision(format, &precision, ap)))
		return (NULL);
	if (!(format = check_length(format, length)))
		return (NULL);
	type = *format;
	if (type == '\0')
		return (format);
	if (!(arg = handle_arg(flags, width, precision, type, ap)))
		return (NULL);
	tmp = *str;
	if (!(*str = ft_strjoin(*str, arg)))
		return (NULL);
	free(tmp);
	free(arg);
	return (format + 1);
}

static char	*join_str(char **str, char *format)
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

int			ft_printf(const char *format, ...)
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
		{
			if (!(str = join_argument(&new_str, ++str, ap)))
				return (-1);
		}
		else
		{
			if (!(str = join_str(&new_str, str)))
				return (-1);
		}
	}
	ft_putstr_fd(new_str, 1);
	str_len = ft_strlen(new_str);
	free(new_str);
	return (str_len);
}
