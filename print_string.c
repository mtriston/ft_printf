/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:13:13 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/22 22:42:16 by mtriston         ###   ########.fr       */
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

char		*print_string(char *flags, int width, int precision, char *str)
{
	if (str)
		str = ft_strdup(str);
	else if (!str)
		str = ft_strdup("(null)");
	if (!(str = apply_str_precision(precision, str)))
		return (NULL);
	if (!(str = apply_flag_space(flags, str, 's')))
		return (NULL);
	if (!(str = apply_width(flags, width, precision, 's', str)))
		return (NULL);
	return (str);
}

char		*print_char(char *flags, int width, int precision, int c)
{
	char str[2];

	str[0] = (unsigned char)c;
	str[1] = '\0';
	return (print_string(flags, width, precision, str));
}
