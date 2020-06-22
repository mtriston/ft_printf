/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 19:06:45 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/18 20:53:27 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

char	*get_base(char type);
char	*check_flags(char *str, char *flags);
char	*check_width(char *str, int *width, va_list ap);
char	*check_precision(char *str, int *precision, va_list ap);
char	*check_length(char *str, char *length);
char	*apply_width(char *flags, int width, int precision, char type, char *str);
char	*apply_precision(int precision, char *str);
char	*apply_flag_plus(char *flags, char *str, int nbr, char type);
char	*apply_flag_sharp(char *flags, char *str, char type);
char	*apply_flag_space(char *flags, char *str, char type);
char	*print_string(char *flags, int width, int precision, char *str);
char	*print_number(char type, char *flags, int width, int precision, ptrdiff_t nbr);
char    *print_char(char *flags, int width, int precision, int c);
int		ft_printf(const char *, ...);

#endif
