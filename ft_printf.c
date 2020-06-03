/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 20:58:58 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/03 23:15:41 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include <stdio.h>

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
		ft_putunbr_base(va_arg(ap, size_t), "0123456789abcdef");
	else if (*str == 'X')
		ft_putunbr_base(va_arg(ap, size_t), "0123456789ABCDEF");
	else if (*str == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_putunbr_base(va_arg(ap, intptr_t), "0123456789abcdef");
	}
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
			str = print_argument(++str, ap);
		else
			ft_putchar_fd(*str++, 1);
		
	}
	return (0);
}

int		main()
{
	int a;
	//char *name = "Alex";
	//char *name2 = "Anna";
//printf("%p\n", &name);
	//ft_printf("Hello, %s and %s. You are %d great persons%c100%%\n", name, name2, x, '!');
	//ft_putnbr_fd(-2147483648, 1);
	//ft_putchar_fd('\n', 1);
//	ft_printf("%x\n", 15);
	printf("%p\n", &a);
	ft_printf("%p", &a);
	return 0;
}
