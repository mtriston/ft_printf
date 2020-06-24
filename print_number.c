/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 23:24:58 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/24 20:18:48 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*apply_precision(int precision, char *str)
{
	int		str_len;
	char	*new_str;
	int		sign;

	sign = 0;
	str_len = ft_strlen(str);
	if (precision == 0 && *str == '0' && str_len == 1)
		return (ft_strdup(""));
	if (precision <= str_len)
		return (str);
	if (*str == '+' || *str == '-')
	{
		precision++;
		str_len--;
		sign = 1;
	}
	if (!(new_str = (char *)malloc((precision + 1) * sizeof(char))))
		return (NULL);
	new_str[precision] = '\0';
	ft_memset(new_str, '0', precision);
	*new_str = sign ? *str : *new_str;
	ft_memcpy(new_str + (precision - str_len), sign ? str + 1 : str, str_len);
	free(str);
	return (new_str);
}

char		*get_base(char type)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return ("0123456789");
	else if (type == 'o')
		return ("01234567");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	else
		return (NULL);
}

int			print_number(t_mods list, ptrdiff_t n)
{
	char	*str;
	int		str_len;

	if (!(str = ft_itoa_base(n, get_base(list.type))))
		return (-1);
	if (n == 0 && list.type == 'p')
		if (!(str = ft_strdup("(nil)")))
			return (free_str(str));
	if (!(str = apply_precision(list.precision, str)))
		return (free_str(str));
	if (!(str = apply_flag_sharp(list, str)))
		return (free_str(str));
	if (!(str = apply_flag_plus(list, str, n)))
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
