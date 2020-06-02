/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 20:58:58 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/03 00:20:50 by mtriston         ###   ########.fr       */
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
	else if (*str == 'x')
		ft_putnbr_base(va_arg(ap, size_t), "0123456789abcdef");
	else if (*str == 'X')
		ft_putnbr_base(va_arg(ap, size_t), "0123456789ABCDEF");
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
	//char *name = "Alex";
	//char *name2 = "Anna";
//printf("%p\n", &name);
	//ft_printf("Hello, %s and %s. You are %d great persons%c100%%\n", name, name2, x, '!');
	//ft_putnbr_fd(-2147483648, 1);
	//ft_putchar_fd('\n', 1);
	ft_printf("%x\n", 15);
	printf("%x", 15);
	return 0;
}
