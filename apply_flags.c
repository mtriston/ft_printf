/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 17:24:09 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/24 17:13:14 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*apply_flag_space(t_mods list, char *str)
{
	char *new_str;

	if (!str)
		return (NULL);
	if (list.type == 's' && *str != '\0')
		return (str);
	if (*str == '-' || *str == '+')
		return (str);
	if (!list.flag_space)
		return (str);
	if (!(new_str = ft_strjoin(" ", str)))
		return (NULL);
	free(str);
	return (new_str);
}

char		*apply_flag_plus(t_mods list, char *str, int nbr)
{
	char *new_str;

	if (!str)
		return (NULL);
	if (nbr < 0 || !list.flag_plus || (list.type != 'd' && list.type != 'i'))
		return (str);
	if (!(new_str = ft_strjoin("+", str)))
		return (NULL);
	free(str);
	return (new_str);
}

static char	*get_prefix(t_mods list)
{
	if (list.type == 'p' || list.type == 'x')
		return ("0x");
	else if (list.type == 'X')
		return ("0X");
	else if (list.type == 'o')
		return ("0");
	else
		return ("");
}

char		*apply_flag_sharp(t_mods list, char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	if ((!list.flag_sharp && list.type != 'p') || \
		(ft_atoi_base(str, get_base(list.type)) == 0 && list.type != 'o'))
		return (str);
	if (list.type == 'o' && *str == '0')
		return (str);
	while (str[i] && str[i] == '0')
		if (str[++i] == '\0')
			return (str);
	if (!(new_str = ft_strjoin(get_prefix(list), str)))
		return (NULL);
	free(str);
	return (new_str);
}
