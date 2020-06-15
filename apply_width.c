/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 15:33:42 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/15 16:09:06 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*move_prefix(char *flags, char *str, char *new_str)
{
	if (ft_strchr(flags, '-'))
		return (str);
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
	{
		ft_memcpy(new_str, str, 2);
		return (str + 2);
	}
	else
		return (str);
}

static char	check_blank(char *flags, int precision, char type)
{
	if (ft_strchr(flags, '0') && precision < 0 && type != 's')
		return ('0');
	else
		return (' ');
}

char	*apply_width(char *flags, int width, int precision, char type, char *str)
{
	int		start;
	char	*new_str;
	char	blank;
	int		sign;

	sign = 0;
	if (width <= (int)ft_strlen(str))
		return (str);
	if (!(new_str = (char *)malloc((width + 1) * sizeof(char))))
		return (NULL);
	blank = check_blank(flags, precision, type);
	if (blank == '0' && (*str == '-' || *str == '+'))
		sign = 1;
	ft_memset(new_str, blank, width);
	new_str[width] = '\0';
	str = move_prefix(flags, str, new_str);
	start = ft_strchr(flags, '-') ? 0 : width - ft_strlen(str) - sign;
	ft_memcpy(new_str + start, sign ? str + 1 : str, ft_strlen(str) - sign);
	*new_str = sign ? *str : *new_str;
	return (str = new_str);
}

