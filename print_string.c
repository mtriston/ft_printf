/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:13:13 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/05 23:13:44 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_string(char *flags, int width, int precision, char *str)
{
	int		str_length;
	int		start_index;
	char	total_string[width + 1];
	
	str_length = ft_strlen(str);
	if (precision >= 0)
		str_length = (str_length > precision) ? precision : str_length;
	start_index = 0;
	if (width > str_length)
	{	
		if (!(ft_strchr(flags, '-')))
			start_index = width - str_length;
		ft_memset(total_string, ' ', width);
		total_string[width] = '\0';
		ft_memcpy(total_string + start_index, str, str_length);
		ft_putstr_fd(total_string, 1);
	}
	else
		ft_putstr_fd(str, 1);
	if (*str == '\0' && ft_strchr(flags, ' '))
		ft_putchar_fd(' ', 1);
}
