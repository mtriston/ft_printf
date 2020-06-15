/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 19:06:45 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/15 16:03:58 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

char	*apply_width(char *flags, int width, int precision, char type, char *str);
char	*apply_precision(int precision, char *str);
char	*apply_flag_plus(char *flags, char *str, int nbr, char type);
char	*apply_flag_sharp(char *flags, char *str, char type);
char	*apply_flag_space(char *flags, char *str, char type);
int		print_string(char *flags, int width, int precision, char *str);
int		print_number(char type, char *flags, int width, int precision, ptrdiff_t nbr);
int		print_char(char *flags, int width, int precision, int c);
int		ft_printf(const char *format, ...);

#endif
