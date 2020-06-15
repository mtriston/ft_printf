/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 17:24:09 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/15 16:05:12 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_flag_space(char *flags, char *str, char type)
{
	char *new_str;

	if (type == 's' && *str != '\0')
		return (str);
	if (*str == '-' || *str == '+')
		return (str);
	if (!ft_strchr(flags, ' '))
		return (str);
	if (!(new_str = ft_strjoin(" ", str)))
		return (NULL);
	return (new_str);
}

char	*apply_flag_plus(char *flags, char *str, int nbr, char type)
{
	char *new_str;
	
	if (nbr < 0 || !ft_strchr(flags, '+') || (type != 'd' && type != 'i'))
		return (str);
	if (!(new_str = ft_strjoin("+", str)))
		return (NULL);
	return (new_str);
}

static char	*get_prefix(char type)
{
	if (type == 'p' || type == 'x')
			return ("0x");
	else if (type == 'X')
			return ("0X");
	else if (type == 'o')
			return ("0");
	else
		return ("");
}

char	*apply_flag_sharp(char *flags, char *str, char type)
{
	char	*new_str;
	int		i;

	i = 0;
	if (!ft_strchr(flags, '#') && type != 'p')
		return (str);
	while (str[i] && str[i] == '0')
		if (str[++i] == '\0')
			return (str);
	if (!(new_str = ft_strjoin(get_prefix(type), str)))
		return (NULL);
	return (new_str);
}
