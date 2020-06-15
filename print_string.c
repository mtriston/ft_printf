/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:13:13 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/15 16:05:25 by mtriston         ###   ########.fr       */
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
	str = new_str;
	return (str);
}

int			print_string(char *flags, int width, int precision, char *str)
{
	if (str)
		str = ft_strdup(str);
	else if (!str)
		str = ft_strdup("(null)");
	if (!(str = apply_str_precision(precision, str)))
		return (-1);
	if (!(str = apply_flag_space(flags, str, 's')))
		return (-1);
	if (!(str = apply_width(flags, width, precision, 's', str)))
		return (-1);
	ft_putstr_fd(str, 1);
	return (1);
}

int		print_char(char *flags, int width, int precision, int c)
{
	char *str;

	if (!(str = (char *)malloc(2 * sizeof(char))))
		return (-1);
	str[0] = (unsigned char)c;
	str[1] = '\0';
	if (!(print_string(flags, width, precision, str)))
		return (-1);
	return (1);
}
