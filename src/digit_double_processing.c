/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_double_processing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:52:02 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/03 16:52:07 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*digit_double_processing(t_flags *fl, va_list *ap)
{
	char	*s;

	fl->precision = (fl->precision == -1) ? 6 : fl->precision;
	if (fl->ld_mod == 1)
		s = ft_ftoa_long(va_arg(*ap, long double), fl->precision);
	else
		s = ft_ftoa(va_arg(*ap, double), fl->precision);
	if (s != NULL)
		s = digit_redactor(s, fl);
	return (s);
}
