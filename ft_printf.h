/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 19:06:45 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/24 14:53:21 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

typedef struct	s_mods
{
	int			flag_sharp;
	int			flag_zero;
	int			flag_minus;
	int			flag_plus;
	int			flag_space;
	int			width;
	int			precision;
	int			length;
	int			type;
}				t_mods;

int		is_type(int c);
int		is_flag(int c);
char	*get_base(char type);
char	*check_flags(char *str, t_mods *list);
char	*check_width(char *str, t_mods *list, va_list ap);
char	*check_precision(char *str, t_mods *list, va_list ap);
char	*apply_width(t_mods list, char *str);
char	*apply_precision(int precision, char *str);
char	*apply_flag_plus(t_mods list, char *str, int nbr);
char	*apply_flag_sharp(t_mods list, char *str);
char	*apply_flag_space(t_mods list, char *str);
char	*print_string(t_mods list, char *str);
char	*print_number(t_mods list, ptrdiff_t nbr);
char	*print_char(t_mods *list, int c);
int		ft_printf(const char *format, ...);

#endif
