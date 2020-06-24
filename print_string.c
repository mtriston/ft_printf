/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:13:13 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/24 17:12:24 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_str_precision(int precision, char *str)
{
	char *new_str;

	if (!str)
		return (NULL);
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

char		*print_string(t_mods list, char *str)
{
	if (str)
		str = ft_strdup(str);
	else if (!str)
		str = ft_strdup("(null)");
	if (!(str = apply_str_precision(list.precision, str)))
		return (NULL);
	if (!(str = apply_flag_space(list, str)))
		return (NULL);
	if (!(str = apply_width(list, str)))
		return (NULL);
	return (str);
}

char		*print_char(t_mods *list, int c)
{
	char str[2];

	str[0] = c;
	str[1] = '\0';
	list->type = 's';
	return (print_string(*list, str));
}
