/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 20:58:58 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/01 15:45:03 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include <stdio.h>

/* int	num_of_arguments(const char *str)
{
	int		num_of_arguments;
	char	*s;

	num_of_arguments = 0;
	s = (char *)str;
	while (s != NULL)
		if (s = ft_strchr(s, '%'))
		{
			num_of_arguments++;
			s++;
		}
	return (num_of_arguments);
}
*/

static char	*print_argument(char *str, va_list ap)
{
	if (*str == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (*str == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (*str == '%')
		ft_putchar_fd('%', 1);
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

int		main()
{
	char *name = "Alex";
	char *name2 = "Anna";
	int x = 2;
	ft_printf("Hello, %s and %s. You are %d great persons%c100%%\n", name, name2, x, '!');
	return 0;
}
