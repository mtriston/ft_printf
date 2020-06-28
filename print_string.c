/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:13:13 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/27 00:26:06 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_str_precision(int precision, char *str)
{
	char *new_str;

	if (precision < 0)
		return (str);
	if ((unsigned int)precision >= ft_strlen(str))
		return (str);
	if (ft_strncmp(str, "(null)", 6) == 0)
		return (ft_strdup(""));
	if (!(new_str = ft_substr(str, 0, precision)))
		return (NULL);
	free(str);
	return (new_str);
}

int			print_string(t_mods list, char *str)
{
	int str_len;

	if (str)
	{
		if (!(str = ft_strdup(str)))
			return (-1);
	}
	else if (!str)
	{
		if (!(str = ft_strdup("(null)")))
			return (-1);
	}
	if (!(str = apply_str_precision(list.precision, str)))
		return (free_str(str));
	if (!(str = apply_flag_space(list, str)))
		return (free_str(str));
	if (!(str = apply_width(list, str)))
		return (free_str(str));
	str_len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (str_len);
}

int			print_char(t_mods *list, int c)
{
	int width;

	width = list->width;
	if (list->flag_minus)
	{
		ft_putchar(c);
		while (width-- > 1)
			ft_putchar(' ');
	}
	else
	{
		while (width-- > 1)
			ft_putchar(' ');
		ft_putchar(c);
	}
	return (list->width > 0 ? list->width : 1);
}
