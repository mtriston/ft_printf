/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_modifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 16:17:29 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/15 16:28:08 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_flags(char *str, char *flags)
{
	char	*all_flags;
	int		i;

	all_flags = "#0- +";
	i = 0;
	ft_bzero(flags, 6);
	while (ft_strchr(all_flags, *str))
		flags[i++] = *str++;
	return (str);
}

char	*check_width(char *str, int *width, va_list ap)
{
	*width = 0;
	if (*str == '*')
	{
		*width = va_arg(ap, int);
		return (str + 1);
	}
	if (!(ft_isdigit(*str)))
	{
		*width = -1;
		return (str);
	}
	*width = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	return (str);
}

char	*check_precision(char *str, int *precision, va_list ap)
{
	*precision = 0;
	if (*str != '.')
	{
		*precision = -1;
		return (str);
	}
	else if (*++str == '*')
	{
		*precision = va_arg(ap, int);
		return (str + 1);
	}
	else if (ft_isdigit(*str))
	{
		*precision = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
	}
	return (str);
}

char *check_length(char *str, char *length)
{
	char *all_mods;
	int i;

	all_mods = "lLhjzt";
	i = 0;
	ft_bzero(length, 3);
	while (*str && ft_strchr(all_mods, *str) && i < 3)
		length[i++] = *str++;
	return (str);
}
