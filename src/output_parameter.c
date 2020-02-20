/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_parameter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:48:58 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/03 15:45:05 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*output_parameter(t_flags *fl, va_list *ap)
{
	char *s;

	s = NULL;
	if (fl->type == 's' || fl->type == 'c' || fl->type == 'S')
		s = type_s_c(fl, ap);
	else if (fl->type == 'd' || fl->type == 'i')
		s = digit_int_processing(fl, ap);
	else if (fl->type == 'u')
		s = digit_uint_processing(fl, ap);
	else if (fl->type == 'o' || fl->type == 'b'\
			|| fl->type == 'x' || fl->type == 'X')
		s = transfer_o_x_b(fl, ap);
	else if (fl->type == 'f')
		s = digit_double_processing(fl, ap);
	else if (fl->type == '%')
		s = str_redactor(ft_strdup("%"), fl);
	else if (fl->type == 'p')
		s = digit_redactor(ft_itoa_base_unsigned(va_arg(*ap, size_t), 16), fl);
	else if (fl->type == 'k')
		s = data_iso(ap);
	else
		return (NULL);
	return (s);
}

char	*hashtag_redactor(int specifier, char *arg, int precision)
{
	if ((specifier == 'x' || specifier == 'X') && ft_iszero(arg))
		return (arg);
	if ((specifier == 'o' || specifier == 'b') && \
	(precision > (int)ft_strlen(arg) || arg[0] == '0'))
		return (arg);
	if (!ft_strcmp(arg, "0") && specifier != 'p')
		return (arg);
	if (!ft_strcmp(arg, "0") && specifier == 'p' && !precision)
		arg[0] = '\0';
	if (specifier == 'x' || specifier == 'p')
		return (ft_strjoin_free("0x", arg, 2));
	return (ft_strjoin_free("0", arg, 2));
}
