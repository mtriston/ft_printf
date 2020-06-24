/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 15:33:42 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/24 14:21:22 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*move_prefix(t_mods list, char *str, char *new_str)
{
	int i;

	i = 0;
	if (list.flag_minus || !list.flag_zero || list.precision >= 0)
		return (str);
	if (str[i] == ' ')
		i++;
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		i += 2;
	ft_memcpy(new_str, str, i);
	return (str + i);
}

static char	check_blank(t_mods list)
{
	if (list.flag_zero && list.precision < 0 && \
			list.type != 's' && !list.flag_minus)
		return ('0');
	else
		return (' ');
}

char		*apply_width(t_mods list, char *str)
{
	int		start;
	char	*new_str;
	char	blank;
	int		sign;
	char	*tmp;

	sign = 0;
	if (list.width <= (int)ft_strlen(str))
		return (str);
	if (!(new_str = (char *)malloc((list.width + 1) * sizeof(char))))
		return (NULL);
	blank = check_blank(list);
	if (blank == '0' && (*str == '-' || *str == '+'))
		sign = 1;
	ft_memset(new_str, blank, list.width);
	new_str[list.width] = '\0';
	tmp = str;
	str = move_prefix(list, str, new_str);
	start = list.flag_minus ? 0 : list.width - ft_strlen(str) + sign;
	ft_memcpy(new_str + start, sign ? str + 1 : str, ft_strlen(str) - sign);
	*new_str = sign ? *str : *new_str;
	free(tmp);
	return (new_str);
}
