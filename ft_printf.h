/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 19:06:45 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/26 23:32:24 by mtriston         ###   ########.fr       */
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
	int			type;
}				t_mods;

int				is_type(int c);
int				is_flag(int c);
int				ft_putchar(int c);
int				free_str(char *str);
char			*get_base(char type);
int				check_modifications(const char *format, int i, t_mods *list, \
				va_list ap);
char			*apply_width(t_mods list, char *str);
char			*apply_precision(int precision, char *str);
char			*apply_flag_plus(t_mods list, char *str, int nbr);
char			*apply_flag_sharp(t_mods list, char *str);
char			*apply_flag_space(t_mods list, char *str);
int				print_string(t_mods list, char *str);
int				print_number(t_mods list, ptrdiff_t nbr);
int				print_char(t_mods *list, int c);
int				ft_printf(const char *format, ...);

#endif
