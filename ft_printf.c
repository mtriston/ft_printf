/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <mtriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 13:44:48 by mtriston          #+#    #+#             */
/*   Updated: 2020/05/31 16:04:33 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include <stdio.h>

int	num_of_arguments(const char *str)
{
	int		num_of_arguments;
	char	*s;

	num_of_arguments = 0;
	s = (char *)str;
	while (s)
		if (s = ft_strchr(s, '%'))
			num_of_arguments++;
	return (num_of_arguments);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int n = num_of_arguments(format);
	va_start(ap, format);
	ft_putnbr_fd(n, 1);
	return (0);
}

int	main()
{
	int n = 5;

	ft_printf("Hello%d", n);
	return 0;
}
