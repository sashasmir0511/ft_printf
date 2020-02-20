/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 17:11:38 by fjessi            #+#    #+#             */
/*   Updated: 2020/02/02 17:12:28 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>

typedef struct	s_flags
{
	unsigned char	minus;
	unsigned char	plus;
	unsigned char	zero;
	unsigned char	space;
	unsigned char	hash;
	int				width;
	int				precision;
	unsigned char	step;
	char			type;
	unsigned char	h_mod;
	unsigned char	l_mod;
	unsigned char	ld_mod;
	unsigned char	filler;
}				t_flags;

int				ft_printf(const char *format, ...);
int				analysis(const char *s, t_flags *fl);
char			*output_parameter(t_flags *fl, va_list *ap);
char			*digit_int_processing(t_flags *fl, va_list *ap);
char			*digit_double_processing(t_flags *fl, va_list *ap);
char			*digit_uint_processing(t_flags *fl, va_list *ap);
char			*transfer_o_x_b(t_flags *fl, va_list *ap);
char			*type_s_c(t_flags *fl, va_list *ap);
char			*data_iso(va_list *ap);
char			*digit_redactor(char *s, t_flags *fl);
char			*hashtag_redactor(int specifier, char *arg, int precision);
int				color(const char *str);
int				color_end(char *color);
char			*str_redactor(char *s, t_flags *fl);
int				putstr_for_null_char(char *s);

#endif
