/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 15:33:42 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/22 23:33:40 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*move_prefix(char *flags, char *str, char *new_str, int precision)
{
	int i;

	i = 0;
	if (ft_strchr(flags, '-') || !ft_strchr(flags, '0') || precision >= 0)
		return (str);
	if (str[i] == ' ')
		i++;
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		i += 2;

	ft_memcpy(new_str, str, i);
	return (str + i);
}

static char	check_blank(char *flags, int precision, char type)
{
	if (ft_strchr(flags, '0') && precision < 0 && type != 's' && \
			!ft_strchr(flags, '-'))
		return ('0');
	else
		return (' ');
}

static int	add_flag(char *flags, int width)
{
	if (width < 0)
	{
		if (!ft_strchr(flags, '-'))
		{
			while (*flags)
				flags++;
			*flags = '-';
		}
		width = -width;
	}
	return (width);
}

char	*apply_width(char *flags, int width, int precision, char type, char *str)
{
	int		start;
	char	*new_str;
	char	blank;
	int		sign;
	char	*tmp;

	sign = 0;
	if (!str)
		return (NULL);
	if (width < 0)
		width = add_flag(flags, width);
	if (width <= (int)ft_strlen(str))
		return (str);
	if (!(new_str = (char *)malloc((width + 1) * sizeof(char))))
		return (NULL);
	blank = check_blank(flags, precision, type);
	if (blank == '0' && (*str == '-' || *str == '+'))
		sign = 1;
	ft_memset(new_str, blank, width);
	new_str[width] = '\0';
	tmp = str;
	str = move_prefix(flags, str, new_str, precision);
	start = ft_strchr(flags, '-') ? 0 : width - ft_strlen(str) + sign;
	ft_memcpy(new_str + start, sign ? str + 1 : str, ft_strlen(str) - sign);
	*new_str = sign ? *str : *new_str;
	free(tmp);
	return (new_str);
}
