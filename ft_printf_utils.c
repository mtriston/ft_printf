/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:08:22 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/27 00:04:15 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_type(int c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'x' || c == 's' || \
	c == 'c' || c == 'X' || c == 'u' || c == 'p' || c == '%')
		return (1);
	else
		return (0);
}

int		is_flag(int c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
		return (1);
	else
		return (0);
}

int		ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int		free_str(char *str)
{
	if (str)
		free(str);
	return (-1);
}
